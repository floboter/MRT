/*
 * tComplex.c
 *
 *  Created on: 02.12.2016
 *      Author: mrt
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tComplex.h"


/* Die Funktion "double betrag" gibt den Betrag einer komplexen Zahl zurueck. */
double betrag (tComplex *a)
{
	return (sqrt((a->realteil)*(a->realteil)+(a->imagteil)*(a->imagteil)));
}

/* Die Funktion "double winkel" gibt den Winkel phi einer komplexen Zahl zurueck.
 *(wird in der Aufgabenstellung aber nicht benoetigt.) */
double winkel(tComplex *a)
{
	if(abs(a->realteil) > 10.0e-10) // Ueberpruefung, ob Realteil groeßer als Null
		{
			return (atan((a->imagteil)/(a->realteil))); // gib Winkel in RAD
		}
		else if(a->imagteil>0) // Ueberpruefung, ob imagteil groeßer Null
		{
			return M_PI/2; // gib pi/2
		}
		else
		{
			return 3/2*M_PI; // ansonten gib 3/2 pi
		}
}

/* Die Funktion "tRealteil getRealteil" gibt den Realteil der komplexen Zahl zurueck */
tRealteil getRealteil(tComplex *a)
{
	return a->realteil;
}

/* Die Funktion "tImagteil getImagteil" gibt den Imagteil der komplexen Zahl zurück */
tImagteil getImagteil(tComplex *a)
{
	return a->imagteil;
}

/* Die Funktion "void setRealteil" setzt den Realteil der komplexen Zahl. */
void setRealteil(tRealteil real, tComplex *a)
{
	a->realteil = real;
	//printf("Realteil: %g\n",real);//DEBUG
}
/* Die Funktion "void setImagteil" setzt den Imagniaerteil der komplexen Zahl. */
void setImagteil(tImagteil imag, tComplex *a)
{
	a->imagteil = imag;
}


int tComplextesten()
{
	tComplex a,b;

		a.realteil = 3.0;
		a.imagteil = -4;
		b.realteil = -3.0;
		b.imagteil = 4;



	printf("realteil von a: %f\n", a.realteil);
	printf("imagteil von a: %f\n", a.imagteil);

	printf("Winkel von a: %f\n", winkel(&a));
	printf("Betrag von a: %f\n", betrag(&a));
	printf("Winkel von b: %f\n", winkel(&b));
	printf("Betrag von b: %f\n", betrag(&b));

		return 0;
}
