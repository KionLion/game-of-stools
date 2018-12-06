#include <MLV/MLV_all.h>
#include <stdio.h>

int main( int argc, char *argv[] ){



int l, h, p, r, dim;
	
	
	printf("Largeur:");

	scanf("%d",&l);

	printf("Hauteur:");

	scanf("%d",&h);
	
	printf("Rayon du cercle:");

	scanf("%d",&r);

	printf("Pas:");

	scanf("%d",&p);



	MLV_create_window( "beginner - 1 - hello world", "hello world", l, h );



	if (l<h){

		dim = l;
	}
	else {
		dim = h;
	}

	while (r <= (dim/2)){

		MLV_draw_filled_circle(l/2,h/2,r,MLV_COLOR_BLUE);

		MLV_actualise_window();

		MLV_wait_seconds(3);

		r = r+p;
	}
	
	/* Met a jour l'affichage.*/
	
	MLV_actualise_window();

	
	/* Attend 10 secondes avant la fin du programme.*/
	
	MLV_wait_seconds( 10 );

	
	/* Ferme la fenêtre*/
	
	MLV_free_window();


	return 0;
}
