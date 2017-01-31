#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[]){

	//default value
	int n = 5;

	//Convert the command line Parameter into an int
	if (argc > 1){
		n = atoi(argv[1]);
		if (n <= 0){
			printf("Usage: ./a1 n\nn has to be a positive number and smaller then %d \n", INT_MAX);
			exit(EXIT_FAILURE);
		}
	}

	//Print first half
	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < i; j++){
			printf("%d ",j+1);
		}
		printf("\n");
	}

	//Print second half
	for (int i = n; i > 0; i--){
		for (int j = 1; j < i; j++){
			printf("%d ",j);
		}
		printf("\n");
	}
	

	return EXIT_SUCCESS;
}

