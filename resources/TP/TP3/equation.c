#include <stdio.h>
#include <math.h>
/* BUT : resoud une equation du second degre    */
/* PARAMETRES : valeur :les coefficients entiers*/
/*             adresse : 2 solutions possibles  */
/* RETOUR : le nombre de solution               */
/* -1 equation degeneree                        */
/* 0 pas de solution                            */
/* 1 un racine placee a l'adresse x             */
/* 2 deux racines placees aux adresses x et y   */

int resoudre(int a,int b,int c,double *r1, double *r2){
	int delta;
	delta = b*b-4*a*c;
	if(a == 0 && b==0){
	  if (c == 0)
	    return -1;
	  return 0;
	}
        if(a == 0 && b!=0){
	  *r1 = -c/b;
	   return 1; /* -c/b */ 
	}	

      	if(delta == 0){
	  *r1 = -b/(2*a);
	  return 1;
	}
	if(delta > 0){
	  *r1 = (-b-sqrt(delta))/(2*a);
	  *r2 = (-b+sqrt(delta))/(2*a);
	  return 2;
	}
	return 0;
	       
}




int main(void){
  int n;
  double r1,r2;
  n = resoudre(2,4,2,&r1, &r2);
  switch(n){
  case -1 : printf("Une infinité de solutions\n"); 
	  break;
  case 0 : printf("pas de solutions\n");
	  break;
  case 1 : printf("1 solution %f \n",r1);
	  break;	
  case 2 : printf("2 solutions %f et %f\n",r1,r2)  ;
	  break;
  default : printf("erreur");
    break;

  }



  return 0;
}
