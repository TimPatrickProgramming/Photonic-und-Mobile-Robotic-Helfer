#include <stdio.h>
#include <stdlib.h>
#include "brechungsindex.h"
#define Lichtgeschwindigkeit (299792458)

void brechungsindex()
{
	float cM = 0;
	float nM = 0;
	
	printf("\nBitte gib die Lichtgeschwindigkeit im Materials an: \n");
    scanf("%f", &cM);
	
    nM = Lichtgeschwindigkeit / cM; 
		
	printf("\nDas Ergebnis der Berechnung ist: %f\n\n", nM); 
		
    return;
}

