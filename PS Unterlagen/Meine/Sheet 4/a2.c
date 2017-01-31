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
		if (n == 0 || n < 2){
			printf("Usage: ./a1 n\nn has to be a positive number greater then 1 and smaller then %d \n", INT_MAX);
			exit(EXIT_FAILURE);
		}
	}

	//create array with numbers 1 to n (including n)
	int number_array[n];
	for(int i = 0; i < n; i++){
		number_array[i] = i+1;
	};

	//Print the numbers from bottom to top and top to bottom
	//Example n=10	1 10 2 9 3 8 4 7 5 6
	int countup = 0;
	int countdown = n-1;
	while(countup <= countdown){
		if (countdown == countup){
			printf("%d ",number_array[countup]);
		}else{
			printf("%d %d ",number_array[countup], number_array[countdown]);
		}
		countup++;
		countdown--;
	}
	printf("\n");

	return EXIT_SUCCESS;
}