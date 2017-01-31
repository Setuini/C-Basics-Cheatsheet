/* Blatt 3 - Aufgabe 4*/

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
			printf("Usage: ./a2 n\nn has to be a positive number and smaller then %d \n", INT_MAX);
			exit(EXIT_FAILURE);
		}
	}

	//print every 4th number from 1 to n
	for (int i = 1; i < n; i += 4){
		printf("%d\n",i);
	}

	return EXIT_SUCCESS;
}