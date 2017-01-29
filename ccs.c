 /* Vorbereitung VO Einführung in die Programmierung WS 2016/2017
 _______________________________________________
|				Aufteilung Klausur			 	|
|												|
|	  Theorie   - 10 Punkte						|
|	  Schwerpunkt Programmierkonzepte			|
|												|
|	  Aufgabe 1 - 10 Punkte						|
|	  Eher Einfache Aufgabe 					|
|												|
|	  Aufgabe 2 - 10 Punkte						|
|												|
|	  Hints:									|
|	  For loop in while loop					|
|	  Kurztests									|
|	  Kein Debugging							|
|	  Keine Makefiles							|
|	  String-Funktionen							|
|												|
|	  Eigner Rechner erlaubt					|
|	  PS Unterlagen und VO Folien erlaubt		|
|_______________________________________________|*/

/*______________________________________________
|												|
|         Table of Content:						|
|												|
| 1.  Basics:									|
|		1.0 Hello World							|
|		1.1 Compile								|
|		1.2 Librays								|
|		1.3 Variablen & Datentypen 				|
|			1.3.1 Char Beispiele 				|
|			1.3.2 Bool 							|
|			1.3.3 Literale						|
|			1.3.4 Enum 							|
|			1.3.5 Konstanten					|
|			1.3.6 Globale Variablen 			|
|		1.4 Printing							|
|		1.5 Operatoren & Ausdrücke				|
|		1.6 Kontrolstrukturen					|
|			1.6.0 If & Switch 					|
|			1.6.1 Schleifen 					|
|		1.7 Funktionen							|
|												|
| 2.  Pointer									|
|												|
| 3.  Arrays									|
|												|
| 4.  Struct Unions Bitfelder					|
|												|
| 5.  Dynamische Speicherverwaltung				|
|												|
| 6.  Speicherklassen							|
|												|
| 7.  Eingabe & Ausgabe							|
|		7.1 Strings								|
|												|
| 8.  Commandozeilenparameter					|
|												|
| 9.  Präprozessor								|
|												|
| 10. Listen					    			|
|												|
| 11. Code Snippets					    		|
|_______________________________________________|*/

//1. Basics
void Basics(){


	struct 1.0 Hello World{

		#include <stdio.h>
		#include <stdlib.h>

		int main(int argc, char** args)
		{
			printf("Hello World\n");
			return EXIT_SUCCESS;
		}
	}

	struct 1.1 Compile{

		// gcc -Wall -Werror -std=c99 prog.c -o. prog 
	}

	struct 1.2 Librarys{

		#include <sdtio.h>
		#include <stdlib.h>
		#include <math.h>
		//Boolesche Variablen
		#include <stdbool.h>
		//Größen der Datentypen
		#include <limits.h>
		#include <float.h>
		#include <stdint.h>
		//String Funktionen
		#include <string.h>
		//Definitionen von Makros
		#include <stddef.h>
		//Tests für Zeichenklassen
		#include <ctype.h>
		//Zeit und Random
		#include <time.h>
	}

	struct 1.3 Variables{

		struct 1.3.0{
			//Variablennamen dürfen aus groß, kleinbuchstaben, nummern und _ bestehen. Nummer darf nicht am Anfang stehen.
			//Declaration - art der Varibale wird festgelegt (keine wertzuweisung)
			int var;
			//Definition - art der Variable wird festgelegt und Speicherplatz wird reserviert
			int var = 1;

			//Datentyp  									Bitanzahl
			//Zeichen oder Ganzzahlen
			char (signed char)									8
			unsigned char										8
			//Ganzahlige Werte mit Vorzeichen
			int (signed int)									32
			unsigned int										32
			//Wertebereich maximal so groß wie int
			short (short int)									16
			unsigned short (unsigned short int)					16
			//Wertebereich mindestens so groß wie int
			long (long int)										32(64)
			unsigned long (unsigned long int)					32(64)

			long long (signed long long int)					64
			unsigned long long (unsigned long long int)			64
			//Gleitkommazahlen einfache Genauigkeit
			float												32
			//Gleitkommazahlen doppleter Genauigkeit
			double												64
			//double mit erweiterter Genauigkeit
			long double											128

			//Für char und ganzzahlige Datentypen kann signed & unsigned verwendet werden.
			//signed - Standard, Wertebereich negativ und positiv
			//usigned - kein Vorzeichen möglich, positiver Wertebereich wird größer
		}

		struct 1.3.1 Char Beispiele{
			char var = ' ';
			char var = 66;		//Maxwert 255
			char var = 0x42;	//Hex 42 = Dec 66
			char var = '\x42'	//hexadecimal character escape
		}


		struct 1.3.2 Bool{
			//Bool (stdbool.h)
			bool var = true;
			bool var = false;

			//funktioniert ohne stdbool.h
			_Bool var = 1;
			_Bool var = 0;
		}


		struct 1.3.3 Literale{
			"Foliensatz 04 Seite 25"
			//
		}


		struct 1.3.4 Enum{
			enum direction {North = 1, South = 2, East = 3, West = 4};
			enum direction s = South;
		}

		struct 1.3.5 Konstanten{
			#define PI 3.14 //PI wird textuel vom Präprozessor ersetzt (keine Typüberprüfung)
			const double pi = 3.14; //konsante Variable (wert kann nicht verändert werden)
		}

		struct 1.3.6 Globale Variablen{
			//Gibt es eine lokale und globale Variable mit dem selben Bezeichner wird die lokale verwendet.
			//Globale Variablen werden automatoisch initialisiert;
		}
	}

	struct 1.4 Printing{
		"Foliensatz 04 Seite 29"

		//printf(Formatstring, Parameterliste)
		//%[flags][weite][.genauigkeit][modifizierer]typ

		//flags - -/+ leerzeichen
		//weite - füllt mit leerzeichen auf
		//genauigkeit - füllt mit nullen auf
		//modifizierer - spezifiziert typ

		//Beispiele:
		int var = 4;
		printf("%.4d\n", var);
		//Output 0004
		printf("%10i\n", var);

		//%i und %d sind für output genau gleich, jedoch beim input mittels scanf erlaubt %i die eingabe von hex bzw. octal werten.
		int var = 0;
		int var2 = 0;
		printf("NUM1: HEX and OCTAL allowed. 0x42, 032\n");
		scanf("%i",&var);
		printf("NUM2: NO HEX and OCTAL\n");
		scanf("%d",&var2);
		printf("%d\n%d\n",var,var2);
	}

	struct 1.5 Operatoren und Ausdrücke{
		"Foliensatz 05 Seite 2" - Einführung
		"Foliensatz 05 Seite 19" - Assoziativtät

		_Bool A = 1;
		char B = 'B';
		char C = 'C';

		//wenn a == 0 dann C
		//wenn a != 0 dann B
		char D = A ? B : C;
		printf("%c\n",D);

		//sizeof
		sizeof(); printf("%zu\n",size_t);
	}
	 
	struct 1.6 Kontrollstrukturen{
		
		struct 1.6.0 If & switch{
			//if
			if(var == 0){
				var++
			}else if(var == 1){
				var--;
			}else{
				var
			}

			//switch
			switch(var){
				case 0:
					var++;
					break;
				case 1:
					var--;
					break;
				default:
					var;
					break;
			}
		}

		struct 1.6.1 Schleifen{
			//while
			while(){
			}

			//do while
			do{
			} while();

			//for
			for (int i = 0; i < n; i++){
			}

			break; //bricht aus schleife aus. (Bei doppelter schleife nur aus der innersten)
			continue; //springt zum schleifendurchlauf
			goto; //springt zu punkt - nimmt keine sau
		}
	}

	struct 1.7 Funktionen{
		//Prototype
		int supercoolfunction(int parameter, char parameter2);

		//Function
		int supercoolfunction(int parameter, char parameter2){
			return 5;
		}

		//Aufruf
		supercoolfunction(12,'C');

		//Rekursion
		//Funktion ruft sich selbst auf
		int rek(int a, int b){
			if (a < 0){
				return b;
			}else{
				rek(a--,b++);
			}
		}

		//Endrekursiv
		//letzer Auruf ist rekursiv

		//Stack Overflow bei zu vielen rekursiven Aufrufen!
	}	
}

//2. Pointer
void Pointer(){

	int* pointer;
	int *pointer;	
	// Ohne Zuweisung zeigen sie auf zufällige Speicherstelle
	// Nichtverwendete Pointer zunächst mit NULL initialisieren

	//Beide zeigen auf die gleiche Speicherstelle
	pointer1 = pointer2;

	int counter = 1;
	//& - liefert einen Pointer auf die Speicherstelle von counter (vom Typ pointer auf int)
	int* pointer = &counter;

	//Printing
	%p 					// gibt die Adresse der Speicherstelle zurück			

	//Beispiel:
	int* pointer,pointer2;
	pointer = &pointer2;


	%p 		pointer 	--> Adresse von pointer2
	%p 	   &pointer 	--> Adresse von pointer
	%p 		pointer2 	--> Adresse von pointer2

	%i     *pointer     --> Integer Wert der Adresse

	// Dereferenzierungsoperator(Inhaltsoperator) - Direkter Zugriff auf Inhalt

									//	Zuweisung von Werten über Pointer mit Inhaltsoperator
	int counter = 1;
	int counter2;
	int* pointer;

	pointer = &counter;
	*pointer = 5;
	counter2 = *pointer;			// 	Beide variablen counter + counter 2 haben am Ende den Wert 5


	*pointer = *pointer +1
	//entspricht
	counter = counter+1


	*&value 	
	//entspricht 
	value



	// Arrays und Pointer

	// Array belegt einen Speicherplatz nach seiner Instanzierung, entspricht Adresse des ersten Elements
	// Pointer muss ein Speicherplatz zugewiesen werden

	alpha[0] oder alpha* 		// Zugriff auf das erste Element
	alpha[i] oder *(alpha +i) 	// Zugriff auf das ite Element

	// pointerarithmetik: Addition und Subtraktion von Pointern mit Integers
	ptr = ptr + 2; 		// Pointer wurde um die Länge von 2 Elementen des entsprechenden Datentyps erhöht
	ptr1 - ptr2 = 		// Gibt die Anzahl der Elemente zwischen den Pointern zurück


	// Vergleiche von Pointern erlaubt bei: gleichem Typ oder Null-Pointer
	//Pointer Arrays

	int* counters[10]; 		// Alternative zu zweidimensionalen Arrays
	char numbers[10][50];	// Reserviert 500 Bytes, egal ob einige Stellen leer sind
	char* numbers[10];		// Reserviert für jeden String den benötigten Speicherplatz

	// Beispiel:
	int arr[4][2];

	arr 				-->			Adresse der ersten Zeile des Arrays
	arr + 2 			--> 		Adresse der dritten Zeile des Arrays
	*(arr + 2)			--> 		Adresse des ersten Elements der dritten Zeile
	*(arr + 2) +1		--> 		Adresse des zweiten Elements der dritten Zeile
	*(*(arr + 2) +1) 	--> 		Wert    des zweiten Elements der dritten Zeile


	// Pointer  auf Arrays
	int (*ptr)[10];			// Pointer auf ein Array von 10 Integern
	int *ptr [10];			// Array mit 10 Integer pointern


	// Mehrdimensionale Arrays in C nur simuliert


	// Pointer auf Pointer 			Haupteinsatzgebiet: Dynamische Erzeugung von mehrdimensionalen Arrays
	char** textpointer;				// Pointer zeigt auf Pointer zeigt auf Variable, oder endlos weiter auf Pointer
	//entspricht
	char* textpointer[];

	// Mehrdimensionale Arrays bei Funktionen


	void f(int (*p)[4]);
	//entspricht
	void f (int p[][4]);



	// Pointer auf Void

	void* ptr;						// kann nicht dereferenziert werden
									//untypisierter generischer Pointer, kompatibel zu allen anderen Pointern
									// in einem späteren Zeitpunkt Umwandlung in explizten Typ möglich



	// Typ Qualifizierer
	// const

	int* const constant_pointer;		// zeigt immer auf dieselbe Adresse, referenzierte Wert darf verändert werden

	int const *constant_pointer;		// Pointer darf verändert werden, die Daten aber nicht

	int const * const constant_pointer;	// konstanter Pointer auf Konstante Daten

	// volatile							// vor jedem Zugriff Wert neu ausgelesen

	// restrict							// bestimmtes Element nur über diesen restrict Zeiger zugreifbar


	// Main function parameter

	int main
	(
	int argc		//	(argument counter)	 Wenn größer als 1, enthalten   argv[1]    bis   argv[argc -1]   Programmparameter
	char **argv	 	//	(argument vector)	 Array vbon Zeiger auf char
	)				
					// Parameter sind Zeichenketten und müssen mit Funktionen umgewandelt werden
					// old: atoi, atol, atof
					// new: strtol, strtoul, strtod

	// Pointer auf Funktionen

	// Man kann einen Pointer auf eine Funktion vereinbaren und diese mit dem Dereferenzierungsoperator (*) aufrufen.
	// Man kann auch Funktionen als Parameter für andere Funktionen übergeben

	int (*ptr) (char); 		// Pointer auf eine Funktion mit Rückgabewert int und Parameter char.

	// Beispiel Hello World:
	int (*fptr)(const char*,...);
	fptr = printf;
	(*fptr)("Hello World\n");

	// Zeiger auf Funktionen können in einem Array gespeichert werden und durch Index aufgerufen werden
}

//3. Arrays
void Arrays(){

	int array[5]; 					// Der Compiler legt mit malloc/calloc Speicherplatz an
	array [2] = 10;
	array[5] = 1; 					// Overflow
	char array[] = {'A','B','C'} 	// Längenangabe kann weggelassen werden
	double array[4] = {1.0,44.7} 	// Rest wird mit Nullen aufgefüllt
	const int array[];				// Werte können nicht verändert werden
	void fun (arr[]);				// Bei Übergabe eines Arrays an eine Funktion wird nur die Anfangsadresse übergeben.
	
	print_array((int[]){1,2,3}, MAX)//C99 Array printing

	// Zwei Arrays können nicht mit arr1 = arr2 überprüft werden, sondern mit Hilfe einer Schleife
	int size = sizeof(array) / sizeof(int);

	int mdarray[3][4];				// Mehrdimensionale Arrays mdarray = 3 Zeilen 4 Spalten

	int mdarray[3][4] = { {1}, {2,4} };    	// Matrix: 1 0 0 0
											//         2 4 0 0
											//		   0 0 0 0
											//	mdarray[1][0] hat Wert 2 ->	 Zeile 2 Spalte 1 (Indizes starten von 0)
	
	char string[] = "Hello";				// Strings in C als Character Arrays, 
	char string[5] = {'H','e','l','l','o'};	// letztes Element \0 (0 Byte), array automatisch 1 wert größer als angegeben			
	strlen, strcpy, strcmp					// Funktionen zur Bearbeitung von strings in string.h library
}

//4. Structs, Unions & Bitfelder 	
void Structs_Unions_Bitfelder(){

	//STRUCTS

	// Strukturen sind Ansammlung von mehreren Variablen die unter einem einzigen Namen zusammengefasst werden
	// Die Variablen können auch verschiedene Typen haben. Structs dienen der Organisation von Daten.
	// Beispiel:

	struct point{				/*oder*/			struct point {			
		int x;											int x;
		int y;											int y;
	};												} pt;

	struct point pt;

	// Zugriff auf die Variablen im Struct
	int value = pt.x;

	// Initialisierung
	struct point maxpt = {150,300}; // Es können auch einzelne Initialisierer freigelassen werden
	// Strukturen können: anderen Strukturen vom selben Typ zugewiesen werden
						//Rückgabe und Übergabe an Funktionen
						// Ermittlung der Adresse mit dem Adressoperator &
						// Ermittlung der Größe mit dem sizeof-Operator
						// Für Vergleiche müssen eigene Funktionen geschrieben werden!
	//Zeiger auf Strukturen können verwendet werden um auf den Inhalt einer Struktur zuzugreifen z.b. Print Funktion
	struct person *p1;
	p1->y 	// Zugriff über Pfeil Operator, (*p1).name auch möglich aber Pfeil Operator besser.
	
	// Übergabe als Parameter (Rückgabe einer Funktion funktioniert auch)
	// Variante 1: Einzelne Elemente Übergeben 
	fun(pt.x);
	// Variante 2: Gesamtes Struct übergeben (langsamer und verbraucht mehr Platz, aber sicherer)
	void fun(struct person p);
	// Variante 3: Zeiger auf Struct übergeben (Schnellere Variante, aber könnte verändert werden. Lösung: const)
	void fun(struct person p*);

	// Array von Structs wird oft für die Speicherung zusammenhängender Daten verwendet. Beispiele: "Foliensatz 13 S. 14+15"
	int val = p1[i].x;

	// Verwendung von zusammengesetzte Literalen
	(struct person){"Hans Wurst", "Straße 4, 6020 IBK"}

	// Man kann auch Strukturen in Strukturen verschachteln

	struct dog {
		int age;
	}

	struct animals{
		dog dogs;
		char cats[20];
	}

	// In Strukturen können auch Zeiger verwendet werden (Elemente sollten aber auf dynamisch allokierten Speicherplatz zeigen)

	//TYPEDEF
		//Erstellung eines neuen Typnamens. Bringt Portabilität, Verständlichkeit ~
		// Beispiele:
	typedef unsigned long un64;
	typedef struct treenode tn;

	typedef struct person{
		char username[8];
		char password[8];
		int uid;
	} user;

	user admin = {"Klaus","123",1};

	//UNIONS
		// Kein Unterschied zu Structs außer dem Schlüsselwort und dem Umgang mit den Daten.
		// Eine Union ist eine Variable die zu verschiedenen Zeitpunkten Objekte mit verschiedenen Datentypen und Größen enthält.
		// Mit unions kann man sich Speicherplatz sparen.
		// Man kann aber immer nur 1 Wert speichern z.B. im folgenden Beispiel entweder ival oder fval oder cval;
	
	union u_tag{
		int ival;
		float fval;
		char *cval;
	} u;

	//BITFELDER
		// Einzelne Elemente einer Struktur oder einer Union können als Bitfelder deklariert werden.
		// Diese Elemente bestehen aus einer ganzzahligen Variable die wiederum aus einer bestimmten Anzahl von Bits besteht.
		// Anwendungssinn: Einsparung von Speicherplatz, Zugriff auf Hardware

		// Typ muss ganzzahlig sein
		// Mit dem Bezeichner Elementname greift man auf das Element zu
		// Breite gibt Anzahl der Bits an
	typedef struct time{
	//  Typ Elementname : Breite
		unsigned int hour:5;
		unsigned int minute:6;
	}time_t;

	time_t time_now;
	time_now.hour = 12;
	
		// Bitfelder können keine adressierbaren Speicherstellen belegen , kein scanf, kein Array von Bitfeldelementen;
		// Die Anordnung der Bits im Speicher ist nicht standardisiert
		// Zugriff langsamer als auf herkömmliche Datentypen
}

//5. Dynamische Speicherverwaltung
void Dynamische_Speicherverwaltung(){

	// Speicherplatz dynamisch zur Laufzeit anfordern ist effizienter als ein übergroßes Array zu erstellen

	size_t 						// Vorzeichenloser Ganzzahltyp

	// MALLOC
	void *malloc(size_t size)	// Reserviert size Bytes am Heap, liefert die Anfangsadresse des Speicherbereichs oder NULL bei Fehler.
	// Beispiel:
	size_t max_numbers = 10;
	double *numbers = malloc (max_numbers * sizeof(*numbers));
	
	// CALLOC
	void *calloc(size_t nmeb, size_t size) // Unterschied zu malloc: reservierter Speicher wird mit 0 initialisiert und benötigt mehr Zeit
	//Beispiel:
	iptr = (int*) calloc(n,sizeof(*iptr));
	
	// REALLOC
	void *realloc(void *ptr, size_t size)  // Möglich den reservierten Speicherplatz während der Laufzeit anzupassen.
								// Zuerst wird die Größe des durch ptr adressierten Speicherblocks verändert (dieser muss auch dynamisch erzeugt worden sein).
								// Es wird ein Zeiger auf die Anfangsadresse des reservierten Speicherblocks mit größe size zurückgegeben.
								// Der ursprüngliche Inhalt bleibt erhalten.
								// Möglichst selten verwendn, Umkopieren aufwändig
								// Speicher kann auch verkleinert werden, hintere Abschnitt des ursprünglichen Blocks wird freigegeben
	ptr = realloc(NULL, size) /*entspricht*/ ptr = malloc(size)
	//Beispiel:
	int *numbers = calloc(8, sizeof(*numbers));
	numbers = realloc(numbers, max * sizeof(*numbers));
	
	

	// FREE
	void free(void *ptr); 		// Nicht benötigter Speicher muss immer freigegeben werden
								// Der übergebene Zeiger muss auf einen Speicher zeigen der vorher reserviert wurde (durch die obigen Funktionen).
								// free setzt den Zeiger nicht auf NULL, sollte programmiert werden sonst undefiniertes Verhalten

	// HEAP: Bei der dynamischen Speicherverwaltung kommt der Speicher vom Heap, wird dynamisch zugewiesen bis free aufgerufen wird.
	//       Bei einer Speicheranforderung wird ein zusammenhängender Block angefordert. Durch anfordern und freigeben kann es zu einer Fragmentierung kommen.
	//       Speicherreservierungen möglichst sparsam einsetzten. 
 	
 	alloca()	// Diese Funktion fordert den Speicher vom Stack an.

 	// Beispiel mehrdimensionales Array (Foliensatz 11 S. 22)
 	// Als erstes wird der Speicherplatz für die Zeilen (erste Dimension []) und anschließend für die Spalten (zweite Dimension []) reserviert
 	// Das freigeben geschieht in der umgekehrten Reihenfolge
}

//6. Speicherklassen
void Speicherklassen(){

	// Adressräume von Variablen und Funktionen

	// Codesegment: Maschinencode des Programms
	// Datensegment: globale (externe) Variablen
	// Stack: 	Lokale Variablen, Rücksprungadresse, Parameter einer Funktion
	// Heap:    Dynamische Variablen 

	//Gültigkeitsbereiche von Variablen und Funktionen

	// Anweisungsblock: 	Nur unnerhalb des Blocks zugänglich
	// Funktionsprototyp: 	Variablen innerhalb eines F-Prototys gelten nur bis zum Ende der Funktion
	// Datei/Modul: 		Speicherobjekte außerhalb einer Funktion können ab Definition bis Dateiende verwendet werden
	// Funktion: 			Labels sind innerhalb einer Funktion überall sichtbar

	// Lebensdauer

	// Autopmatische Lebensdauer
		// Klasse von Speicherobjekten die zur Ausführungszeit einer Funktion/Block definiert sind. 
		// Stack Frame wird angelegt und am Ende wieder geleert.

	// Statische Lebensdauer
		// Speicherobjekte die zur gesamten Programmlaufzeit einen festen Platz haben
		// Statische Speicherobkekte werden nicht in einem Stack Frame sondern im Datensegment des Progs gespeichert.

	// Speicherort: Speicherobjekt kann im Speicher oder Prozessorregister gehalten werden. 
	             // Es wird zwischen Datensegment und Stack unterschieden

	// Bindung: 	Extern: Speicherobjekt kann überallin einem Programm (auch mehrere Dateien) verwendet werden
				//  Intern: Speicherobjekt kann nur in derselben Datei verwendet werden, in der es definiert ist.
				//	Keine:  Lokale Variablen


	auto int i = 2;	// Spezifizierer "auto" nur für lokale Variablen. Automatisch Standard von lokalen Variablen in Blöcken.
					// auto - Variablen sind nur in diesem Block verfügbar und müssen explizit initialisiert werden

	register int i = 0; // Schlüsselwort wird bei Variablen verwendet um es so lange wie möglich im Prozessorregister zu halten.
						// Kann nicht mit dem Adressoperator zugegriffen werden, ansonsten gleiche Eigenschaften wie auto-Variable.

	static int b = 2;   // Variable in Funktion: Der Wert der lokalen Variable bleibt nach der Rückkehr aus einer Funktion erhalten. 
					    // Kann trotzdem nur lokal angesprochen werden.
					
	static fun();	    // Funktion oder globale Variable: Sichtbarkeit auf die aktuelle Datei beschränkt.  Bsp: Funktion mit selben Namen in verschiedenen Dateien möglich.

	extern int a; 		// Mit extern kann man auf ein Speicherobjekt außerhalb der Datei zugreifen. (Compiler gibt Linker bescheid)
						// Variable: Es wird keine neue Variable definiert sondern eine bereits definierte wird deklariert.
						// Funktion: Funktion global in allen Dateien sichtbar.

						// Kurzfassung: Foliensatz 10 S. 16
}

//7. Eingabe & Ausgabe (I/O)
void Eingabe_Ausgabe(){
	
	// Ein und Ausgabe ohne File
		// Ausgabe auf STDOUT
		printf("%i\n", var);

		// Einlesen von STDIN
		scanf("%i\n",&var);
		
	// stdio.h Library für Ein und Ausgabe. "Foliensatz 15 Seite 8" Überblick über alle wichtigen I/O Funktionen
	// Man unterscheidet: 
		// Textströme: 		Folge von Zeilen, Zeile endet mit Zeilentrenner \n
		// Binäre Ströme: 	Byte für Byte verarbeitet
	
	// Um nicht immer Zeichen für Zeichen übertragen zu müssen gibt es Pufferung:
		// Vollgepuffer:	Zeichen werden übertragen wenn der Puffer voll ist (4096 Bytes)
		// Zeilengepuffert: Zeichen werden übertragen wenn eine neue Zeile beginnt oder der Puffer voll ist 
		// Ungepuffert: 	Sofort übertragen
	
	// Standard Ströme: Zeiger auf ein FILE-Object
		// stdin: 	mit der Tastatur verbunden 			zeilenweise gepuffert
		// stdout: 	mit dem Bildschirm verbunden 		zeilenweise gepuffert
		// stderr:  mit dem Bildschirm verbunden 			      ungepuffert

	// Man kann die Ausgabe auch in eine Datei schreiben. Dazu wird ein Objekt vom Typ FILE angelegt und initialisiert.
	// Eine erfolgreich geöffnete Datei liefert immer einen Zeiger auf ein FILE-Speicherobjekt zurück.
	// Das FILE-Speicherobject ist ein Struct welcher alle wichtigen Informationen für die I/O speichert
	
	FILE *fp;

	// Öffnen von Dateien mit fopen. Die Funktion liefert einen Pointer auf den entsprechenden Datenstrom sonst NULL Pointer
	FILE *fopen(const char *restrict filename, const char *restrict mode);
	// filename: Dateiname oder Pfad
	// mode: Zugriffsmodus 
		// r 	Lesen
		// w 	Schreiben (falls die Datei nicht existiert wird sie erstellt)
		// a 	Öffnen zum Anhängen (falls die Datei nicht existiert wird sie erstellt)
		// r+	Lesen und Schreiben, beginnt am Anfang der Datei
		// w+ 	Lesen und Schreiben, überschreibt die Datei
		// a+ 	Lesen und Schreiben, beginnt am Ende der Datei
		// Um Dateien im Binärmodus zu lesen muss man nach dem mode noch ein b hinzufügen z.b. r+b

	// Nach Schreiboperationenn muss man die Operation mit bestimmten Funktionen abschließen:
	// Schreiben, dann Lesen: fflush, fsetpos, fseek, rewind

	// Nach Leseoperationen muss der Schreibpointer positioniert werden:
	// Lesen, dann Schreiben: fseek, fsetpos, rewind

	//Beispiel:
	FILE *fp = fopen(filename, "r");
	if (fp != NULL)
	{
		printf("Datei wurde geöffnet.\n");
	}

	// Schließen von Dateien mit fclose
	int fclose(FILE *fp);
	// fclose schliest den zu fp gehörigen Datenstrom und leert den damit verbundenen Puffer
	// Falls erfolgreich gibt die funktion 0 zurück, ansonsten etwas anderes.

	// Einlesen von einzelnen Zeichen, gibt EOF bei Fehler zurück
	int fgetc(FILE *fp);
	int getc(FILE *fp);
	int getchar(); /*entspricht*/ 	getc(stdin);

	// Einzelnes Zeichen im Datenstrom wieder zurückstellen. Gibt das Zeichen zurück, gibt EOF bei Fehler zurück
	int ungetc(int x, FILE *fp);

	// Schreiben von einzelnen Zeichen, gibt EOF bei Fehler zurück
	int fputc(int c, FILE *fp);
	int  putc(int c, FILE *fp);
	int  putchar(int c); /*entspricht*/ 	petc(c,stdout);

	// Beispiel: "Foliensatz 15 Seite 17"

	// Zeilenweise einlesen
	char *fgets(char *restrict buf, int n, FILE *restrict fp);
	// Vom Strom fp werden bis zu n-1 Zeichen in den Puffer buf eingelesen. Am Ende wird ein Terminierungszeichen angehängt.
	// Gibt NULL-Pointer bei Fehler zurück, ansonsten Anfangsadresse

	// Zeilenweise schreiben. Rückgabewert >=0 bei erfolgt ansonsten EOF
	// fputs schreibt den nullterminerten String str in den Strom fp. Das Terminierungszeichen zählt nicht dazu.
	int fputs(const char *restrict str, FILE *restrict fp);
	//  puts gibt den String str auf stdout aus.
	int puts(const char *str);

	// Formatierte Ausgabe
	int fprintf(FILE *restrict fp, const char *restrict format, ...);
	// Wie printf nur für den angegebenen Datenstrom. fp ist ein Zeiger auf den Strom
	// Rückgabewert zeigt an wie viele Zeichen geschrieben wurde. Negativer Wert bei Fehler

	// Formatiertes Einlesen
	int fscanf(FILE *restrict fp, const char *restrict format, ...)
	// Wie scanf nur für den angegebenen Datenstrom. fp ist ein Zeiger auf den Strom
	// Rückgabewert zeigt Anzahl der Konvertierungen an. Bei Fehler EOF
	// Syntax und Beispiele "Foliensatz 15 S, 22+23"

	// Anschließend Lesen und Schreiben von Binärdateien S. 24+25 (sehr unwahrscheinlich bei der Klausur)

	// Bewegen des FILE-Pointers. Bei Erfolg wird 0 zurückgeben, ansonsten ungleich 0
	int fseek(FILE *fp, long offset, int position);
	// fp: 		 Der zu verändernde File-Pointer
	// position: Wo offset startet: 
				// SEEK_SET (Anfang der Datei), 
				// SEEK_CUR (Aktuelle Position des File-Pointers)
				// SEEK_END (Ende der Datei)
	// offset: 	 Anzahl der Bytes um den der File Pointer vom offset weg verschoben werden soll

	// Position ermitteln und setzen. Position: Anzahl von Bytes vom Anfang der Datei. Bei Erfolg wird 0 zurückgeben, ansonsten ungleich 0
	int fgetpos(FILE *fp, fpos_t *restrict pos);
	int fsetpos(FILE *fp, const fpos_t *pos);

	// Liefert aktuelle Schreib/Leseposition im Strom (gemeinsam mit fseek benutzen)
	long ftell(FILE *fp);

	// Setzt die aktuelle Schreib/Leseposition an den Anfang des Stroms
	void rewind(File *fp);

	// Überprüfen ob EOF ein Fehler ist oder ob es wirklich End of file ist.
	int feof(FILE *fp); 		// Gibt ungleich 0 zurück wenn EOF-Flag für fp gesetzt ist, sonst 0
	int ferror(FILE *fp);		// Gibt ungleich 0 zurück wenn Fehler-Flag für fp gesetzt ist, sonst 0
	void clearerr(FILE *fp);	// Löschen von Fehler und EOF-Flags

	// Datei löschen. 		Gibt 0 bei Erfolg zurück, sonst -1
	int remove(const char *pathname);
	// Datei umbenennen.	Gibt 0 bei Erfolg zurück, sonst -1
	int rename(const char *oldname,const char *newname);

	// Pufferung für Datenstrom setzen
	int setvbuf(FILE *restrict fp, char *restrict buf, int type, size_t size);
	// type: 
		// _IONBF (Ungepuffert)
		// _IOLBF (Zeilenpufferung)
		// _IOFBF (Vollpufferung)

	// Puffer leeren. Alle Daten im Puffer werden geschrieben. Gibt 0 bei Erfolg zurück, sonst EOF
	// Ist der Parameter NULL werden ALLE offenen Puffer geleert.
	int fflush(FILE *stream);

	// Einige Funktionen setzen im Fehlerfall die globale Variable "errno" auf einen bestimmten Wert.
	// Funktionen: fopen, fclose, remove, rename, fgsetpos, fgetpos, fseek, ftell, fflush;
}

//8. Commandozeilenparameter
void Commandozeilenparameter(){

	int main(int argc, char const **argv){return EXIT_SUCCESS}
	//argc = argument counter
	//argv = argument vector
	/*
	Example: ./main abc 123
		ARGC: 3
		ARGV: ["./main"] ["abc"] ["123"]
	*/
}

//9. Präprozessor
void Präprozessor(){
}

//10. Listen
void Listen(){
}

//11. Code Snippets
void Code_Snippets(){

}

