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
		if (n == 0 || n < 2){
			printf("Usage: ./a1 n\nn has to be a positive number greater then 1 and smaller then %d \n", INT_MAX);
			exit(EXIT_FAILURE);
		}
	}

	//Computes and prints all fibonacci numbers smaller then n
	int number1 = 0;
	int number2 = 1;
	int numberfib = 0;
	printf("%d ",number1);
	printf("%d ",number2);
	while(1){
		numberfib = number1 + number2;
		if (numberfib < n){
			printf("%d ",numberfib);
		}else{
			break;
		}
		number1 = number2;
		number2 = numberfib;
	}
	printf("\n");

	return EXIT_SUCCESS;
}