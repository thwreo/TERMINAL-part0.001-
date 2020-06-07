#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_lookup_string(char lookup_string[]) {
	fgets(lookup_string,30,stdin);
	lookup_string[strlen(lookup_string) - 1] = '\0';  //deoarece 'fgets' salveaza 'new line' ca ultim caracter al sirului(deci '\n' apartine astfel sirului), vom inlocui 'new line' cu terminatorul de sir
}
void read_number_of_lines(int *number_of_lines) {
	scanf("%d\n", number_of_lines);
}
char **create_matrix(int number_of_lines) {
	char **matrix_of_pointers = (char **)malloc( number_of_lines * sizeof(char* ) );
	int i;
	for ( i = 0; i < number_of_lines; i++) {
		char line[200];
		fgets(line, 200, stdin);
		matrix_of_pointers[i] = (char *)malloc( strlen(line) * sizeof(char) );
		strcpy(matrix_of_pointers[i], line);
	}
	return matrix_of_pointers;
}
void modify(char **matrix_of_pointers, int line_number, char lookup_string[]) {
	char *position_of_loookup_string = strstr(matrix_of_pointers[line_number], lookup_string);
	int count = 0;
	char *red_1 = "\e[0;31m", *red_2 = "\e[m";
	int red_dimension = strlen(red_1) + strlen(red_2) - 2;  //dimensiunea string-urilor "red_1" si "red_2" (adunate)
	while (position_of_loookup_string != NULL) {  //cautam aparitiile cuvantului "lookup_string" in linie si numaram de cate ori acesta este gasit
		count++;
		position_of_loookup_string = strstr(position_of_loookup_string + strlen(lookup_string), lookup_string);
	}
	int new_dimension = strlen(matrix_of_pointers[line_number]) + (red_dimension * count);
	matrix_of_pointers[line_number] = realloc(matrix_of_pointers[line_number], new_dimension * sizeof(char) );
	char aux_line[200];
	aux_line[0] = '\0';
	char *final_position = strstr(matrix_of_pointers[line_number], lookup_string);
	char *initl_position = matrix_of_pointers[line_number];
	while (final_position != NULL) {
		char *copy = strndup(initl_position, strlen(initl_position) - strlen(final_position));
		strcat(aux_line, copy);
		strcat(aux_line, red_1);
		strcat(aux_line, lookup_string);
		strcat(aux_line, red_2);
		initl_position = final_position + strlen(lookup_string);
		final_position = strstr(final_position + strlen(lookup_string), lookup_string);
	}
	char *copy = strdup(initl_position);
	strcat(aux_line, copy);
	if (aux_line[strlen(aux_line) - 1] != '\n') {  //daca "lookup_string" a aparut la finalul sirului => ultimul caracter al sirului este "m", NU endline, asadar marim dimensiunea cu un caracter pentru a aduga "\n" la finalul sirului
		aux_line[strlen(aux_line)] = '\n';
		matrix_of_pointers[line_number] = realloc(matrix_of_pointers[line_number], (new_dimension + 1) * sizeof(char) );
	}
	strcpy(matrix_of_pointers[line_number], aux_line);	
}
void grep(char **matrix_of_pointers, int number_of_lines, char lookup_string[]) {
	int i;
	for ( i = 0; i < number_of_lines; i++) {
		if (strstr(matrix_of_pointers[i], lookup_string) != NULL) {  //daca se gaseste cuvantul "lookup_string" in linia "i" a matricei
			modify(matrix_of_pointers, i, lookup_string);  			//se apeleaza functia "modify" pentru a colora toate aparitiile cuvantului "lookup_string" in linia "i" a textului
			printf("%s", matrix_of_pointers[i] );
		}
	
	}
}
int main() {
	int n;
	char lookup_string[30], **text;
	read_lookup_string(lookup_string);
	read_number_of_lines(&n);
	text = create_matrix(n);
	grep(text, n, lookup_string);	
	return 0;
}