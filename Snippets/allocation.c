#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 2048

//----------------------------------------------- Prototypes -----------------------------------------------
void allocate(int** array_ptr, int max);
void reallocate(int **array_ptr, int max);
int userinput();

//-----------------------------------------------    Main    -----------------------------------------------
int main(int argc, char const *argv[]){
	
	int max = 1;
	int cur_len = 0;
	int *array = NULL;
	int** array_ptr = &array;

	//Init allocation
	allocate(array_ptr, max);

	//Main loop
	while(1){
		int num = userinput();
		if (num == -1){
			break;
		}
		array[cur_len] = num;
		cur_len++;
		if (cur_len > max-1){
			reallocate(array_ptr, max);
			max *= 2;
		}
	}

	//Print array
	printf("array = [");
	for (int i = 0; i < cur_len-1; i++){
		printf("%d, ",array[i]);
	}printf("%d]\n",array[cur_len-1]);

	//Free memory
	free(array);
	return EXIT_SUCCESS;
}

//----------------------------------------------- Functions -----------------------------------------------
//Allocate max * sizeof(int) memory
void allocate(int** array_ptr, int max){
	*array_ptr = (int*)malloc(sizeof(int)*max);
	if (*array_ptr == NULL){
		fprintf(stderr, "ERROR - malloc\n");
		exit(EXIT_FAILURE);
	}
}

//Double the size of the memory
void reallocate(int **array_ptr, int max){
	printf("realloc\n");
	*array_ptr = (int*)realloc(*array_ptr, sizeof(int)*max*2);
	if (*array_ptr == NULL){
		fprintf(stderr, "ERROR - realloc\n");
		exit(EXIT_FAILURE);
	}
}

//Get a integer in range 1 to 100 from stdin. returns -1 for quit
int userinput(){
	printf("Please input a number from 1 to 100. q to quit\n");
	char buffer[BUFFER];
	char* end;
	fgets(buffer, sizeof(char)*BUFFER, stdin);
	if (buffer[0] == 'q' || buffer[0] == 'Q'){
		return -1;
	}
	int retval = strtol(buffer,&end,10);
	if (retval < 1 || retval > 100){
		printf("Incorrect input. Please retry.\n");
		return userinput();
	}
	return retval;	
}