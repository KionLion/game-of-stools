#include <MLV/MLV_all.h>
#include <stdio.h>

/*
// Attention ! 
// Pour pouvoir compiler ce programme sous windows et sous macintosh,
// il faut, pour la déclaration du main, respecter strictement la syntaxe
// suivante :
*/

int main(int argc, char *argv[]){

        int x, y, e, r;

    	char c; 



   	printf("Absc du cercle: ");

    	scanf("%d",&x);

    	printf("ordon du cercle: ");

    	scanf("%d",&y);

    	printf("epais du cercle: ");

    	scanf("%d",&e);

	printf("rayon du cercle: ");

    	scanf("%d",&r);

    
    	while(r>x || r>y){   /*Et non pas && car sinin --> erreur de segmentation*/

    	printf("impossible chossissez un autre rayon svp:");

    	scanf("%d",&r);

    	}
    
    	printf("Couleurs : y (yellow), b (blue), w (white), g (green), r (red), \n");

    	printf("Choisir :");

    	scanf(" %c",&c);

	MLV_create_window( "beginner - 1 - hello world", "hello world", x*2, y*2 );

     	switch(c){/*plus sipmle que suite de if car ça coute cher*/

            	case 'y': MLV_draw_filled_circle(x,y,r,MLV_COLOR_YELLOW);break;

            	case 'b':MLV_draw_filled_circle(x,y,r,MLV_COLOR_BLUE);break;

		case 'w':MLV_draw_filled_circle(x,y,r,MLV_COLOR_WHITE);break;

            	case 'g':MLV_draw_filled_circle(x,y,r,MLV_COLOR_GREEN);break;

            	case 'r':MLV_draw_filled_circle(x,y,r,MLV_COLOR_RED);break;

            	default : MLV_draw_filled_circle(x,y,r,MLV_COLOR_BLACK);

    	}

 	

    	MLV_draw_filled_circle(x,y,r-e,MLV_COLOR_BLACK); 

    	/* Met a jour l'affichage.*/
	
	MLV_actualise_window();

	
	/* Attend 10 secondes avant la fin du programme.*/
	
	MLV_wait_seconds( 10 );

	
	/* Ferme la fenêtre*/
	
	MLV_free_window();

    return 0;

}
