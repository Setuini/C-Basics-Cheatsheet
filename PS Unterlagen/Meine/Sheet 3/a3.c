/* Blatt 3 - Aufgabe 3*/

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

	//Check for all number from 1 to n if it is dividable by 3 without remainder
	//If it is dividable print it to the console
	for (int i = 1; i < n; i++){
		if (i % 3 == 0){
			printf("%d\n",i);
		}
	}
	
	return EXIT_SUCCESS;
}