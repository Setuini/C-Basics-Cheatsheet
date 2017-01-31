#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ALLOC 1

//Prototypes
void printmenu();
void inputNumber(int **array, int *inputcounter, int *realloccounter);
void printStatistic(int *array, int *inputcounter);
int min(int *array, int *len);
int max(int *array, int *len);
float avg(int *array, int *len);

//Main
int main(int argc, char const **argv){

	bool running = true;
	char userin = 0;
	int *array = NULL;
	int inputcounter = 0;
	int realloccounter = 0;
	int *inputptr = &inputcounter;
	int *reallocptr = &realloccounter;

	//allocate memory for the int array
	array = (int *)malloc(sizeof(int) * ALLOC);
	if (array == NULL){
		fprintf(stderr,"Couldn't allocate Memory\n");
		exit(EXIT_FAILURE);
	}

	printmenu();

	//main loop - running until the user inputs 'Q'
	while(running){
		printf("Waiting for input: ");

		//get input from user
		char buffer[LINE_MAX];
		fgets(buffer, sizeof(buffer),stdin);
		//2 because of \n
		if (strlen(buffer) > 2){
			printf("invalid input. Please retry\n");
			continue;
		}
		userin = buffer[0];

		switch(userin){
			case 'n':
			case 'N':
				inputNumber(&array, inputptr, reallocptr);
				break;
			case 's':
			case 'S':
				printStatistic(array, inputptr);
				break;
			case 'q':
			case 'Q':
				printf("\nGoodbye.\n");
				running = false;
				break;
			case 'c':
			case 'C':
				printmenu();
				break;
			default:
				printf("invalid input. Please retry\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}

//Functions
void printmenu(){
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

void inputNumber(int **array, int *inputcounter, int *realloccounter){

	//array is running out of memory, time to reallocate
	if (*inputcounter > ALLOC - 1){
		//printf("REALLOC - REALLOCCOUNTER = %d REALLOCSIZE = %lu\n", *realloccounter, sizeof(int) * ALLOC * (*realloccounter + 2));
		*array = (int *)realloc(*array, sizeof(int) * ALLOC * (*realloccounter + 2));
		if (*array == NULL){
			fprintf(stderr, "Couldn't reallocate memory\n");
			exit(EXIT_FAILURE);
		}
		//reset counter
		//*inputcounter = 0;
		(*realloccounter)++;
	}

	printf("Please input a whole number beetween -100 and 100.\n");
	char buffer[LINE_MAX];
	fgets(buffer, sizeof(buffer), stdin);
	//remove \n
	buffer[sizeof(buffer) - 1] = 0;
	char *ptr;
	//get int from string buffer
	int usernum = strtol(buffer, &ptr, 10);
	if (usernum < -100 || usernum > 100){
		printf("Invalid number: %d\n",usernum);
	}else{
		//*((*array) + *inputcounter) = usernum;
		*( (*array) + (*inputcounter)) = usernum;

		printf("input: %d counter: %d\n", *(*array + *inputcounter), *inputcounter);
		(*inputcounter)++;
	}
}

void printStatistic(int *array, int *inputcounter){

	for (int i = 0; i < *inputcounter - 1; i--){
		printf("Array[%d]= %d\n",i, array[i]);
	}

	printf("CNT: %d\n", *inputcounter);
	printf("MIN: %d\n", min(array, inputcounter));
	printf("MAX: %d\n", max(array, inputcounter));
	printf("AVG: %f\n", avg(array, inputcounter));
}

int min(int *array, int *len){
	int min = array[0];
	for (int i = 0; i < *len; i++){
		if (array[i] < min){
			min = array[i];
		}
	}
	return min;
} 

int max(int *array, int *len){
	int max = array[0];
	for (int i = 0; i < *len; i++){
		if (array[i] > max){
			max = array[i];
		}
	}
	return max;
} 

float avg(int *array, int *len){
	int sum = 0;
	for (int i = 0; i < *len; i++){
		sum += array[i];
	}
	return (float) sum / *len;
} 

















