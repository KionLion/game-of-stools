#include <stdio.h>

int main(void)
{ 
 	char n;

	while( n!='E')/*boucle while pour repeter le menu jusqu'à ce qu'on sorte du jeu.*/
	{

		printf("Choisisez ue couleur : \n");

		scanf(" %c", &n); 

		if (n=='R')
		{
			printf("Red\n");
		}

		if (n=='G')
		{
			printf("Green\n");
		}
	
		if (n=='B')
		{
			printf("Blue\n");
		}

		if(n =='E')
		{
			printf("EXIT\n");
			return 0;

		}

		if (n!='R' && n!='G' && n!='B')
		{
			printf("Le choix n’appartient pas à l’ensemble des choix possibles.\n");
		}
		
		
	}
}

