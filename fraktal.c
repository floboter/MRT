/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "tParam.h"
#include "tComplex.h"



/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
/*int GetItera(tComplex c, tComplex z, tParam p){ //Wichtig, dass return int.
	int itera;
	return itera;

}
*/
/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
/*tColor GetColorValue(int it, int it_max){

	tColor it_rueckgabe;

	if (it>it_max){
		it_rueckgabe=0; 		//Null Entspricht schwarz, lt. Anforderung
	}
	else {
	it_rueckgabe= (tColor)(it%15+1); //Sonst Farbe ungleich schwarz wählen

	}
	return it_rueckgabe;			//Gibt Farbe vom Typ tColor zurück
}
*/
/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
/*

void Fraktal(tComplex *c, tComplex *z, tParam *p){

printf("%d",5);


}
*/
/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/

int GetItera(tComplex *c, tComplex *z, tParam *param){
 int i=0;
 while(i<getimax(param)){

	 if(betrag(z)>getRadius(param)){
	     /*printf("Itera: %d \n",i);//DEBUG
	     printf("C= %g+j%g \n",c->realteil,c->imagteil);//DEBUG
	     printf("Z= %g+j%g \n",z->realteil,z->imagteil);//DEBUG
	     */
		 break;

	 }

	 i++;

	 double realneu = getRealteil(z)*getRealteil(z) - getImagteil(z)*getImagteil(z) + getRealteil(c);  // Zr*Zr - Zi*Zi + Cr
	 double imagneu = 2*getRealteil(z)*getImagteil(z) + getImagteil(c); // 2*Zr*Zi + Ci
	 setRealteil(realneu, z);
	 setImagteil(imagneu, z);


 }
 // printf("Itera: %d \n",i);//DEBUG
 return i;

}


/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

tColor GetColorValue(int i, int imax){
	if(i>=imax)
	{
		return black;
	}

	int color=i%15+1;
	return color;
}

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void Fraktal(tComplex *c, tComplex *z, tParam *p){
	int x=0;
    while(x<getxpoints(p)){
     int y=0;
	  while(y<getypoints(p)){
		  //printf("Checking %d %d %g %g %d\n",x,y,getxmax(p),getxmin(p),getxpoints(p));//DEBUG
		  double a = x/(double)getxpoints(p)*(getxmax(p)-getxmin(p))+getxmin(p);

		  double b = y/(double)getypoints(p)*(getymax(p)-getymin(p))+getymin(p);
		  // printf("Position: %g %g \n",a,b);//DEBUG

		  int i = GetItera(c,z,p);

		  if(getfraktalvariante(p)==apfel){
			  setRealteil(a,c);
			  //printf("NeuerRealteil:%g\n",c->realteil);//DEBUG
			  setImagteil(b,c);
			  setRealteil(0,z);
			  setImagteil(0,z);

		  }
		  else if(getfraktalvariante(p)==julia){
			  setRealteil(a,z);
			  setImagteil(b,z);
		  }
		  // TEST int i = GetItera(c,z,p);

		  tColor color=GetColorValue(i,getimax(p));
		  SetPoint(a,b,color);
		  y++;
	  }
	  x++;
  }
}

/* v3_frakt.c */
