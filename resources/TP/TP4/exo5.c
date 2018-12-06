#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void initAlea(int t[],int sz , int max){

 	int i,x;

	srand(time(NULL));
	
	for ( i = 0 ; i < sz ; i++ ){

	x = rand();

	while (x >= max){

		x = rand();
	}

	t[i] = x ;

	printf("%d ",t[i]);
}
}


void sommeTab (int a[], int b[], int resultat[], int sz){

	int i ;

	for ( i = 0 ; i <= sz ; i++ ){

		

		resultat[i] = a[i] + b[i] ;

		c[i]= resultat[i];

		printf ("%d ", c[i]);
	}

int main (void){

	int a[n], b[n], resultat[n], m, max;

	printf("Tableau A:\n");
	initAlea(a,m,max);

	printf("Tableau B:\n");
	initAlea(b,m,max);

	printf("Tableau Résultat (C):\n");

	sommeTab(a,b,resultat,m);

	printf("\n");

}
