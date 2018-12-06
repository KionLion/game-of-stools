#include <stdio.h>

int main(void)
{ 
	printf("Programme pour calculer l'équation d'uen droite");

	int xP, yP, xQ, yQ, xR, yR, xS, yS;
	
	float a, b, m, p, xI, yI; /* a coefficient directeur et b ordonnée à l'origine*/

	printf("\nDonnez xP : ");

	scanf("%d", &xP); /* saisie du premier nombre */

	printf("Donnez yP : ");

	scanf("%d", &yP); /* saisie du deuxième nombre */

	printf("Donnez xQ : ");

	scanf("%d", &xQ); /* saisie du premier nombre */

	printf("Donnez yQ : ");

	scanf("%d", &yQ); /* saisie du deuxième nombre */

	printf("Donnez xR : ");

	scanf("%d", &xR); /* saisie du premier nombre */

	printf("Donnez yR : ");

	scanf("%d", &yR); /* saisie du deuxième nombre */

	printf("Donnez xS : ");

	scanf("%d", &xS); /* saisie du premier nombre */

	printf("Donnez yS : ");

	scanf("%d", &yS); /* saisie du deuxième nombre */
	
	a = (yP-yQ)/(xP-xQ);/* coefficient directeur de la premiere droite*/

	m = (yR-yS)/(xR-xS);/* coefficient directeur de la deuxieme droite*/


	b = yP - a*xP;/* ordonnée à l'origine de la premiere droite*/

	p = yR - m*xR;/* ordonnée à l'origine de la premiere droite*/
	

	printf("L'équation de la premiere droite est y = %fx + %f", a, b);

	printf("\nL'équation de la deuxieme droite est y = %fx + %f", m, p);

	
	xI = (p-b)/(a-m);/*abscisse de l'intersection*/
	yI = a*xI+b;/*ordonnée de l'intersection*/


	printf("\nLe point d'intersection est de coordonnées xI = %f et yI = %f", xI, yI);
	

}
