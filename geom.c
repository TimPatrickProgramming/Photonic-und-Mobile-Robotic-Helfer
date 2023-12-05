#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geom.h"
#include "brechungsgesetz.h"
#include "brechungsindex.h"
#include "formel3.h"

void geom(void)
{
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	int formel = 0;
	char reg[3] = "no";
	
	printf("\nWenn du die Zahlen fuer die Formeln sehen willst, dann schreibe Ja oder ja:\n");
	scanf("%s" ,&reg);
	fflush(stdin);
		
	// Hier wird ueberprueft, ob die Werte fuer die Faecher angezeigt werden sollen und anschliessend geprintet.
	if(strcmp (reg, ja) == 0 || strcmp (reg, Ja) == 0)
	{
		printf("\nFuer den Brechungsindex waehle die 1.\n");
		printf("Fuer das Brechungsgesetz waehle die 2.\n");
		printf("Fuer die dritte Formel waehle die 3.\n");
	}
		
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
            formel3();
			break;			
        default:
			printf("Dieser Zahl ist keine Formel zugewiesen!\n\n");
			return;
    }
}