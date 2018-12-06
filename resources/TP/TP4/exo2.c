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

int position(int t[] , int sz , int x){

	int i;

	for (i = 0 ; i < sz ; i++ ){

		if (t[i]==x){

		return i ;
		}
	}
	
	return -1 ;
}

int main(void){

	int a, x, sz, t[sz], max;
	
	srand(time(NULL));


	
	printf("Saisir la taille souhaitée... :");

	scanf("%d",&sz);



	printf("...et les valeurs doivent etre inférieures au max qui est :");

	scanf("%d",&max);

	initAlea(t,sz,max);	
	


	printf ("\n");



	printf("x :");

	scanf("%d",&x);

	a = position(t,sz,x);


	printf("L'indice de %d est donc %d. \n",x,a);

}
