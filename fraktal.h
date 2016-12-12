/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************
  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"
*****************************************************************************/

#ifndef __fraktal
#define __fraktal
#include "graphic.h"
#include "tComplex.h"
#include "tParam.h"

/*--- Iterationswert berechnen --------------------------*/
int GetItera( tComplex *c, tComplex *z, tParam *param);

/*--- Farbwert anhand Iteration berechnen --------------------------*/
tColor GetColorValue(int it, int it_max);

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/
void Fraktal( tComplex *c, tComplex *z, tParam *p);

/*--- Testfunktionen --------------------------*/

void tGetItera();
void tGetColorValue(int i, int imax);

#endif

/* v3_frakt.h */
