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

	printf("(x, y, z)\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (!(i == j || j == k || i == k)){
					printf("(%d, %d, %d)\n",i,j,k);
				}
			}
		}
	}

	return EXIT_SUCCESS;
}

