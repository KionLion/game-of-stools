#include <stdio.h>
#include <stdlib.h>

int Caract(FILE * file) {
	int i;
	int co = 0; 
	
	while ((i = fgetc(file)) != EOF) {
		co += 1;
	}
	return(co);
}

int Lines(FILE * file) {
	int i;
	int co = 0; 
	int com = 0;
	
	while ((i = fgetc(file)) != EOF) {
		com +=1;

		if (i == '\n') {
			co += 1;
		}
	}

	return(com);
}

int Word(FILE * file) {
	int i,j=0;
	int co = 0; 
	
	while ((i = fgetc(file)) != EOF) {
		if (i == '\n' || i == ' ' || i == '\t') {
			if (j != '\n' && j != ' ' && i == '\t') {
				co += 1;
			}
		}
		j = i;
	}
	return(co);
}


int main(int argc, char const *argv[]) {
	int i;
	FILE * fp = NULL;
	int n_lines = 0;
	int n_caract = 0; 
	int n_word = 0;
	
	/* point 1 */
	printf("Le programme a %d arguments \n",argc);
	

	/* point 2 et 3 */
	for (i = 1; i < argc; ++i) {
		if (argv[i][0] == '-') {
			printf("Le premier argument commence par -\n");
		}
		else {
			fp = fopen(argv[i], "r");
			if (fp == NULL){
				printf("La lecture du fichier %s n'a pas abouti...\n",argv[i]);
			}
			else {
				/*printf("Le fichier %s peut etre lu\n",argv[i]);*/
				n_caract = Caract(fp);
				printf("Il y a %d caractères.\n",n_caract);
				fclose(fp);
				fp = fopen(argv[i], "r");
				n_lines = Lines(fp);
				printf("Il y a %d lignes\n",n_lines);
				fclose(fp);
				fp = fopen(argv[i], "r");				
				n_word = Word(fp);
				printf("Il y a %d mots\n",n_word);
				fclose(fp);
			}
		}
	}
	return 0;
}
	

