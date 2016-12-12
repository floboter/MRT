/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include "tParam.h"
#include "tComplex.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	/* Testfunktionen */

	// tComplextesten();
	// tParamtesten();

	// ParamDialog();

	// return 0;

	/*--- Variablendeklaration ---------------------------------------------*/

	tParam parameter;
	tComplex c1, z1;

  	/*--- Initialwerte -----------------------------------------------------*/
	printf("Initialwerte werden gesetzt\n");

	parameter.fraktalvariante = apfel;
	parameter.R = 4;
	parameter.xmin = -2;
	parameter.xmax = 2;
	parameter.ymin = -2;
	parameter.ymax = 2;
	parameter.imax = 75;
	parameter.xpoints = 1024; // Geaendert vom vorgegebenen Initialwert (Streifen in Ausgabe)
	parameter.ypoints = 768; // Geaendert vom vorgegebenen Initialwert (Streifen in Ausgabe)

	c1.realteil = 0.4;
	c1.imagteil = 0.4;
	z1.realteil = 0;
	z1.imagteil = 0;

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/

	printf("ParamDialog wird ausgefuehrt\n\n");

	bool programmstatus = ParamDialog(&parameter, &c1); // bool programmstatus gibt an, ob Nutzer Programm beendet oder OK gegeben hat


	//printf("%d", programmstatus); // DEBUG

	if(programmstatus == 1)
	{
		// printf("xmin, xmax, ymin, ymax: %lf,%lf,%lf,%lf\n", parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); //DEBUG

		InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); // Initialisierung der Grafik


		LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein

		/*----------------------------------------------------------------------*/
		/*-------------------Fraktale berechnen und ausgeben--------------------*/
		/*----------------------------------------------------------------------*/

		Fraktal(&c1,&z1,&parameter);
		printf("Fraktale wurden berechnet\n");

		UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
	}
	else if(programmstatus == 0)
	{
		return 0;
	}

	/*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
	/*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
	/*sich das Fenster wieder. */

	//InputChar(); // ist zwar vorgegebene Funkt. geht aber nicht



	int grafikschliessen = 0;
	printf("Um die Grafik zu schliessen, druecken Sie: 1\n");

	while(grafikschliessen != 1)
	{
		scanf("%d", &grafikschliessen);
		if(grafikschliessen == 1)
		{
			CloseGraph();
			printf("Programm beendet.\n");
		}
		else
		printf("Falsche Eingabe.\n");
	}

	return 0;
}


