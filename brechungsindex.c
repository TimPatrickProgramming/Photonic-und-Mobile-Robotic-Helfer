/* brechungsindex.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Julian Walter, York Willmann
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
*/

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
	fflush(stdin);
	
    nM = Lichtgeschwindigkeit / cM; 
		
	printf("\nDas Ergebnis der Berechnung ist: %f\n\n", nM); 
		
    return;
}
