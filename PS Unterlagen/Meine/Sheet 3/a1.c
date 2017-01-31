/* Blatt 3 - Aufgabe 1*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[]){
	
	//Define variable n with default value 100
	int n = 100;

	//Convert the command line Parameter into an int
	if (argc > 1){
		n = atoi(argv[1]);
		if (n == 0){
			printf("Usage: ./a1 n\nn has to be a positive number and smaller then %d \n", INT_MAX);
			exit(EXIT_FAILURE);
		}
	}

	//Check if n is dividable by 3 without remainder
	if (n % 3 == 0){
		printf("Der gegebene Wert %d ist durch drei ohne rest teilbar\n", n);
	}else{
		printf("Der gegebene Wert %d ist nicht durch drei ohne rest teilbar\n", n);
	}

	return EXIT_SUCCESS;
}