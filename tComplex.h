/*
 * tComplex.h
 *
 *  Created on: 02.12.2016
 *      Author: mrt
 */

#ifndef TCOMPLEX_H_
#define TCOMPLEX_H_

typedef double tRealteil; // tRealteil wird als double deklariert, wegen leichterer Änderbarkeit
typedef double tImagteil; // tImagteil  -                    "						-

typedef struct
{
	tRealteil realteil; // Realteil von tComplex
	tImagteil imagteil; //Imaginaerteil von tComplex

} tComplex;

/* TODO Funktionen */

double betrag (tComplex a); // Funkt. für Berechnung des Betrags
double betragberechnen (tComplex *a); // alternative Fkt.
double betragberechnen2 (tComplex *a); // alternative Fkt.

double winkel (tComplex a); // Funkt. für Berechnung des Winkels
double winkelberechnen(tComplex *a); // alternative Fkt.

tRealteil getRealteil(tComplex *a); // Funkt. um Realteil zurück zu geben
tImagteil getImagteil(tComplex *a); // Funkt. um Imagteil zurück zu geben

void setRealteil(tRealteil real, tComplex *a);
void setImagteil(tImagteil imag, tComplex *a);


#endif /* TCOMPLEX_H_ */


