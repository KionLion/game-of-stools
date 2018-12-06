#include <stdio.h>

int main(void)
{ 

	int J;/*2 nombres entiers*/

	float Si;

	float A;

	float M;
	
	float Se;

	float Jo;

	printf("Nombre de jours : ");

	scanf("%d", &J); /* saisie du premier nombre */

	Si = J/100;

	A = J/360;

	M = J/30;

	Se = J/7;

	Jo = J/1;

	printf("%d jours correspondent à : %f siècles, %f années, %f mois, %f semaines, %f jours.", J, Si, A, M, Se, Jo);


}
