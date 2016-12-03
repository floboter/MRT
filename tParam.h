/*
 * tParam.h
 *
 *  Created on: 02.12.2016
 *      Author: mrt
 */

#ifndef TPARAM_H_
#define TPARAM_H_

typedef double tRadius;


/* ftype deklariert das Fraktal. Entweder Apfelmännchen (= apfel = 0) oder Juliamenge (= julia = 1) */
typedef enum
{
	apfel, // = 0
	julia  // = 1
} ftype;

typedef struct
{
	tRadius R; // radius R zur Beschreibung des kreisförmigen gebietes G für komplexe Zahlen
	unsigned int imax; // maximale Iterationszahl
	double xmin, xmax, ymin, ymax; // Kennzeichnung für das komplexwertige Analysegebiet
	unsigned int xpoints, ypoints; // Anzahlen für Linien im Analysegebiet
	ftype fraktalvariante; // Fraktalvariante: Apfelmännchen oder Juliamenge

} tParam;

/* Funktionen */

void setRadius(tRadius r, tParam *p);
tRadius getRadius(tParam *p);

void setimax(unsigned int i, tParam *p);
unsigned int getimax(tParam *p);

void setxmin(double x_min, tParam *p);
double getxmin(tParam *p);

void setxmax(double x_max, tParam *p);
double getxmax(tParam *p);

void setymin(double y_min, tParam *p);
double getymin(tParam *p);

void setymax(double y_max, tParam *p);
double getymax(tParam *p);

void setxpoints(unsigned int i, tParam *p);
unsigned int getxpoints(tParam *p);

void setypoints(unsigned int i, tParam *p);
unsigned int getypoints(tParam *p);

void setfraktalvariante(ftype f, tParam *p);
ftype getfraktalvariante(tParam *p);






#endif /* TPARAM_H_ */
