#include <stdio.h>

/*unsigned int decompositionBinaire(int n)
{
    int nombre = 0;
    while (n > 0)
    {
        int reste = n % 2;
        nombre = nombre * 10 + reste;
        n/=2;
    }
    return nombre;
}*/

int decompositionBinaire(int n) {
    //Ajoutez votre code ici
    
    int result = 0;
    int position = 1;
    
    while(n > 0)
    {
        int digit = n % 2;
        result = result + digit * position;
        position *= 10;
        n/=2;
    }

    return result;

}

int main () 
{
    int n = 123;
    int nbr = decompositionBinaire(n);

    printf("123 en binaire : %d", nbr);
}