/* totalreflektion.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Julian Walter, York Willmann
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_6.12.2023 Erste Version 
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "totalreflektion.h"
#define Pi (3.141592654)

void totalreflektion(void) //<=totalreflektion
{				
	//Variablen
	double  n1 = 0;			//Brechzahl 1. Medium
	double  n2 = 0;			//Brechzahl 2. Medium
	double  ergebnis = 0;  	//Winkel Theta
	double  val = 0;  		//Zwischenspeicher
	
	//Abfrage
	printf("\nBitte gib eine Brechzahl n1 an: \n");
    scanf("%lf", &n1);
	fflush(stdin);
	
	printf("\nBitte gib eine Brechzahl n2 an: \n");
    scanf("%lf", &n2);
	fflush(stdin);

	//Berechnung
	if (n1 > n2)
	{
		val = n2/n1;
		
		ergebnis = (asin(val))*180/Pi;
		
		//Ausgabe
		printf("\nDer Winkel der Totalreflexion beträgt: %lf\n\n", ergebnis);
	}
	
	else 
	{
		printf("\nDie erste Brechungszahl muss groesser als die zweite Brechungszahl sein!\n\n");
	}	

	return;
}