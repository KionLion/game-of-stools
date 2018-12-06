#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 100000 
 
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


int main(void){

	int i, sz, max, t[sz];

	srand(time(NULL));
	
	printf("Les 20 valeurd aléatoires sont :\n");
	for( i = 0 ; i < 20 ; i++ ){
		printf("%d\n",rand());
	}

	printf("Saisir la taille souhaitée... :");

	scanf("%d",&sz);

	printf("...et les valeurs doivent etre inférieures au max qui est :");

	scanf("%d",&max);

	initAlea(t,sz,max);

	printf ("\n");
}
