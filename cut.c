#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read(char del[], int *fields_dim, int fields[], char out_del[], int *matrix_dim ) {
	int i;
	fgets(del,11,stdin);
	scanf("%d",fields_dim);
	for ( i = 0; i < *fields_dim; i++) {
		scanf("%d,",&fields[i]);
	}
	scanf("%s",out_del);
	scanf("%d\n", matrix_dim);
}
void cut(int number_of_lines, char del[], int fields_dim, int fields[], char out_del[]) {
	char **matrix_of_pointers = (char **)malloc( number_of_lines * sizeof(char* ) );  //se genereaza liniile matricei
	int i, j;
	for ( i = 0; i < number_of_lines; i++) {
		int check = 1;  //verifica daca un cuvant va fi primul afisat (pentru a evita afisarea unor delimitatori la inceput de linie)
		char line[200];
		fgets(line, 200, stdin);
		matrix_of_pointers[i] = (char *)malloc( strlen(line) * sizeof(char) );  //se aloca memorie liniei "i" a matricei
		strcpy(matrix_of_pointers[i], line);
		char *word = strtok(matrix_of_pointers[i], del);  //cuvantul precedat de delimitatorul "del"
		int count = 0;
		while (word != NULL) {
			count++;
			for ( j = 0; j < fields_dim; j++) {
				if (count == fields[j]) {
					if (check == 1) {
						check = 0;
						printf("%s",word );  
					}
					else {
						printf("%s",out_del );
						printf("%s",word );
					}
					j = fields_dim;  //daca s-a gasit o valoare, nu se mai verifica si celelalte
				}
			}
			word = strtok(NULL, del);
		}
		printf("\n");
		
	}
}
int main() {
	char del[11], out_del[10];
	int fields[100],n, m;
	read(del, &n, fields, out_del, &m);
	cut(m,del,n,fields,out_del);
	return 0;
}