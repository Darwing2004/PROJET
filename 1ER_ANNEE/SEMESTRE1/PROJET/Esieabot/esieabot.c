#include <stdio.h>
#include <stdlib.h>
#include <pigpiod_if2.h>


/***********************************************************************

    Code d'example de la bibliothèque pigpiod
    https://abyz.me.uk/rpi/pigpio/code/SRTED.zip

    Ne pas modifier jusqu' à la fin de ce bloc

************************************************************************/
struct SRTED_s;

typedef struct SRTED_s SRTED_t;

#define SRTE_GOOD      0
#define SRTE_BAD_RANGE 1
#define SRTE_TIMEOUT   2

typedef struct
{
   int pi;
   int trig;
   int echo;
   int status; /* Good, bad range, or timeout */
   int round_trip_micros; /* micros taken to travel to the object and back */
   float range_cms; /* range in centimetres to the object */
   double timestamp; /* time of last reading (good or not) */
   double tov; /* time of validity of last good range */
} SRTED_data_t;

typedef void (*SRTED_CB_t)(SRTED_data_t);

struct SRTED_s
{
   int pi;
   int trig;
   int echo;
   float seconds;
   float min_cms, max_cms;
   SRTED_CB_t cb;

   int _cb_id_trig;
   int _cb_id_echo;

   pthread_t* _pth;

   int _in_code;

   int _ready;
   int _new_reading;
   SRTED_data_t _data;
   int _got_echo;
   int _got_trig;
   uint32_t _echo_tick;
   uint32_t _trig_tick;
};

SRTED_t* SRTED(int pi,
   int trig,
   int echo,
   SRTED_CB_t cb_func);

void         SRTED_config(SRTED_t* self, float min_cms, float max_cms);

void         SRTED_cancel(SRTED_t* self);

int          SRTED_ready(SRTED_t* self);

SRTED_data_t SRTED_data(SRTED_t* self);

void         SRTED_manual_read(SRTED_t* self);

static void _cb(
   int pi, unsigned gpio, unsigned level, uint32_t tick, void* user)
{
   SRTED_t* self = user;
   int round_trip_micros;
   float range_cms;
   int tick_diff;

   if (gpio == self->trig)
   {
      self->_got_trig = 1;
      self->_trig_tick = tick;
      self->_got_echo = 0;
   }
   else if (level == 1)
   {
      if (self->_got_trig)
      {
         /*
         Some devices send a rising edge shortly after the trigger.
         Those rising edges must be ignored.
         */

         tick_diff = tick - self->_trig_tick;

         if (tick_diff > 100)
         {
            self->_got_echo = 1;
            self->_echo_tick = tick;
         }
      }
   }
   else if (level == 0)
   {
      if (self->_got_echo)
      {
         self->_got_echo = 0;
         self->_got_trig = 0;

         round_trip_micros = tick - self->_echo_tick;
         range_cms = round_trip_micros * 0.017015;

         if ((self->min_cms <= range_cms) && (range_cms <= self->max_cms))
         {
            self->_data.tov = self->_data.timestamp;
            self->_data.range_cms = range_cms;
            self->_data.round_trip_micros = round_trip_micros;
            self->_data.status = SRTE_GOOD;
         }
         else
         {
            self->_data.status = SRTE_BAD_RANGE;
         }

         self->_ready = 1;
         self->_new_reading = 1;

         if (self->cb) (self->cb)(self->_data);
      }
   }
}

static void _trigger(SRTED_t* self)
{
   gpio_trigger(self->pi, self->trig, 11, 1);
}

/* PUBLIC ----------------------------------------------------------------- */

SRTED_t* SRTED(int pi, int trig, int echo, SRTED_CB_t cb_func)
{
   SRTED_t* self;

   self = malloc(sizeof(SRTED_t));

   if (!self) return NULL;

   self->pi = pi;
   self->trig = trig;
   self->echo = echo;
   self->cb = cb_func;

   self->_data.pi = pi;
   self->_data.trig = trig;
   self->_data.echo = echo;

   self->_data.status = 0;
   self->_data.round_trip_micros = 0;
   self->_data.range_cms = 0.0;
   self->_data.timestamp = 0.0;
   self->_data.tov = 0.0;

   self->seconds = 0.0;

   self->min_cms = 0.5;
   self->max_cms = 400.0;

   self->_pth = NULL;

   self->_got_trig = 0;
   self->_got_echo = 0;

   self->_ready = 0;
   self->_new_reading = 0;

   set_mode(pi, trig, PI_OUTPUT);
   set_mode(pi, echo, PI_INPUT);

   self->_cb_id_trig = callback_ex(pi, trig, FALLING_EDGE, _cb, self);
   self->_cb_id_echo = callback_ex(pi, echo, EITHER_EDGE, _cb, self);

   return self;
}

void SRTED_cancel(SRTED_t* self)
{
   if (self)
   {
      if (self->_pth)
      {
         stop_thread(self->_pth);
         self->_pth = NULL;
      }

      if (self->_cb_id_trig >= 0)
      {
         callback_cancel(self->_cb_id_trig);
         self->_cb_id_trig = -1;
      }

      if (self->_cb_id_echo >= 0)
      {
         callback_cancel(self->_cb_id_echo);
         self->_cb_id_echo = -1;
      }

      free(self);
   }
}
int SRTED_ready(SRTED_t* self)
{
   /*
   Returns True if a new reading is ready.
   */
   return self->_ready;
}

SRTED_data_t SRTED_data(SRTED_t* self)
{
   /*
   Returns the last reading.
   */
   self->_ready = 0;
   return self->_data;
}

void SRTED_manual_read(SRTED_t* self)
{
   int i;

   self->_new_reading = 0;

   _trigger(self);

   self->_data.timestamp = time_time();

   /* timeout if no new reading */

   for (i = 0; i < 25; i++) /* 0.25 seconds */
   {
      time_sleep(0.01);
      if (self->_new_reading) break;
   }

   if (!self->_new_reading)
   {
      self->_data.status = SRTE_TIMEOUT;
      self->_ready = 1;
      if (self->cb) (self->cb)(self->_data);
   }
}

void SRTED_config(SRTED_t* self, float min_cms, float max_cms)
{
   if ((min_cms >= 0.5) && (min_cms < max_cms) && (max_cms < 1000.0))
   {
      self->min_cms = min_cms;
      self->max_cms = max_cms;
   }
}




/***********************************************************************

    Fin du code d'exemple

************************************************************************/




// Variable globale distance
float distance = 0;

// La variable distance est mise à jour automatiquement après chaque lecture
// Ne pas modifier
void cbf(SRTED_data_t r)
{
   distance = r.range_cms;
}

// Fonction main d'exemple
int main(int argc, char* argv[])
{
   int trig_G = 8; // GPIO à modifier
   int echo_G = 7; // GPIO à modifier
   int trig_D = 16; // GPIO à modifier
   int echo_D = 20; // GPIO à modifier 

   int pi;
   SRTED_t* sr;

   pi = pigpio_start(NULL, NULL);

   if (pi >= 0)
   {
      // Déclaration du capteur
      sr = SRTED(pi, trig_G, echo_G, cbf);
      // Déclenchement de la lecture  
      SRTED_manual_read(sr);
      // Fin de la lecture
      SRTED_cancel(sr);

      // Affichage de la distance
      printf("Distance = %.1f cm\n", distance);

      set_PWM_dutycycle(pi, 16, 128);
      
      if (distance < 4)
      {
         set_PWM_dutycycle(pi, 16, 128);
      }

      pigpio_stop(pi);
   }
   return 0;
}