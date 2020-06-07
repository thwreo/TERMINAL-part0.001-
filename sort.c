#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_number(int *n) {  //se citeste numarul de linii al matricei
	scanf("%d",n);
	free(n);
}
int **read_matrix(int n) {  //se citeste/genereaza matricea
	int **matrix = (int **)malloc(n * sizeof(int *));  
	int dim = 3, i;
	for ( i = 0; i < n; i++ ) {
		int aux = 0;
		matrix[i] = (int *)malloc(dim * sizeof(int)); //se aloca memorie vectorului de intregi 
		scanf("%d", &matrix[i][aux]);
		while ( matrix[i][aux] != 0 ) {  //se citesc intregi pana la introducerea valorii '0', variabila 'aux' reprezinta dimenisunea vectorului totala (incluzand valoarea '0')
			aux++;
			if (aux == dim) {
				dim += 3;
				matrix[i] = realloc(matrix[i],dim * sizeof(int));  //se realoca memorie vectoruli de intregi
			}
			scanf("%d", &matrix[i][aux]);
		}
	}
	return matrix;
}
int sum(int **matrix, int line) {  //suma unei anumite linii a matricei
	int collumn = 0; //variabila reprezinta indicele 'coloanei' (sau indicele blocului din vectorul de intregi matrix[line]); creste pana la intalnirea valorii '0'
	int sum = 0;
	while ( matrix[line][collumn] != 0 ) {  
		sum+=matrix[line][collumn];
		collumn++;
	}
	return sum;
}
float average(int **matrix, int line) {
	int count = 0, aux = 0;
	while ( matrix[line][aux] != 0 ) {
		count++;  //calculeaza numraul valorilor intregi (diferite de '0') in vector 
		aux++;
	}
	float average = sum(matrix, line) / (count * 1.0f ); //fara inmultirea lui 'count' (numarul valorilor intregi diferite de '0') cu valoarea '1' de tip float, operatorul '/' transforma valoarea impartirii intr-un intreg
	return average;
}
void sort(int **matrix, int nmb_lines) {  //bubble sort
	int check = 0, i, *p;
	while (!check) {
		check = 1;
		for ( i = 0; i < nmb_lines - 1; i++ ) {
			if ( average(matrix, i) < average(matrix, i + 1) ) {  //in cazul in care media aritmetica a unei linii cu un anumit indice este mai mica decat a unei linii de indice mai mare, se realizeaza interschimbarea liniilor
				check = 0;
				p = matrix[i];  //se initializeaza un pointer auxiliar ce indica spre adresa liniei 'i' din matrice
				matrix[i] = matrix[i + 1];  //  matrix[i] va indica spre adresa liniei 'i+1'
				matrix[i + 1] = p; // matrix[i+1] va indica spre adresa pointer-ului auxiliar, adica adresa liniei 'i' 
			}
		}
	}
	free(p);
}
void print(int **matrix, int nmb_lines) {
	int i;
	for ( i = 0; i < nmb_lines; i++ ) {
		int aux = 0;
		printf("%-10.3f", average(matrix, i) );
		while ( matrix[i][aux] != 0 ) {
			printf("%d ",matrix[i][aux] );  // '-' aliniaza spre stanga output-ul
			aux++;
		}
		printf("\n");
	}
}
int main(){
	int n, **notes,i;
	read_number(&n);
	notes = read_matrix(n);
	sort(notes,n);
	print(notes, n);
	for ( i = 0; i < n; i++)
		free(notes[i]);
	free(notes);
	return 0;
}