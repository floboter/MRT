/*
 * tParam.c
 *
 *  Created on: 02.12.2016
 *      Author: mrt
 */


#include <stdio.h>
#include <stdlib.h>
#include "tParam.h"


/* Funktionen */

/* Es können jeweils alle Attribute der Struktur tParam gesetzt oder gelesen werden
 * WICHTIG: Es wird sowohl beim Setzen als auch beim Lesen die Adresse der Struktur tParam benötigt!
 *
 *  */

void setRadius(tRadius r, tParam *p)
{
	p->R = r;
}

tRadius getRadius(tParam *p)
{
	return p->R;
}

void setimax(unsigned int i, tParam *p)
{
	p->imax = i;
}
unsigned int getimax( tParam *p)
{
	return p->imax;
}

void setxmin(double x_min, tParam *p)
{
	p->xmin = x_min;
}
double getxmin(tParam *p)
{
	return p->xmin;
}

void setxmax(double x_max, tParam *p)
{
	p->xmax = x_max;
}
double getxmax(tParam *p)
{
	return p->xmax;
}

void setymin(double y_min, tParam *p)
{
	p->ymin = y_min;
}
double getymin(tParam *p)
{
	return p->ymin;
}

void setymax(double y_max, tParam *p)
{
	p->ymax = y_max;
}
double getymax(tParam *p)
{
	return p->ymax;
}

void setxpoints(unsigned int i, tParam *p)
{
	p->xpoints = i;
}
unsigned int getxpoints(tParam *p)
{
	return p->xpoints;
}

void setypoints(unsigned int i, tParam *p)
{
	p->ypoints = i;
}
unsigned int getypoints(tParam *p)
{
	return p->ypoints;
}

void setfraktalvariante(ftype f, tParam *p)
{
	p->fraktalvariante = f;
}
ftype getfraktalvariante(tParam *p)
{
	return p->fraktalvariante;
}


/* Testfunktion */

void tParamtesten()
{
	tParam param;
	param.R = 50;
	printf("Der eingestellte Radius ist: %f\n", param.R);

	setRadius(30, &param);
	printf("Der neue Radius ist: %f\n", getRadius(&param));

	param.fraktalvariante = apfel;
	printf("Die eingestellte Fraktalvariante ist: %d\n", param.fraktalvariante);

	setfraktalvariante(julia, &param);
	printf("Die neue Fraktalvariante ist: %d\n", getfraktalvariante(&param));
}
