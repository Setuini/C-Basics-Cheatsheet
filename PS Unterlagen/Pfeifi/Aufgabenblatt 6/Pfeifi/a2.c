#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** args)
{
	srand(time(NULL));
	int random = rand() % 100;
	int input[3]; 
	int turn = 0;
	int small = 0;
	int big = 0;

	printf("Computer hat eine Zufallszahl generiert. (%i)\n",random);

	while(1){
	
	printf("Geben sie 3 Zahlen zwischen 1-100 ein: \n");

	turn++;

	for (int i = 0; i < 3; ++i)
	{
		scanf("%i", &input[i]);

	}

	if (input[0] == random || input[1] == random  || input[2] == random)
		{
			printf("Sie haben in %i Zügen gewonnen!\n",turn);
			break;
		}


	for (int i = 0; i < 3; ++i)
	{
		if (input[i] > random)
		{
			small++;
		}
		else
		{
			big++;
		}
	}

	if (big > small)
	{
		printf("Die gesuchte Zahl ist größer. \n");

	}
	else
	{
		printf("Die gesuchte Zahl ist kleiner. \n");
	}

	small = 0;
	big = 0;

	}
}