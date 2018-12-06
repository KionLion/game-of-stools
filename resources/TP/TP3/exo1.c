#include <stdio.h>

void ValAbsolue(int *x)
{
	if(*x < 0)
	{
		*x = -*x;
	}
}



int main(void)
{ 
	int a;

 	printf("Entrez une valeur :");

	scanf("%d", &a);

	ValAbsolue(&a);

	printf("Sa valeur absolue est %d :", a);
	

}

