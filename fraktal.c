/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"


/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int GetItera(tComplex c, tComplex z, tParam p){ //Wichtig, dass return int.
	int itera;
	return itera;

}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
tColor GetColorValue(int it, int it_max){

	tColor it_rueckgabe;

	if (it>it_max){
		it_rueckgabe=0; 		//Null Entspricht schwarz, lt. Anforderung
	}
	else {
	it_rueckgabe= (tColor)(it%16);

	}
	return it_rueckgabe;
}

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void Fraktal(tComplex c, tComplex z, tParam p){
	 					//TODO Von Komplexen Zahl zu Koordinaten
	SetPoint();			//TODO Koordinaten einarbeiten und richtige Farbe
						//TODO C und z aufaddieren

}

/* v3_frakt.c */
