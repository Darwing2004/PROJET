#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} POINT;

typedef struct
{
    POINT pt1;
    POINT pt2;
    POINT pt3;
} TRIANGLE;

typedef struct
{
    float rayon;
    POINT centre;
} CERCLE;

typedef struct
{
    POINT c1;
    POINT c2;
} RECTANGLE;

float distance(POINT pta, POINT ptb)
{
    float diff_x = pow(ptb.x - pta.x, 2);
    float diff_y = pow(ptb.y - pta.y, 2);

    float distance = sqrt(diff_x + diff_y);

    return distance;
}

float A_T(TRIANGLE Samuel)
{
    float a = distance(Samuel.pt1, Samuel.pt2);
    float b = distance(Samuel.pt2, Samuel.pt3);
    float c = distance(Samuel.pt3, Samuel.pt1);

    float s = (a + b + c) / 2;

    float air_triangle = sqrt(s * (s - a) * (s - b) * (s - c));

    return air_triangle;
}

bool check_triangle(TRIANGLE Samuel)
{
    float air = A_T(Samuel);
    if (air == 0)
    {
        return false;
    }

    return true;
}

bool check_cercle(CERCLE Darwing)
{
    if (Darwing.rayon > 0)
    {
        return true;
    }
    return false;
}

bool check_rectangle(RECTANGLE Alexis)
{
    if (Alexis.c1.x == Alexis.c2.x && Alexis.c1.y == Alexis.c2.y)
    {
        return false;
    }
    return true;
}

float Air_Cercle(CERCLE Darwing)
{
    float air_c = M_PI * (Darwing.rayon * Darwing.rayon);
    return air_c;
}

float Air_Rectangle(RECTANGLE Alexis)
{
    float Longueur = abs(Alexis.c1.x - Alexis.c2.x);
    float Largeur = abs(Alexis.c1.y - Alexis.c2.y);

    float air_r = Longueur * Largeur;

    return air_r;
}

bool check_point(CERCLE Darwing, POINT pt)
{
    float distance_centre_pt = distance(Darwing.centre, pt);

    if (distance_centre_pt <= Darwing.rayon || distance_centre_pt == 0)
    {
        return true;
    }

    return false;
}

bool check_c_rectangles(RECTANGLE Alexis, RECTANGLE Vincent)
{
    if (Alexis.c2.x < Vincent.c1.x || Alexis.c1.x > Vincent.c2.x)
    {
        return false;
    }

    if (Alexis.c2.y < Vincent.c1.y || Alexis.c1.y > Vincent.c2.y)
    {
        return false;
    }

    return true;
}

typedef union
{
    TRIANGLE Samuel;
    CERCLE Darwing;
    RECTANGLE Alexis;

} geometricalForm;

int main()
{   
    RECTANGLE Alexis = {{2.0, 2.0}, {5.0, 4.0}};
    RECTANGLE Vincent = {{7.0, 2.0}, {10.0, 4.0}};

    printf("Les rectangles se chevauchent : %d\n", check_c_rectangles(Alexis, Vincent));
}