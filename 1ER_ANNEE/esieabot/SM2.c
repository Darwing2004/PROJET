#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpiod_if2.h>

void controlServo(int pi, int pin)
{
    set_servo_pulsewidth(pi, 13, 1500); // Produit une tension moyenne de 0V (comme si on émettait un signal BAS)
    sleep(1);
    set_servo_pulsewidth(pi, 13, 2500); // Produit une tension moyenne de 1.65V (la moitié de 3.3V)
    sleep(1);
    set_servo_pulsewidth(pi, 16, 0); // Désarme le servo moteur
}

int main ()
{
   int pi = pigpio_start(NULL, NULL);
    if (pi < 0)
    {
        printf("Can't connect to pigpiod\n");
        exit(-1);
    }

    set_mode(pi, 16, PI_OUTPUT);            // Met le GPIO 16 en mode entrée
    controlServo(pi, 13);

    return 0;
}

