/* Datei: v3_dialo.h              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#ifndef __dialog
#define __dialog

#include <stdio.h>
#include <stdlib.h>
#include "tComplex.h"
#include "tParam.h"

/*--- Definitionen ---------------------------------------------------------*/

typedef enum {FALSE, TRUE} bool;

/*--- Parameter Dialog ------------------------------------------------------*/

bool ParamDialog(tParam *ptr_param, tComplex *z);

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char InputChar();

#endif

/* v3_dialo.h */
