#include <stdio.h>

void LireInf2(int *n)
{
	do{
		printf("Entrez un entier entre 0 et 2.\n");
		scanf("%d" , n);
	}

	while (*n < 0 || *n > 2);
}

int Arbitre(int *m, int *o){

	if(*m == *o)
	{
		return 0;
	}
	
	if(*m == ((*o + 1) %3))
	{
		return 1;
	}

	return 2;		
}

int main(void)
{ 
	int i;

 	int J1, J2;
	 
	int res;
	
	for(i = 0; i < 10; i++){

		LireInf2(&J1);

		LireInf2(&J2);

		printf("Vous avez choisi %d %d\n", J1,J2);

		res = Arbitre(&J1, &J2);

		printf("J1 = %d J2 = %d res = %d\n", J1, J2, res);

	}

	

}

