#include <stdio.h>
#include <stdlib.h>

int** init_matrix(int dim1, int dim2);
void free_matrix(int** matrix, int dim1);

int main(int argc, char const **argv){
	int dim1 = 4;
	int dim2 = 8;
	int** matrix = init_matrix(dim1,dim2);

	//Init values with cell numbers
	for (int i = 0; i < dim1; i++){
		for (int j = 0; j < dim2; j++){
			matrix[i][j] = (j+1) + ((i+1)*10);
		}
	}

	//Print Values
	printf("\nmatrix %d x %d\n",dim1,dim2);
	for (int i = 0; i < dim1; i++){
		for (int j = 0; j < dim2; j++){
			printf("%02d ",matrix[i][j]);
		}printf("\n");
	}printf("\n");

	free_matrix(matrix,dim1);
	return EXIT_SUCCESS;
}

int** init_matrix(int dim1, int dim2){
	int** matrix = NULL;
	//Allocate dimension 1
	matrix = (int**)malloc(sizeof(int*)*dim1);
	//matrix = (int**)calloc(dim1, sizeof(int*)); //if the matrix should be initialized with 0's
	if (matrix == NULL){
		fprintf(stderr, "ERROR - malloc dimension 1\n");
		exit(EXIT_FAILURE);
	}
	//Allocate dimension 2
	for (int i = 0; i < dim1; i++){
		matrix[i] = (int*)malloc(sizeof(int)*dim2);
		//matrix[i] = (int*)calloc(dim2, sizeof(int)); //if the matrix should be initialized with 0's
		if (matrix[i] == NULL){
			fprintf(stderr, "ERROR - malloc dimension 2 - i=%d\n",i);
			exit(EXIT_FAILURE);
		}	
	}
	return matrix;
}

void free_matrix(int** matrix, int dim1){
	//Free dimension 2
	for (int i = 0; i < dim1; i++){
		free(matrix[i]);
	}
	//Free dimension 1
	free(matrix);
}