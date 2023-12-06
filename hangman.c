/* hangman.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: _________, __________, ___________
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
#include "hangman.h"

void hangman(void)
{
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	char weitereRechnungHang[3] = "ja";
	
	while(strcmp (weitereRechnungHang, ja) == 0 || strcmp (weitereRechnungHang, Ja) == 0)
	{
		printf("Willst du eine weitere Partie spielen? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnungHang);
		fflush(stdin);
		
		system("cls");
	}
	return;
}