#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpiod_if2.h>

void Led(int pi)
{
    set_mode(pi, 16, PI_OUTPUT);

    for (int i = 0; i < 5; i++)
    {
        gpio_write(pi, 16, PI_HIGH); // Send a HIGH signal to GPIO 16
        sleep(1);                    // Wait for 1 second
        gpio_write(pi, 16, PI_LOW);  // Send a LOW signal to GPIO 16
        sleep(1);                    // Wait for 1 second
    }
}
int main()
{
    int pi = pigpio_start(NULL, NULL);
    if (pi < 0)
    {
        printf("Can't connect to pigpiod\n");
        exit(-1);
    }

    Led(pi);

    set_mode(pi, 20, PI_INPUT);            // Met le GPIO 20 en mode entrée
    set_pull_up_down(pi, 16, PI_PUD_DOWN); // Active la résistance de rappel sur le GPIO 16

    while (1)
    {
        int state = gpio_read(pi, 20); // Lecture de l'état du bouton poussoir
        if (state == PI_HIGH)
        { 
            printf("Le bouton poussoir sur le GPIO 16 est enclenché\n"); // Si le GPIO a reçu un "HAUT"
        }
        else if (state == PI_LOW)
        { 
            printf("Le bouton poussoir sur le GPIO 16 est relaché\n"); // Si le GPIO a reçu un "BAS"
        }
        else
        { 
            printf("Le GPIO 16 est dans un état inconnu\n"); // Ne devrait pas exister
        }
        sleep(1);
    }
    return 0;
}