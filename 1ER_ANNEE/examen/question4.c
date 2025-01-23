#include<math.h>
#include<stdio.h>
#include<stdlib.h>

double Racine_Carree(double n, double e){
	double a = 0.0;
	double b = n;
	double m = (a + b) / 2;

	while (m * m - n > e){
		if(m * m < n){
			a = m;
		}else{
			b = m;
		}
		
		m = (a + b) / 2.0;
	}
	return m;
}

int main(){
	double n, e;
	printf("saisir n:\n");
	scanf("%lf", &n);
	printf("saisir e:\n");
	scanf("%lf", &e);
	double result = Racine_Carree(n, e);
	printf("%lf", &result);
}
