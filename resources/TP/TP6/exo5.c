#include <stdio.h>
#include <stdlib.h>

int cAll(FILE * file,int* caract, int* lines, int* word) {
	int x, y;
	
	while ((x = fgetc(file)) != EOF) {
		*caract += 1;
		if (x == '\n') {
			*lines += 1;
		}
		if (x == '\n' || x == ' ' || x == '\t') {
			if (y != '\n' && y != ' ' && y == '\t') {
				*word += 1;
			}
		}

		y = x;
	}
	return(0);
}

int main(int argc, char const *argv[]) {
	int n;
	FILE * fp = NULL;
	int n_caract = 0; 
	int n_lines = 0;
	int n_word = 0;
	
	/* point 1 */
	printf("Il y a %d arguments \n",argc);
	

	/* point 2 et 3 */
	for (n = 1; n < argc; ++n) {
		if (argv[n][0] == '-') {
			printf("Le premier argument commence par -\n");
		}
		else {
			fp = fopen(argv[n], "r");
			if (fp == NULL){
				printf("Le fichir %s ne peut pas etre lu, fin du programme\n",argv[n]);
			}
			else {
			

				cAll(fp,&n_caract, &n_lines, &n_word);
				printf("Le nombre de caractère est de : %d\n",n_caract);
				printf("Le nombre de ligne est de : %d\n",n_lines);
				printf("Le nombre de mots est de : %d\n",n_word);	
				fclose(fp);
			}
		}
	}
	return 0;
}
