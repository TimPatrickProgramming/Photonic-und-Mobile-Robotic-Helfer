/* main_helfer_photonics_mobile_robotics.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Photonics und MObile Robotics Studenten Jahrgang 2023
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Einbinden von weiteren C files.
#include "geom.h"
#include "mechanik.h"
#include "elektronikAufgaben.h"
#include "elektronikFormeln.h"
#include "vector.h"

// Mit main beginnt das Programm.
int main(void) 
{
	// Variablen definieren
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	int fach = 0;
	char reg[3] = "_";
	char weitereRechnung[3] = "ja";
	
	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereRechnung, ja) == 0 || strcmp (weitereRechnung, Ja) == 0)
	{
		// Abfrage ob die Werte fuer die jeweiligen Faecher angezeigt werden sollen.
		printf("\nWenn du die Zahlen fuer die Faecher sehen willst, dann schreibe Ja oder ja:\n");
		scanf("%s" ,&reg);
		fflush(stdin);
		
		// Hier wird ueberprueft, ob die Werte fuer die Faecher angezeigt werden sollen und anschliessend geprintet.
		if(strcmp (reg, ja) == 0 || strcmp (reg, Ja) == 0)
		{
			printf("\nFuer Geometrische Optik waehle die 1.\n");
			printf("Fuer Mechanik waehle die 2.\n");
			printf("Fuer Elektronik Aufgaben waehle die 3.\n");
			printf("Fuer Elektronik Formeln waehle die 4.\n");
			printf("Fuer Vektorgeometrie Formeln waehle die 5.\n");
		}
		
		// Abfrage des gewuenschten Fachs.
		printf("\nWelches Fach willst du bearbeiten:\n");
		scanf("%i" ,&fach);
		fflush(stdin);
		
		// Aufrufen des gewuenschten Fachs.
		switch(fach)
		{
			case 1:
				geom();
				break;	
			case 2:		
				mechanik();
				break;
			case 3:
				elektronikAufgaben();
				break;
			case 4:
				elektronikFormeln();
				break;
			case 5:
				vector();
				break;
			default:
				printf("Der eingegebene Wert ist keinem Fach zugewiesen!\n\n");
				break;
		}
		
		// Abfrage ob eine weitere Rechnung durchgefuert werden soll.
		printf("Willst du eine weitere Rechnung durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnung);
	}
	
	// Praeprozessoranweisung Linux oder Windows?
	#ifndef _linux_ // Haelt die Konsole offen.
	system ("pause");
	#endif
	
	//Rueckgabewert, dass das Programm erfolgreich beendet wurde.
	return 0;
}