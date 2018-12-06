#include <MLV/MLV_all.h>
#include <stdio.h>

int main( int argc, char *argv[] ){


	int i, l, h, s;
	

	
	printf("Largeur:");

	scanf("%d",&l);

	printf("Hauteur:");

	scanf("%d",&h);

	printf("Sommets:");

	scanf("%d",&s);


	MLV_create_window( "beginner - 1 - hello world", "hello world", l, h );


	int coordonnees[s][2];


	for(i = 0; i < s; i++){

			MLV_draw_text(5, 5, "%d",s - i, MLV_COLOR_BLUE);


			MLV_actualise_window();


			MLV_wait_mouse(&coordonnees[i][1], &coordonnees[i][0]);
		}
		
		for(i = 0; i < s-1; i++){

			MLV_draw_line(coordonnees[i][1],coordonnees[i][0],coordonnees[i+1][1],coordonnees[i+1][0], MLV_COLOR_BLUE);}

								
			MLV_draw_line(coordonnees[0][1], coordonnees[0][0], coordonnees[s-1][1], coordonnees[s-1][0], MLV_COLOR_BLUE);

									
	/* Met a jour l'affichage.*/
	
	MLV_actualise_window();

	
	/* Attend 10 secondes avant la fin du programme.*/
	
	MLV_wait_seconds( 10 );

	
	/* Ferme la fenêtre*/
	
	MLV_free_window();
		
		return 0;
}

