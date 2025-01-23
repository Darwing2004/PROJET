#include <stdio.h>

int count_7(int nombre) {
    int count = 0;

    while (nombre != 0) {
        if (nombre % 10 == 7) {
            count++;
        }
        nombre /= 10;
    }

    return count;
}

int main() {
    int nombre;
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    int resultat = count_7(nombre);
}