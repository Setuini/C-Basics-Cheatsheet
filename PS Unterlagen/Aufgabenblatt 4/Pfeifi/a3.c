#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	int n = 30;
	int fib = 0;
	int fib2 = 1;
	int temp = 0;
	
	for (int i = 0; fib <= n; ++i)
	{
		printf("%i\n",fib);	
		fib  = fib2;
		fib2 = temp+fib;
		temp = fib;
	}

	exit(0);
}