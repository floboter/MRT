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


/* Die Struktur tComplex beschreibt eine komplexe Zahl mit Real- und Imaginaerteil */
typedef struct
{
	tRealteil realteil; // Realteil von tComplex
	tImagteil imagteil; //Imaginaerteil von tComplex

} tComplex;

/* Funktionen.
 * WICHTIG: Es wird die Adresse einer komplexen Zahl benoetigt. */

double betrag(tComplex *a);  // Funkt. für Berechnung des Betrags

double winkel(tComplex *a); // Funkt. für Berechnung des Winkels

tRealteil getRealteil(tComplex *a); // Funkt. um Realteil zurück zu geben
tImagteil getImagteil(tComplex *a); // Funkt. um Imagteil zurück zu geben

void setRealteil(tRealteil real, tComplex *a); // Funkt. um den Realteil zu setzen
void setImagteil(tImagteil imag, tComplex *a); // Funkt. um den Imagteil zu setzen


#endif /* TCOMPLEX_H_ */


