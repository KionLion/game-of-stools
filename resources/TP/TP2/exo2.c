#include <stdio.h>

int main(void)
{ 

	int n; /* nombre entré */

	int a; /* nombre d'essais */
	
	printf("Entrez un nombre: \n");

	scanf("%d", &n); /* saisie du nombre */

	for(a=1;a<10;a++)
	{
	
		if(n<27)
		{
			printf("La valeur saisie est inférieure au nombre secret.");
			scanf("%d", &n);
		}

		else if(n>27)
		{
			printf("La valeur saisie est superieure au nombre secret.");
			scanf("%d", &n);
		}

		if(n<0)
		{
			printf("La valeur saisie doit etre comprise entre 0 et 1000.");
			scanf("%d", &n);
		}

		if(n>1000)
		{
			printf("La valeur saisie doit etre comprise entre 0 et 1000.");
			scanf("%d", &n);
		}

		if(n==27)
		{		
			printf("Bravo ! Vous avez gagné en %d essais !", a+1);
			return 0;
		}

		
	}

	if ((a>=10) && (n!=27))
	{	
		printf("Perdu...");
	}

	

}
