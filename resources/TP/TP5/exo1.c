#include <MLV/MLV_all.h>


/*
// Attention ! 
// Pour pouvoir compiler ce programme sous windows et sous macintosh,
// il faut, pour la déclaration du main, respecter strictement la syntaxe
// suivante :
*/

int main( int argc, char *argv[]){

        int l, h;

 	printf("Largeur de la fenetre :");
	scanf("%d", &l);
	printf("\n");
	printf("Hauteur de la fenetre :");
	scanf("%d", &h);

	/* Créé et affiche la fenêtre*/
	MLV_create_window( "beginner - 1 - hello world", "hello world", l, h );


	/* Affiche "Bonjour !" a l'écran */
	
	/*MLV_draw_text(
		10, 120, 
		"Bonjour !",
		MLV_COLOR_CYAN
	);*/

	// Dessine un rectangle
	//
	
	/*MLV_draw_rectangle( MLV_COLOR_BLUE );*/
	MLV_draw_filled_rectangle( l/4, h/4, l/2, h/2, MLV_COLOR_BLUE);


	/* Met a jour l'affichage.*/
	
	MLV_actualise_window();

	
	/* Attend 10 secondes avant la fin du programme.*/
	
	MLV_wait_seconds( 10 );

	
	/* Ferme la fenêtre*/
	
	MLV_free_window();

	return 0;


	





}
