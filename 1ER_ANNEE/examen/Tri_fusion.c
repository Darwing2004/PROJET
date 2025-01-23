#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void REMPLISSAGE_TAB(int N, int TAB[N])
{
  int i;
  for (i=0; i<N; i++) TAB[i] = rand()%100;
}

void AFFICHAGE_TAB(int N, int TAB[N])
{
  int i;
  for (i=0; i<N; i++)
  {
    printf("%d ", TAB[i]);
  }
  printf("\n");
}

void FUSION(int N, int TAB[N], int a, int c, int b)
{
  int i, j, k;
  int TEMP[b-a+1]; //Tableau temporaire
  i=a;
  j=c+1;
  k=0; 
  
  while ((i<=c) && (j<=b))
  { // On compare élément par élément les deux sous tableaux
    if (TAB[i] <= TAB[j])
    {
      TEMP[k] = TAB[i];
      i++;
    }
    else
    {
      TEMP[k] = TAB[j];
      j++;
    }
    k++;
  }
  
  
    while (i<=c)// Si le premier tas n'est pas encore fini, on recopie le reste 
    {
      TEMP[k] = TAB[i];
      k++;
      i++;
    }

  
   while (j<=b)// Si le deuxième tas n'est pas encore fini, on recopie le reste 
    {
      TEMP[k] = TAB[j];
      k++;
      j++;
    }
    
  k=0;
  for (i=a; i<=b; i++) //On copie le tableau temporaire dans le tableau original
  {
  TAB[i] = TEMP[k];
  k++;
  }
}



void TRI_FUSION(int N, int TAB[N], int a, int b)
{
  int c;
  if (a != b)
  {
    c = (a+b)/2;
    TRI_FUSION(N, TAB, a, c);
    TRI_FUSION(N, TAB, c+1, b);
    FUSION(N, TAB, a, c, b);
    //AFFICHAGE_TAB(TAB);
  }
}




int main()
{
  int N=10;
  int TAB[N];
  srand(time(NULL));
  REMPLISSAGE_TAB(N, TAB);
  printf("DEP : ");
  AFFICHAGE_TAB(N, TAB);
  printf("FIN : ");
  TRI_FUSION(N, TAB, 0, N-1);
  AFFICHAGE_TAB(N, TAB);
  return 0;
}