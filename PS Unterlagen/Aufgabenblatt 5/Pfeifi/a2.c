#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	int n = 5;
/*
	int x = 0;
	int y = 0;
	int z = 0;*/

	// 2 DO: 3 Zahlen x,y,z in einem Tripel, jede Zahl nur 1 Vorkommen

	for (int i = 0; i < n; ++i)
	{

		printf("(%i,%i,%i)\n", i,i,i );

		for (int j = 0; j < n; ++j)
		{

			printf("(%i,%i,%i)\n",i,j,i );

			for (int k= 0; k < n; ++k)
			{

				printf("(%i,%i,%i)\n",i,j,k );

					
			}	
		}
	}


	exit(0);
}