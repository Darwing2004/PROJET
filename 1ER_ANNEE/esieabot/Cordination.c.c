#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpiod_if2.h>

void Led(int pi)
{
    set_mode(pi, 16, PI_OUTPUT);
    for (int i = 0; i < 3; i++)
    {
        gpio_write(pi, 16, PI_HIGH);
        sleep(1);
        gpio_write(pi, 16, PI_LOW);
        sleep(1);
    }
    gpio_write(pi, 20, PI_HIGH);
}

void FinLed(int pi)
{
    gpio_write(pi, 20, PI_LOW);
    sleep(0);
    for (int i = 0; i < 2; i++)
    {
        gpio_write(pi, 16, PI_HIGH);
        sleep(1);
        gpio_write(pi, 16, PI_LOW);
        sleep(1);
    }
    gpio_write(pi, 16, PI_LOW);
    sleep(1);
    gpio_write(pi, 20, PI_LOW);
    sleep(1);
}

void Mouv_avant(int pi)
{
    set_PWM_dutycycle(pi, 23, 90); // Avant Gauche
    set_PWM_dutycycle(pi, 22, 80);
    sleep(1.75);
    set_PWM_dutycycle(pi, 23, 0);
    set_PWM_dutycycle(pi, 22, 0);
    sleep(1);
}

void Tourne(int pi)
{
    set_PWM_dutycycle(pi, 23, 97.5); // Avant Gauche
    set_PWM_dutycycle(pi, 22, 0);
    sleep(1);
    set_PWM_dutycycle(pi, 23, 0);
    set_PWM_dutycycle(pi, 22, 0);
    sleep(1);
}

void Servomo(int pi)
{
    set_mode(pi, 16, PI_INPUT);
    set_pull_up_down(pi, 16, PI_PUD_DOWN);
    set_mode(pi, 18, PI_OUTPUT);
    set_servo_pulsewidth(pi, 18, 1500);
    sleep(1);
    set_servo_pulsewidth(pi, 18, 2500);
    sleep(1);
    set_servo_pulsewidth(pi, 18, 0);
    sleep(1);
}

int main()
{
    int pi = pigpio_start(NULL, NULL);

    Led(pi);
    Servomo(pi);
    Mouv_avant(pi);
    Tourne(pi);
    Mouv_avant(pi);
    Servomo(pi);
    FinLed(pi);
}
