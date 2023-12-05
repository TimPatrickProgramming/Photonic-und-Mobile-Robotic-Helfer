#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "brechungsgesetz.h"
#define Pi (3.141592654)

void brechungsgesetz()
{     
	double T2 = 0;
	double n1 = 0;
	double n2 = 0;
	double t2 = 0;
	double val = 0;
	double ergebnis = 0;
	
	printf("\nBitte gib einen Winkel Theta 2 an: \n");
    scanf("%lf", &T2);
	printf("\nBitte gib die Brechzahl des aeusseren Materials an: \n");
    scanf("%lf", &n1);
    printf("\nBitte gib die Brechzahl des inneren Materials an: \n");
    scanf("%lf", &n2);
	
	if(n1 > n2)
	{
	t2 = T2*Pi/180;
	
	val = (n2*sin(t2))/n1;
	
	ergebnis = (asin(val))*180/Pi;
		
	printf("\nDer Winkel Theta 1 betraegt %lf \n\n", ergebnis);
	}
	
	else
	{
		printf("\nDie erste Brechungszahl muss groesser als die zweite Brechungszahl sein!\n\n");
	}	
    return;
}
   