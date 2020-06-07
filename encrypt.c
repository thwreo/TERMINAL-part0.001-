#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_number(int *n) {
	scanf("%d\n", n);
}
char **create_matrix( int number_of_lines) {
	char **matrix = malloc( number_of_lines * sizeof(char *) );
	int i;  
	for ( i = 0; i < number_of_lines; i++ ) {
		char line[200];
		fgets(line,200,stdin);
		line[strlen(line) - 1] = '\0';
		matrix[i] = malloc( strlen(line) * sizeof(char) );  //se aloca dinamic linia matricei (cu o lungime egala cu lungimea sirului introdus) - procedeu repetat pentru toate cele n linii
		strcpy(matrix[i], line);
	}
	return matrix;
}
void codify(char **matrix, int number_of_lines ) {
	int i, j;
	for ( i = 0; i < number_of_lines; i++ ) {
		char *copy_of_line = malloc((strlen(matrix[i]) + 1) * sizeof(char) );  
		strcpy(copy_of_line, matrix[i]);
		int ok = 1; //ajuta la afisarea primului cuvant, ulterior afisandu-se mai intai spatiu si apoi cuvantul
		char *word = strtok(copy_of_line, " ");
		while ( word != NULL) {
			int word_length = strlen(word);
			int check = 1; //verificator pentru "numere"
			for( j = 0; j < word_length ; j++) {
				if ( !(word[j] >= 48 && word[j] <= 57) )
					check = 0; //word nu reprezinta un numar
			}
			if ( check == 0) {
				for ( j = 1; j < word_length; j++) {
					if ( word[j] != 10) {
						word[j] = word[j] + word[0];			
					}
				}
			}
			if (ok == 1) { //daca "word" este primul cuvant din linie
				ok = 0;
				printf("%s",word );  //afisam doar "word"
			}
			else {
				printf(" ");
				printf("%s",word );
			}
			word = strtok(NULL, " ");
		}
		printf("\n");
	}
}
int main() {
	int n;
	char **text;
	read_number(&n);
	text = create_matrix(n);
	codify(text, n);
	return 0;
}