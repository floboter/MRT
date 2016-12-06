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

/*--- Datentypvereinbarungen -----------------------------------------------*/
int GetItera(tComplex c, tComplex z, tParam p);
tColor GetColorValue(int it, int it_max);

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/
void Fraktal(tComplex c, tComplex z, tParam p);

#endif

/* v3_frakt.h */
