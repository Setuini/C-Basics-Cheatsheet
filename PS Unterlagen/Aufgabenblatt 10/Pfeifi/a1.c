#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void map(int array[], int lenght, int (*ptr)(int));
int doubling(int value);
int quadring(int value);
int sqrtfun(int value);

int main(int argc, char** args)
{
	srand(time(NULL));

	int len = 1;

	printf("Geben Sie die Anzahl der Elemente ein: \n");
	scanf("%i",&len);
	
	int array[len]; 
	printf("Generiertes Array: [");
	for (int i = 0; i < len; ++i)
	{
		array[i] = 1 + rand() % (100 - 1);
		printf("%i,",array[i]);

	}
	printf("END]\n");

	int (*ptr)(int);

	ptr = doubling;
	//ptr = quadring;
	//ptr = sqrtfun;

	map(array,len,ptr);

	return EXIT_SUCCESS;
}


int doubling(int value){
	return value*2;
}
int quadring(int value){
	return value*value;
}
int sqrtfun(int value){

	return sqrt(value);
}


void map(int array[], int lenght, int (*ptr)(int)){

	printf("Verändertes Array: [");

	for (int i = 0; i < lenght; ++i)
	{
		array[i] = (int)(*ptr)(array[i]);
		printf("%i,",array[i]);
	}
	printf("END]\n");
	return;
}