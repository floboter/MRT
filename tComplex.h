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

double betrag (tComplex a); // Funkt. für Berechnung des Betrags
double winkel (tComplex a); // Funkt. für Berechnung des Winkels

tRealteil gibRealteil(tComplex a); // Funkt. um Realteil zurück zu geben
tImagteil gibImagteil(tComplex a); // Funkt. um Imagteil zurück zu geben


#endif /* TCOMPLEX_H_ */


