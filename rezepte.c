/* rezepte.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Luca Kreuzen
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "rezepte.h"

void rezept(void);

void rezepte()
{
	int rezepte = 0;
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	char regRez[3] = "ja";
	char weitereRechnungRez[3] = "ja";
	
	while(strcmp (weitereRechnungRez, ja) == 0 || strcmp (weitereRechnungRez, Ja) == 0)
	{
		// Abfrage ob die Werte fuer die jeweiligen Faecher angezeigt werden sollen.
		printf("\nWenn du die Zahlen fuer die Rezepte sehen willst, dann schreibe Ja oder ja:\n");
		scanf("%s" ,&regRez);
		fflush(stdin);
		
		// Hier wird ueberprueft, ob die Werte fuer die Faecher angezeigt werden sollen und anschliessend geprintet.
		if(strcmp (regRez, ja) == 0 || strcmp (regRez, Ja) == 0)
		{
			printf("\nFuer das erste Rezept waehle die 1.\n");
		}
		
		// Abfrage des gewuenschten Fachs.
		printf("\nWelches Rezept willst du bearbeiten:\n");
		scanf("%i" ,&rezepte);
		fflush(stdin);
		
		// Aufrufen des gewuenschten Fachs.
		switch(rezepte)
		{
			case 1:
				rezept();
				break;	
			default:
				printf("Der eingegebene Wert ist keinem Rezept zugewiesen!\n\n");
				break;
		}
		
		printf("Wenn du ein weiteres Rezept sehen willst, dann schreibe ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnungRez);
		fflush(stdin);
		
		system("cls");
	}
	return;
}

void rezept(void)
{
	printf("Hier ist das Rezept:\n\n");
	
	return;
}