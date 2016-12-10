/* Datei: v3_dialo.h              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#ifndef __dialog
#define __dialog

#include "fraktal.h"

/*--- Parameter Dialog Prototyp --------------------------------------------*/
/*--- Definitionen ---------------------------------------------------------*/

typedef enum {FALSE, TRUE} bool;
bool ParamDialog(tParam *ptr_param, tComplex *z);

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char InputChar();
void InputDouble (double *value);
void InputInt (int *value);

#endif

/* v3_dialo.h */
