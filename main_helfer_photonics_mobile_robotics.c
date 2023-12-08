/* main_helfer_photonics_mobile_robotics.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Photonics und Mobile Robotics Studenten Jahrgang 2023
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
2.0_5.12.2023 Einfuegen while-Schleife
3.0_6.12.2023 Einfuegen Unterprogramme Rezepte und Hangman.
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
#include "rezepte.h"
#include "hangman.h"

// Mit main beginnt das Programm.
int main(void) 
{
	// Variablen definieren
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	int fach = 0;
	char weitereRechnung[3] = "ja";
	
	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereRechnung, ja) == 0 || strcmp (weitereRechnung, Ja) == 0)
	{
		// Hier wird ueberprueft, ob die Werte fuer die Faecher angezeigt werden sollen und anschliessend geprintet.
			printf("\nFuer Geometrische Optik waehle die 1.\n");
			printf("Fuer Mechanik waehle die 2.\n");
			printf("Fuer Elektronik Aufgaben waehle die 3.\n");
			printf("Fuer Elektronik Formeln waehle die 4.\n");
			printf("Fuer Vektorgeometrie Formeln waehle die 5.\n");
			printf("Fuer Rezepte waehle die 6.\n");
			printf("Fuer Hangman waehle die 7.\n");
		
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
			case 6:
				rezepte();
				break;
			case 7:
				hangman();
				break;
			default:
				printf("Der eingegebene Wert ist keinem Fach zugewiesen!\n\n");
				break;
		}
		
		// Abfrage ob eine weitere Rechnung durchgefuert werden soll.
		printf("Willst du eine weitere Rechnung durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnung);
		fflush(stdin);
		
		system("cls");
	}
	
	// Praeprozessoranweisung Linux oder Windows?
	#ifndef _linux_ // Haelt die Konsole offen.
	system ("pause");
	#endif
	
	//Rueckgabewert, dass das Programm erfolgreich beendet wurde.
	return 0;
}