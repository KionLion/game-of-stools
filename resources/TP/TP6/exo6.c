#include <stdio.h>
#include <stdlib.h>

int cAll(FILE * file,int* caract, int* lines, int* word) {
	int co, com;
	
	while ((co = fgetc(file)) != EOF) {
		*caract += 1;
		if (co == '\n') {
			*lines += 1;
		}
		if (co == '\n' || co == ' ' || co == '\t') {
			if (com != '\n' && com != ' ' && com == '\t') {
				*word += 1;
			}
		}
		com = co;
	}
	return(0);
}

int main(int argc, char const *argv[]) {
	int n;
	FILE * fp = NULL;
	int l = 0;
	int p = 0;
	int w = 0;
	int v = 0;
	int n_caract = 0; 
	int n_lines = 0;
	int n_word = 0;
	
	
	/* point 1 */
	printf("Il y a %d arguments \n",argc);
	

	/* point 2 et 3 */
	for (n = 1; n < argc; ++n) {
		if (argv[n][0] == '-') {
			printf("Le premier argument commence par -\n");
			int j = 1;
			while (j < 5) {
				if (argv[n][j] == 'l') {
					l = 1;
				}
				if (argv[n][j] == 'p') {
					p = 1;
				}	
				if (argv[n][j] == 'w') {
					w = 1;
				}
				if (argv[n][j] == 'v') {
					v = 1;		
				}					
				j += 1;
			}
		}
		else {
			fp = fopen(argv[n], "r");
			if (fp == NULL){
				printf("Désolé la lecture du fichier %n n'a pas abouti... \n",argv[n]);
			}
			else {
				cAll(fp,&n_caract, &n_lines, &n_word);
				if (p == 1) {
					printf("Il y a %d caractères.\n",n_caract);
				}
				if (l == 1) {
					printf("Il y a %d lignes.\n",n_lines);
				}
				if (w == 1) {
					printf("Il y a  %d mots.\n",n_word);	
				}
				if ( l == 0 && p == 0 && w == 0) {
					printf("Il y a %d caractères.\n",n_caract);
					printf("Il y a %d lignes.\n",n_lines);
					printf("Il y a  %d mots.\n",n_word);
				}
				fclose(fp);
			}
		}
	}
	if (v == 1) {
		printf("La version de la fonction du programme est wc.\n");
	}
	return 0;
}

