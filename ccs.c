/*______________________________________________
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
|												|
|	  Eigner Rechner erlaubt					|
|	  PS Unterlagen und VO Folien erlaubt		|
|_______________________________________________|*/

/*______________________________________________
|												|
|         Table of Content:						|
|												|
| 1.  Basics:									|
|		1.1 Compile								|
|		1.2 Librays								|
|		1.3 Variablen & Datentypen 				|
|			1.3.1 Char Beispiele 				|
|			1.3.2 Bool 							|
|			1.3.3 Literale						|
|			1.3.4 Enum 							|
|			1.3.5 Konstanten					|
|			1.3.6 Gloable Variablen 			|
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
| 5.  Dynamische Speicherklassen 				|
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
			"Folie 04 Seite 25"
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
		"Folie 04 Seite 29"

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
		"Folie 05 Seite 2" - Einführung
		"Folie 05 Seite 19" - Assoziativtät

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

	//Example:
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

	// Example:
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
}

//4. Dynamische Speicherklassen 	
void Structs_Unions_Bitfelder(){
}

//5. Dynamische Speicherklassen
void Dynamische_Speicherklassen(){
}

//6. Speicherklassen
void Speicherklassen(){
}

//7. Eingabe & Ausgabe
void Eingabe_Ausgabe(){
	//scanf getchar putchar
	aa
}

//8. Commandozeilenparameter
void Commandozeilenparameter(){
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



















