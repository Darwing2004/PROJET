#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpiod_if2.h>

void controlLed(int pi)
{
    set_mode(pi, 16, PI_OUTPUT); // Met le GPIO 16 en mode sortie

    for (int i = 0; i < 5; i++)
    {
        gpio_write(pi, 16, PI_HIGH); // Send a HIGH signal to GPIO 16
        sleep(1);                    // Wait for 1 second
        gpio_write(pi, 16, PI_LOW);  // Send a LOW signal to GPIO 16
        sleep(1);                    // Wait for 1 second
    }
}

void controlServo(int pi, int pin)
{
    set_mode(pi, 13, PI_OUTPUT);  // Met le GPIO 16 en mode sortie
    set_PWM_dutycycle(pi, 13, 0); // Produit une tension moyenne de 0V (comme si on émettait un signal BAS)
    sleep(1);
    set_PWM_dutycycle(pi, 13, 128); // Produit une tension moyenne de 1.65V (la moitié de 3.3V)
    sleep(1);
    set_PWM_dutycycle(pi, 13, 255); // Produit une tension moyenne de 3.3V (comme si on émettait un signal HAUT)
}

int main()
{
    int pi = pigpio_start(NULL, NULL);
    if (pi < 0)
    {
        printf("Can't connect to pigpiod\n");
        exit(-1);
    }

    set_mode(pi, 16, PI_INPUT);            // Met le GPIO 16 en mode entrée
    set_pull_up_down(pi, 16, PI_PUD_DOWN); // Active la résistance de rappel sur le GPIO 20

    controlLed(pi);

    while (1)
    {
        int state = gpio_read(pi, 20); // Lecture de l'état du bouton poussoir
        if (state == PI_HIGH)
        {
            printf("Le bouton est appuye\n");
            controlServo(pi, 13);
            sleep(1);
            int PIN_BACKWARD_LEFT = pigpio_start(NULL, NULL);
            int PIN_BACKWARD_RIGHT = pigpio_start(NULL, NULL);
            set_mode(PIN_BACKWARD_LEFT, 23, PI_OUTPUT);
            set_mode(PIN_BACKWARD_RIGHT, 22, PI_OUTPUT);
            set_mode(PIN_BACKWARD_LEFT, 25, PI_OUTPUT);
            set_mode(PIN_BACKWARD_RIGHT, 17, PI_OUTPUT);
            set_PWM_dutycycle(pi, 23, 80);
            set_PWM_dutycycle(pi, 22, 80);
            sleep(1);
            set_PWM_dutycycle(pi, 23, 0);
            set_PWM_dutycycle(pi, 22, 0);
            sleep(1);
            set_PWM_dutycycle(pi, 25, 80);
            set_PWM_dutycycle(pi, 17, 80);
            sleep(1);
            set_PWM_dutycycle(pi, 25, 0);
            set_PWM_dutycycle(pi, 17, 0);
        }
        printf("Le bouton est relache\n");
        sleep(1);
    }
    return 0;
}
