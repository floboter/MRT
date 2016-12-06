/* Datei: v3_dialog.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include "tComplex.h"
#include "tParam.h"


/*--- Definitionen ---------------------------------------------------------*/

typedef enum {FALSE, TRUE} bool;


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};


/*--- Parameter Dialog ------------------------------------------------------*/
/* Diese Funktion listet alle Parameter auf.
 * Danach ermöglicht sie nach Eingabe einer Zahl entsprechend der Zeilennummer,
 * den in dieser Zeile stehenden Parameter zu ändern. */


bool ParamDialog(tParam *param, tComplex *z)
{
	int c = 0; // Ueberpruefungsvariable fuer Schleife
	int cnt = 1; // Counter, fuer die Zeilennummer
	int eingabe = 0; // eingabevariable
	double dtemp; // temporaere double Zahl
	unsigned int uitemp; // temporaere unsigned int Zahl


	while(c == 0)
	{
		cnt = 1;
		printf("Es folgen alle Parameter, die definiert wurden.\n"
				"Geben Sie die Zeilennummer (Zahl in der Klammer) ein,\n"
				"um den entsprechenden Parameter zu aendern.\n");

		printf("(%d): Realteil der komplexen Zahl c: %f\n", cnt, z->realteil); cnt++;
		printf("(%d): Imaginaerteil der komplexen Zahl c: %f\n", cnt, z->imagteil); cnt++;
		printf("(%d): Radius des Gebietes G: %f\n", cnt, getRadius(param)); cnt++;
		printf("(%d): Maximale Iterationszahl imax: %d\n", cnt, getimax(param)); cnt++;
		printf("(%d): Fraktialvariante (0 = apfel, 1 = julia): %d\n", cnt, getfraktalvariante(param)); cnt++;
		printf("(%d): xmin: %f\n", cnt, getxmin(param)); cnt++;
		printf("(%d): xmax: %f\n", cnt, getxmax(param)); cnt++;
		printf("(%d): ymin: %f\n", cnt, getymin(param)); cnt++;
		printf("(%d): ymax: %f\n", cnt, getymax(param)); cnt++;
		printf("(%d): Anzahl für Linien im Analysegebiet xpoints: %d\n", cnt, getxpoints(param)); cnt++;
		printf("(%d): Anzahl für Linien im Analysegebiet ypoints: %d\n", cnt, getypoints(param)); cnt++;

		printf("Welchen Parameter wollen Sie aendern?\n"
				"Geben Sie die Zeilennummer ein.\n"
				"Möchten Sie nichts ändern, geben Sie '0' ein\n"
				"Falls Sie das Programm abbrechen möchten, geben Sie '100' ein\n");

		scanf("%d", &eingabe);

		switch(eingabe)
		{
		case 1:
			printf("Wert für den Realteil: ");
			scanf("%lf", &dtemp);
			z->realteil = (tRealteil)dtemp;
			break;
		case 2:
			printf("Wert für den Imaginaerteil: ");
			scanf("%lf", &dtemp);
			z->imagteil = (tImagteil)dtemp;
			break;
		case 3:
			printf("Wert für den Radius R: ");
			scanf("%lf", &dtemp);
			setRadius((tRadius)dtemp, param);
			break;
		case 4:
			printf("Wert für maximale Anzahl der Iterationen: ");
			scanf("%d", &uitemp);
			setimax(uitemp, param);
			break;
		case 5:
			printf("Wert für Fraktalvariante (0 = apfel, 1 = julia): ");
			scanf("%d", &uitemp);
			if(uitemp == 0 || uitemp == 1)
			{
				setfraktalvariante(uitemp, param);
			}
			else printf("Eingabe falsch! (0 = apfel, 1 = julia)\n");
			break;
		case 6:
			printf("Wert für xmin: ");
			scanf("%lf", &dtemp);
			setxmin(dtemp, param);
			break;
		case 7:
			printf("Wert für xmax: ");
			scanf("%lf", &dtemp);
			setxmax(dtemp, param);
			break;
		case 8:
			printf("Wert für ymin: ");
			scanf("%lf", &dtemp);
			setymin(dtemp, param);
			break;
		case 9:
			printf("Wert für ymax: ");
			scanf("%lf", &dtemp);
			setymax(dtemp, param);
			break;
		case 10:
			printf("Wert für xmin: ");
			scanf("%lf", &dtemp);
			setxmin(dtemp, param);
			break;
		case 11:
			printf("Wert für xpoints: ");
			scanf("%d", &uitemp);
			setxpoints(dtemp, param);
			break;
		case 12:
			printf("Wert für ypoints: ");
			scanf("%lf", &dtemp);
			setypoints(dtemp, param);
			break;
		case 0:
			printf("Programm OK\n");
			c = 1;
			break;
		case 100:
			c = 1;
			printf("Programmabbruch\n");
			break;


		default: printf("Fehler: Zeile nicht vorhanden.\n");

		}



	}
	if(eingabe == 0)
	{
		return TRUE;
	}

	else if(eingabe == 100)
	{
		return FALSE;
	}


}



/* v3_diag.c */
