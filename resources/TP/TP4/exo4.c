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

void histogramme(int note[], int histo[]){

    	int i, j ;

    	for(i = 0; i < N; i++){

        	for(j = 0 ; j < N ; j++ ){

            	if( note[i] == j){

                	histo[j] = histo[j] + 1;
            	}
        	}	
   	 }
}

int affichage(int histo[]){ /*bloqué à ce niveau...*/

    int i;
   
    printf("Histogramme : \n");

    for( i = 0 ; i <= N ; i++){

        printf("%d ", histo[i] );
       
    }
  return 0; 
}

int main (void){

	int i;

	int max;


	printf("taille du tableau :");
	scanf("%d",&i);

	printf("max :");
	scanf("%d",&max);

	affichage(histo);

}
