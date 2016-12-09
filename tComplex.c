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




double betrag (tComplex *a)
{
	return (sqrt((a->realteil)*(a->realteil)+(a->imagteil)*(a->imagteil)));
}

/*
 * double winkel nimmt complexe zahl "a". berechnet den winkel der Zahl. Überprüft dabei, ob der Realteil größer ist als null.
 * ansonsten wird der winkel je nach vorzeichn vom imagteil ausgegeben.
 */


double winkel(tComplex *a) // alternative Fkt.
{
	if(abs(a->realteil) > 10.0e-10) // überprüfung, ob realteil größer als Null
		{
			return (atan((a->imagteil)/(a->realteil))); // gib winkel in RAD
		}
		else if(a->imagteil>0) // überprüfung, ob imagteil größer Null
		{
			return M_PI/2; // gib pi/2
		}
		else
		{
			return 3/2*M_PI; // ansonten gib 3/2 pi
		}
}

/*
 * Funktion gibt den Realteil der komplexen Zahl zurück
 */

tRealteil getRealteil(tComplex *a) // Funkt. um Realteil zurück zu geben
{
	return a->realteil;
}

/*
 * Funktion gibt den Imagteil der komplexen Zahl zurück
 */
tImagteil getImagteil(tComplex *a) // Funkt. um Imagteil zurück zu geben
{
	return a->imagteil;
}



/* TODO Die "set" Funktionen sind nur als Ergaenzung (Notwendigkeit kann noch diskutiert werden) */

void setRealteil(tRealteil real, tComplex *a)
{
	a->realteil = real;
	//printf("Realteil: %g\n",real);//DEBUG
}

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
