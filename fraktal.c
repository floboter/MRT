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

int GetItera( tComplex *c, tComplex *z, tParam *param){
 int i=0;
 double zrealTmp, a,b;
 while(i<=param->imax){
	 if((z->realteil*z->realteil+z->imagteil*z->imagteil)>(param->R*param->R)){
	     printf("Zeichne: %d \n",i);//DEBUG
	     printf("C= %g+j%g \n",c->realteil,c->imagteil);//DEBUG
	     printf("Z= %g+j%g \n",z->realteil,z->imagteil);//DEBUG
		 break;

	 }

	 i++;
	 zrealTmp = getRealteil(z);
	 a=z->realteil*z->realteil-z->imagteil*z->imagteil+c->realteil;
	 setRealteil(a,z);
	 b=2*zrealTmp*z->imagteil+c->imagteil;
	 setImagteil(b,z);

 }
 return i;

}


/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

tColor GetColorValue(int i, int imax){
	if(i>=imax)return black;

	int color=i%15+1;
	return color;
}

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void Fraktal( tComplex *c, tComplex *z, tParam *p){
	int x=0;
    while(x<getxpoints(p)){
     int y=0;
	  while(y<getypoints(p)){
		  //printf("Checking %d %d %g %g %d\n",x,y,getxmax(p),getxmin(p),getxpoints(p));//DEBUG
		  double a=(x/(double)getxpoints(p))*(double)(getxmax(p)-getxmin(p))+getxmin(p);

		  double b=y/(double)getypoints(p)*(double)(getymax(p)-getymin(p))+getymin(p);
		  //printf("Position: %g %g \n",a,b);//DEBUG

		  if(getfraktalvariante(p)==apfel){
			  setRealteil(a,c);
			  //printf("NeuerRealteil:%g\n",c->realteil);//DEBUG
			  setImagteil(b,c);

		  }
		  else{
			  setRealteil(a,z);
			  setImagteil(b,z);
		  }
		  int i= GetItera(c,z,p);

		  tColor color=GetColorValue(i,getimax(p));
		  SetPoint(a,b,color);
		  y++;
	  }
	  x++;
  }
}

/* v3_frakt.c */
