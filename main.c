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
	if(ParamDialog(&parameter, &c1) == 0)
	{
		printf("bool ParamDialog == FALSE");
		return EXIT_FAILURE;
	}



    InitGraph (parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax); 	// Initialisierung der Grafik
    
    LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
  	/*----------------------------------------------------------------------*/
  	/*--- Fraktale berechnen und ausgeben                                 --*/
  	/*----------------------------------------------------------------------*/
    UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben
    
    /*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
    /*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
    /*sich das Fenster wieder. */
    InputChar(); 
    CloseGraph();
	
	return 0;
}


