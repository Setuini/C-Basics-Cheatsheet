#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// last Element muss pointer sein, sonst kann man den Wert in einer Funktion nicht bleibend verändern
int enqueue(int arr[], int* lastElementIdx, int length, int element);
int dequeue(int arr[], int* lastElementIdx);
void printQueue(const int arr[], int lastElementIdx);

int main(int argc, char** args)
{
	
	int len = 100;
	int queue[len];
	queue[0]= 1;
	int* elementPtr=queue;
	

	printf("Fill Array with Random Intergers:\n");
	srand(time(NULL));
	int random;
	for (int i = 0; i < 20; ++i)
	{
		random = rand() % 100;
		enqueue(queue,elementPtr,len,random);

		if (i!=19)
		{
			printf("in main: %i,\n", queue[i]);
		}
		else
		{
			printf("in main: %i;\n", queue[i]);

		}
		
	}


	printQueue(queue,*elementPtr);


	return EXIT_SUCCESS;
}

int enqueue(int arr[], int* lastElementIdx, int length, int element){


	for (int i = 0; i < length; ++i)
	{	printf("Array: %p \n",arr + i);
		printf("Counter: %p \n", lastElementIdx);
		if (arr + i == lastElementIdx && i != 99)
		{
			arr[i+1] = element;
			lastElementIdx++;
			return 1;
		}
			
	}

		return 0;
	

}

int dequeue(int arr[], int* lastElementIdx){

	for (int i = 0; arr[i] != *lastElementIdx; ++i)
	{
		if (arr[i] != 0)
		{
			int temp = arr[i];
			arr[i] = 0;
			return temp;
		}
	}
	return 0;
}

void printQueue(const int arr[], int lastElementIdx){

	printf("Printing Queue Elements:\n");
	for (int i = 0; arr[i] != lastElementIdx; ++i)
	{
			printf("%i,",arr[i]);
	}
	printf("%i;\n",lastElementIdx);
	return;
}