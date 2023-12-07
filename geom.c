/* geom.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Julian Walter, York Willmann
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
2.0_6.12.2023 Einfuegen der while-Schleife
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geom.h"
#include "brechungsgesetz.h"
#include "brechungsindex.h"
#include "totalreflektion.h"

void geom(void)
{
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	int formel = 0;
	char reg[3] = "no";
	char weitereRechnungGeom[3] = "ja";
	
	while(strcmp (weitereRechnungGeom, ja) == 0 || strcmp (weitereRechnungGeom, Ja) == 0)
	{
		printf("\nFuer den Brechungsindex waehle die 1.\n");
		printf("Fuer das Brechungsgesetz waehle die 2.\n");
		printf("Fuer die Totalreflektion waehle die 3.\n");
			
		// Abfrage des gewuenschten Fachs.
		printf("\nWelche Formel willst du benutzen:\n");
		scanf("%i" ,&formel);
		fflush(stdin);

		switch(formel)
		{
			case 1:
				brechungsindex();
				break;
			case 2:
				brechungsgesetz();
				break;
			case 3:
				totalreflektion();
				break;			
			default:
				printf("Dieser Zahl ist keine Formel zugewiesen!\n\n");
				return;
		}
		
		printf("Willst du eine weitere Rechnung in der geometrischen Optik durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnungGeom);
		fflush(stdin);
		
		formel = 0;
		
		system("cls");
	}
	return;
}