#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const * argv[]) {
	int i;
	FILE * fp = NULL;
	 
	/* point 1 */
	printf("Voici le nombre d'arguments qu'a le programme %d \n",argc);
	

	/* point 2 et 3 */
	for (i = 1; i < argc; ++i) {
		if (argv[i][0] == '-') {

			printf("Le premier argument commence par -\n");
		}
		else {
			fp = fopen(argv[i], "r");
			if (fp == NULL){
				printf("Désolé... la lecture du fivhier %s n'a pas abouti...\n",argv[i]);
			}
			else {
				printf("Bravo ! Le fichier  %s a été lu\n",argv[i]);
				fclose(fp);
			}
		}
	}
	return 0;
}
