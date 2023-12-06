/* main.c
Beschreibung: Kreuz- und Skalarprodukt
Autor: Ramon Tarca, Ryoya Bauer
Firma: FHGR 
Version: 1.0 
Datum: 04.12.2023 
Änderungen: 
1.0 04.12.2023 Erste Version 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


void norm(void);
void cross(void);
void dot(void);

void vector()
{
	int menue = 0;
	
	printf("\n1 - Betrag eines Vektors in n\n2 - Kreuzprodukt in 3D\n3 - Skalarprodukt in n\n\nBitte wähle eine Operation:\n");
	scanf("%i", &menue);
	fflush(stdin);
	switch(menue)
	{
		case 1 : norm(); break;
		case 2 : cross(); break;
		case 3 : dot(); break;
	}
	return;
}

void norm(void)
{
	int n = 0;
	printf("\nBitte Dimension wählen:\n");
	scanf("%i",&n);
	fflush(stdin);
	float vector1[n];
	
	printf("\nBitte den Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	float result = 0;
	
	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector1[i];
	}
	
	result = sqrtf(result);
	
	printf("\nDer Betrag ist %f\n\n",result);
	return;
}

void cross(void)
{
	int n = 3;
	float vector1[n], vector2[n];
	
	printf("\nBitte den ersten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	printf("\nBitte den zweiten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector2[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
	
	float result[n];
	
	int count1 = 1;
	int count2 = 2;
	
	for(int i = 0; i < n; i++)
	{
		result[i] = vector1[count1] * vector2[count2] - vector1[count2] * vector2[count1];
		count1++;
		count2++;
		if (count1 > 2)
		{
			count1 = 0;
		}
		if (count2 > 2)
		{
			count2 = 0;
		}
	}
	
	printf("\nDer neue Vektor lautet:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%f\n",result[i]);
	}
	printf("\n");
	return;
}

void dot(void)
{
	int n = 0;
	printf("\nBitte Dimension wählen:\n");
	scanf("%i",&n);
	fflush(stdin);
	float vector1[n], vector2[n];
	
	printf("\nBitte den ersten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	printf("\nBitte den zweiten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector2[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
	
	float result = 0;
	
	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector2[i];
	}
	
	printf("\nDas Skalarprodukt ergibt %f\n\n",result);
	return;
}