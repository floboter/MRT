/* Datei: v3_dialog.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "tComplex.h"
#include "tParam.h"
#include "dialog.h"


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
 * Danach ermoeglicht sie nach Eingabe einer Zahl entsprechend der Zeilennummer,
 * den in dieser Zeile stehenden Parameter zu aendern. */


bool ParamDialog(tParam *ptr_param, tComplex *z)
{
	int c = 0; // Ueberpruefungsvariable fuer Schleife
	int cnt = 1; // Counter, fuer die Zeilennummer
	int eingabe = 0; // eingabevariable
	double dtemp; // temporaere double Zahl
	unsigned int uitemp; // temporaere unsigned int Zahl
	int fehlercnt = 0;

	while(c == 0)
	{
		cnt = 1;

		if(fehlercnt > 0)
		{
			printf("Fehler: Zeile nicht vorhanden!\n\n");
		}

		printf("Es folgen alle Parameter, die definiert wurden.\n"
				"Geben Sie die Zeilennummer (Zahl in der Klammer) ein,\n"
				"um den entsprechenden Parameter zu aendern.\n\n");

		printf("(%d): Realteil der komplexen Zahl c: %f\n", cnt, z->realteil); cnt++;
		printf("(%d): Imaginaerteil der komplexen Zahl c: %f\n", cnt, z->imagteil); cnt++;
		printf("(%d): Radius des Gebietes G: %f\n", cnt, getRadius(ptr_param)); cnt++;
		printf("(%d): Maximale Iterationszahl imax: %d\n", cnt, getimax(ptr_param)); cnt++;
		printf("(%d): Fraktialvariante (0 = apfel, 1 = julia): %d\n", cnt, getfraktalvariante(ptr_param)); cnt++;
		printf("(%d): xmin: %f\n", cnt, getxmin(ptr_param)); cnt++;
		printf("(%d): xmax: %f\n", cnt, getxmax(ptr_param)); cnt++;
		printf("(%d): ymin: %f\n", cnt, getymin(ptr_param)); cnt++;
		printf("(%d): ymax: %f\n", cnt, getymax(ptr_param)); cnt++;
		printf("(%d): Anzahl für Linien im Analysegebiet xpoints: %d\n", cnt, getxpoints(ptr_param)); cnt++;
		printf("(%d): Anzahl für Linien im Analysegebiet ypoints: %d\n", cnt, getypoints(ptr_param)); cnt++;

		printf("\nWelchen Parameter wollen Sie aendern?\n"
				"Geben Sie die Zeilennummer ein.\n"
				"Möchten Sie nichts ändern, geben Sie '0' ein.\n"
				"Falls Sie das Programm abbrechen möchten, geben Sie '-1' ein.\n");


		scanf("%d", &eingabe);

		switch(eingabe)
		{

		case 1:
			/* if(getfraktalvariante(ptr_param) == apfel)
			{
				printf("Fraktaltyp = apfel.\n"
						"Realteil fuer c = 0.4 (Initialwert)\n");
				break;
			}
			*/
			printf("Wert für den Realteil von c: ");
			scanf("%lf", &dtemp);
			z->realteil = (tRealteil)dtemp;
			break;
		case 2:
			/*if(getfraktalvariante(ptr_param) == apfel)
			{
				printf("Fraktaltyp = apfel.\n"
						"Imagteil fuer c = 0.4 (Initialwert)\n");
				break;
			}*/
			printf("Wert für den Imaginaerteil von c: ");
			scanf("%lf", &dtemp);
			z->imagteil = (tImagteil)dtemp;
			break;
		case 3:
			printf("Wert für den Radius R: ");
			scanf("%lf", &dtemp);
			setRadius((tRadius)dtemp, ptr_param);
			break;
		case 4:
			printf("Wert für maximale Anzahl der Iterationen: ");
			scanf("%d", &uitemp);
			setimax(uitemp, ptr_param);
			break;
		case 5:
			printf("Wert für Fraktalvariante (0 = apfel, 1 = julia): ");
			scanf("%d", &uitemp);
			if(uitemp == 0 || uitemp == 1)
			{
				setfraktalvariante(uitemp, ptr_param);
			}
			else printf("Eingabe falsch! (0 = apfel, 1 = julia)\n");
			break;
		case 6:
			printf("Wert für xmin: ");
			scanf("%lf", &dtemp);
			setxmin(dtemp, ptr_param);
			break;
		case 7:
			printf("Wert für xmax: ");
			scanf("%lf", &dtemp);
			setxmax(dtemp, ptr_param);
			break;
		case 8:
			printf("Wert für ymin: ");
			scanf("%lf", &dtemp);
			setymin(dtemp, ptr_param);
			break;
		case 9:
			printf("Wert für ymax: ");
			scanf("%lf", &dtemp);
			setymax(dtemp, ptr_param);
			break;
		case 10:
			printf("Wert für xpoints: ");
			scanf("%lf", &dtemp);
			setxpoints(dtemp, ptr_param);
			break;
		case 11:
			printf("Wert für ypoints: ");
			scanf("%lf", &dtemp);
			setypoints(dtemp, ptr_param);
			break;
		case 0:
			printf("Programm OK\n");
			c = 1;
			return TRUE;
		case -1:
			c = 1;
			printf("Programmabbruch\n");
			return FALSE;
		default:
			fehlercnt++;

		}



	}

	return 0;
}







/* v3_diag.c */
