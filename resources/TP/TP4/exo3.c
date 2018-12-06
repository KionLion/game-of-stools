#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define N 21

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

int affichage(int histo[]){

    int i;
   
    printf("Histogramme : \n");

    for( i = 0 ; i <= N ; i++){

        printf("%d ", histo[i] );
       
    }
  return 0; 
}

int main(void){
    
   	int note[21], histo[21], max; /*Note de 0 à 20 --> en tout 21*/


   	srand(time(NULL));


   	printf("les valeurs doivent etre inférieures au max qui est :");
   	
	scanf("%d",&max);


  	printf("NOTE :\n");

	printf ("\n");

   	initAlea(note,21,max);

	printf ("\n");

   	histogramme(note,histo);

    	affichage(histo);

}
