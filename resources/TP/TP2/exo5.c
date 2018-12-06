#include <stdio.h>

void ajouteDix(int *n)
{
	*n = *n + 10;
	
}

void echangeInt(int *m, int *l)
{
	int ech;
	ech = *m;
	*m = *l;
	*l = ech;
}

int main(void)
{ 
 	
	int n;
	
	int x, y;

	printf("Choissisez un entier :");

	scanf("%d", &n);

	printf("Le nombre est %d et son adresse est %p.\n", n, &n);

	ajouteDix(&n);	

	printf("Le nombre est %d et son adresse est %p.\n", n, &n);

	printf("Choissisez deux entiers :\n");

	scanf("%d", &x);
	
	scanf("%d", &y);

	echangeInt(&x,&y);

	printf("On les a échangés : %d et %d.\n", x, y);



}

