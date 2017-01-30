#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	int n = 10;
	printf("%i:\n",n);
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		
		if (j==4)
		{
			printf("%i\n",i);
			j=0;
		}
		j++;
	}
}