#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	
	int n = 11;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			printf("%i",j );
		}
		printf("\n");
	}	

	for (int i = n; i > 0; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			printf("%i",j );
		}
		printf("\n");
	}


	exit(0);
}