#include <stdio.h>

int main(void)
{ 

	int n, p;/*2 nombres entiers*/

	float somme; /* somme des nombres n et p */

	printf("Donnez le premier nombre : ");

	scanf("%d", &n); /* saisie du premier nombre */

	printf("\n%d", n);

	printf("Donnez le deuxième nombre : ");

	scanf("%d", &p); /* saisie du deuxième nombre */

	printf("\n%d", p);

	somme = n + p;/*calcul de la somme*/ 

	printf("\nLe résultat de la somme des 2 nombre est %f\n", somme);

	if((n%2==0) && (n%3==0))
	{
		printf("%d est divisible par 2 et par 3\n", n);

	}

	if((n%2==0) || (n%3==0))
	{
		printf("\n%d est divisible par 2 ou par 3\n", n);

	}

	if((p%2==0) && (p%3==0))
	{
		printf("\n%d est divisible par 2 et par 3\n", p);

	}

	if((p%2==0) || (p%3==0))
	{
		printf("\n%d est divisible par 2 ou par 3\n", p);

	}
}
