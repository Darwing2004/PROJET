#include <pigpiod_if2.h>
#include <unistd.h>

int pi = pigpio_start(NULL, NULL);

if (pi < 0)
{
    printf("Can't connect to pigpiod\n");
    exit(-1);
}

set_mode(pi, 16, PI_OUTPUT);

while (1)
{
    gpio_write(pi, 16, PI_HIGH); // Envoi un signal "HAUT" sur le GPIO 16 pour l'allumer
    sleep(1);
    gpio_write(pi, 16, PI_LOW); // Envoi un signal "BAS" sur le GPIO16 pour l'éteindre
    sleep(1);
}