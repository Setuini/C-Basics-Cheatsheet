#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


//Prototypes
void print_menu();
void allocate_memory(int **array, int size);
bool menu_input(int **array);
void number_input(int **array, int *counter, int *malloc);

int main(int argc, char const *argv[]){
	bool running = true;
	int *array = NULL;
	print_menu();
	allocate_memory();

	while(running){
		running = menu_input(&array);
	}

	return EXIT_SUCCESS;
}

void print_menu(){
	system("clear");
	printf(" __________________________________\n");
	printf("|              Menu                |\n");
	printf("|__________________________________|\n");
	printf("|  Input      Description          |\n");
	printf("|                                  |\n");
	printf("|  N          Input a new number   |\n");
	printf("|  S          Print the statistic  |\n");
	printf("|  C          Clear the screen     |\n");
	printf("|  Q          Quit the programm    |\n");
	printf("|__________________________________|\n\n");
}

void allocate_memory(int **array, int size){

	*array = (int *)malloc(sizeof(int) * size);
	if (*array == NULL){
		fprintf(stderr, "%s\n", );
	}
}

bool menu_input(int **array){
	

	if (*array == NULL){
		printf("Malloc\n");
		*array = (int *)malloc(sizeof(int));
		if (*array == NULL){
			fprintf(stderr, "ERROR - Malloc\n");
			exit(EXIT_FAILURE);
		}
	}

	
	

	


	/*

	printf("Please input a letter to choose from the menu\n");
	fgets(buffer, sizeof(buffer), stdin);
	if(strlen(buffer) == 2){
		userinput = buffer[0];
	}else{
		printf("Invalid input: %s\n",buffer);
	}

	switch(userinput){
		case 'n':
		case 'N':
			number_input(&array, counter_ptr, malloc_ptr);
			break;
		case 's':
		case 'S':
		//	print_statistic();
			break;
		case 'c':
		case 'C':
			print_menu();
			break;
		case 'q':
		case 'Q':
			printf("q\n");
			return false;
		default:
			printf("Invalid input: %c\n", userinput);
			break;
	}
	*/
	return true;
}

void number_input(int **array, int *counter, int *malloc){

	//Running out of Memory
	if (*counter > *malloc - 1){
		printf("Reallocate\n");
		//Double the Memory
		*malloc *= 2;
		*array = (int*)realloc(*array, sizeof(int) * *malloc);
		if (*array == NULL){
			fprintf(stderr, "ERROR - reallocating memory\n");
			exit(EXIT_FAILURE);
		}
	}

	char buffer[LINE_MAX];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[sizeof(buffer) - 1] = '\0';

	printf("INPUT: %s\n",buffer);
}




