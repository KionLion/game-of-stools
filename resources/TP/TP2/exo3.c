#include <stdio.h>

int main(void)
{ 
 	char n;

	char m=0;
	
	//printf("Entrez le premier caractère : \n");

	printf("Entrez les deux caractères : \n");/* sur la meme ligne */

	scanf(" %c", &n);/* avec espace */ 

	//printf("Entrez le deuxième caractère : \n");

	scanf(" %c", &m);/* avec espace */ 
	
	printf("\n*%c*\n*%c*\n",n,m);


}

