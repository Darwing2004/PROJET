#include<stdio.h>
#include<stdlib.h>
#define L 5
void AFFICHAGE_TAB(int TAB[L]){
  int i;
  for (i=0; i<L; i++){
    printf("%d ", TAB[i]);
  }
  printf("\n")
}

int PARTITION_LOMUTO(int TAB[L], int g, int d){
  int i, j, x, TEMP;
  x = TAB[d];
  i=g-1;
  
  for (j=g; j<d; j++){
    if (TAB[j]<=x){
      i=i+1;
      TEMP = TAB[i];
      TAB[i]=TAB[j];
      TAB[j]=TEMP;
    }
  }
  
  TEMP = TAB[i+1];
  TAB[i+1]=TAB[d];
  TAB[d]=TEMP;
  return i+1;
}

int PARTITION_HOARE(int TAB[L], int g, int d){
  int i, j, x, TEMP;
  x=TAB[g];
  i=g-1;
  j=d+1;
  
  while (1){
    do{
      j=j-1;
    }
    while (TAB[j]>x);
    do{
      i=i+1;
    }
    while (TAB[i]<x);
    if (i<j){
      TEMP = TAB[i];
      TAB[i]=TAB[j];
      TAB[j] = TEMP;
    }
    else{
      return j;
    }
  }
}

void TRI_RAPIDE (int TAB[L], int g, int d){
  int m;
  if (g<d){
    m=PARTITION_LOMUTO(TAB, g, d);
    TRI_RAPIDE (TAB, g, m-1);
    TRI_RAPIDE (TAB, m+1, d);
  }
}

int main(int argc, char** argv){
  int TAB[L] = {20, 16, 84, 49, 17};
  AFFICHAGE_TAB(TAB);
  TRI_RAPIDE (TAB, 0, L-1);
  printf("Après tri : ");
  AFFICHAGE_TAB(TAB);
  return 0;
}