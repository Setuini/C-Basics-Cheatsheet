#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{

	int n = 10; 	// input value
	int m = n+1;	// working variable
	int j = 0;		// secondary counter

	for (int i = 1; i <= n; ++i)
	{
		if (i%2 == 0)
		{
		printf("%i\n",--m);
		}
		else
		{
		printf("%i\n",++j);
		}
	}
}