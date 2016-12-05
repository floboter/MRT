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

	//return 0;

	/*--- Variablendeklaration ---------------------------------------------*/

	tParam parameter;
	tComplex c1, z1;

  	/*--- Initialwerte -----------------------------------------------------*/

	parameter.fraktalvariante = apfel;
	parameter.R = 4;
	parameter.xmin = -2;
	parameter.xmax = 2;
	parameter.ymin = -2;
	parameter.ymax = 2;
	parameter.imax = 75;
	parameter.xpoints = 640;
	parameter.ypoints = 480;

	c1.realteil = 0.4;
	c1.imagteil = 0.4;
	z1.realteil = 0;
	z1.imagteil = 0;

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter über Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/

	int programmstatus = ParamDialog(&parameter, &c1); // int programmstatus gibt an, ob Nutzer Programm beendet oder OK gegeben hat

	if(programmstatus == 1)
	{
		// printf("xmin, xmax, ymin, ymax: %lf,%lf,%lf,%lf\n", parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); //DEBUG

		InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); // Initialisierung der Grafik


		LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
		/*----------------------------------------------------------------------*/
		/*--- Fraktale berechnen und ausgeben                                 --*/
		/*----------------------------------------------------------------------*/
		while (TRUE){
			if (GetItera(c1,z1,p)>=tParam.getimax()){           //Nur Entwurf. Funktioniert nicht. Bei idee ändern
				break;
			}
			else {
			Fraktal(c);							//TODO Fehlt noch einiges. Nur erste Idee
												//Aktuell: Tausendmal mit Startwert in Fraktal, bisssschen unsinnig
			}

		}
		UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
	}
	else if(programmstatus == 0)
	{
		return EXIT_FAILURE;
	}



	/*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
	/*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
	/*sich das Fenster wieder. */

	InputChar(); // ist zwar vorgegebene Funkt. geht aber nicht

	int grafikschliessen = 0;
	printf("Um die Grafik zu schliessen, druecken Sie: 1\n");

	while(grafikschliessen != 1)
	{
		scanf("%d", &grafikschliessen);
		if(grafikschliessen == 1)
		{
			CloseGraph();
		}else
			printf("Falsche Eingabe.\n");
	}





	return 0;
}


