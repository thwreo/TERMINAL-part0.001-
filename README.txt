			CERINTA 1
- se citeste numarul de linii al textului, utilizand o functie ("read_number")
- se citesc liniile textului, ce se introduc intr-o matrice de pointeri, alocata dinamic; acestea se realizeaza cu ajutorul functiei "create_matrix"
- functia "modify" coloreaza cu rosu toate cuvintele de tipul "lookup_string" din linia "line_number" a matricei "matrix_of_pointers":
	*initializam un pointer ce indica spre prima aparitie a cuvantului pe care vrem sa il coloram ("lookup_string");
	*initializam un intreg (are valoarea "0" la inceput) "count"
	*ne deplasam prin linie cautand aparitiile cuvantului "lookup_string", numarandu-le cu ajutorul variabilei "count"
	*introducem o variabila "new_dimension" ce reprezinta noua dimensiune pe care dorim sa o aiba linia matricei, aceasta fiind egala cu suma dintre lungimea initiala a liniei si numarul de aparitii al cuvantului inmultit cu dimensiunea celor doua string-uri ce se vor introduce inainte si dupa cuvantul pe care vrem sa-l coloram
	*realocam memorie liniei (adica noua dimensiune "new_dimension")
	*initializam un sir "aux_line", al carui prim element este chiar terminatorul de sir
	*ne ajutam de doi pointeri, initial "final_position" indica spre pozitia primei aparitii a cuvantului, iar "initl_position" indica spre inceputul sirului
	*ne deplasam prin linie cu ajutorul pointerului "final_position" (care mereu se va deplasa la urmatoarea aparitie a cuvantului de colorat, pana acesta nu mai apare, adica pana devine "NULL"), intitl_position indicand spre pozitia anterioara a lui "final_position"
	*in "copy" se afla sirul delimitat de cei doi pointeri; liniei auxiliare i se aduga in ordine: "copy", primul string ce precede cuvantul pe care vrem sa-l coloram (unul din stringurile specifice culorii "red"), cuvantul pe care vrem sa-l coloram, stringul ce vine dupa cuvantul dorit (al doilea ce ajuta la colorarea cuvantului);
	*la final se copiaza tot ce se afla dupa ultima aparitie a cuvantului "lookup_string" in linie si finalul acesteia
	*daca dupa ultima aparitie a cuvantului dorit urmeaza finalul liniei,ultimul caracter al sirului este "m", NU endline, asadar marim dimensiunea liniei cu un caracter  pentru a aduga "\n" la finalul sirului 
	*copiem linia auxiliara in linia propriu-zisa a matricei
-functia "grep" verifica aparitia lui "lookup_string" (cuvantul pe care vrem sa il coloram) in fiecare linie a textului nostru; daca acesta apare, se apeleaza functia "modify" pentru linia respectiva si dupa se afiseaza linia nou formata a textului(matricei)
- in main: 
	*se citeste cuvantul pe care vrem sa il coloram in text
	*se citeste numarul de linii al textului
	*se citeste/formeaza matricea "text"
	*se apeleaza functia "grep"


			CERINTA 2
- se citesc (in ordine): delimitatorul de referinta (cel prezent in text, pe care il vom inlocui), numarul coloanelor pe care vrem sa le afisam, indicii coloanelor (separati prin ","), delimitatorul dorit, numarul liniilor textului (functia "read")
- functia "cut":
	*citim/generam matricea (textul)
	*ne deplasam din cuvant in cuvant, in functie de delimitatorul de referinta, inregistrand indicele coloanei pe care se afla "word" (cu ajutorul lui "count")
	*daca indicele coloanei pe care se afla cuvantul se regaseste in vectorul "fields" (ce are indicii coloanelor ce vor fi afisate ), atunci se verifica daca "word" este primul cuvant din linie ce trebuie tiparit
	*printam coloanele dorite delimitate de noii marcator
- in main:
	*se apeleaza functia "read"
	*se genereaza/citeste textul, prin functia "cut" si se afiseaza coloanele dorite, despartiel prin delimitatorul ales

			
			CERINTA 3
- se citeste numarul de linii al matricei mediilor
- se citeste/genereaza matricea de pointeri (liniile sunt formate din intregi): se aloca pentru fiecare linie la inceput o dimensiune de "3", ulterior, daca este necesar, realocandu-se "+3"; citirea unei linii se opreste la intalnirea intregului "0"
- se calculeaza suma unei anumite linii a matricei
- se calculeaza media de pe o linie a matricei (se numara cati intregi sunt pe o linie - "0" nu se numara - si se apeleaza functia "sum"; impartim rezultatul functiei "sum" la numarul de intregi - "count" -)
- functia "sort" (~bubble sort~) ordoneaza descrescator liniile in functie de medie; interschimbarea liniilor se realizeaza cu ajutorul unui pointer auxiliar (de fapt, se schimba directia spre care indica pointerul "matrix[i]" cu directia spre care indica pointerul   "matrix[i+1]")
- se printeaaza liniile (alineat la stanga, pe 10 spatii - se adauga "-10" -), la inceput media, urmata de note

			
			CERINTA 4
- se citeste numarul de linii
- se genereaza/citeste matricea de pointeri
- pe fiecare linie a matricei (apeland functia "codify"):
	*se face o copie a liniei "i" (alocata dinamic)
	*ne deplasam cu "word" prin fiecare cuvant al liniei
	*verificam daca intr-un cuvant se afla caractere diferite de cifrele "0-9" (cu ajutorul variabilei "check" ce va deveni "0" daca respectivul cuvant contine caractere diferite de cifre)
	*daca "check" este "0", atunci incepem codificarea cuvantului
		~dimensiunea cuvantului "length_of_word"
		~incepand cu al doilea caracter al cuvantului, adauga codului sau ASCII codul ASCII al prmului cuvant (reprezinta cheia mod 256)
		~verificam daca "word" este la finalul sirului, daca acesta este, nu codificam ultimul caracter (intrucat acesta este "new line"), daca nu se afla la finalul sirului, atunci il codificam
	*vedem daca "word" este primul caracter din linie; daca da, atunci afisam doar cuvantul codificat sau numarul; daca nu, afisam "spatiu" si cuvantul codificat/numarul
	*dupa afisarea unei linii, printal "new line"
