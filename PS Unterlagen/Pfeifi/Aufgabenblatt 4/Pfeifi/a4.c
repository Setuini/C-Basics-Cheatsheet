#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	printf("Variablen: a,b,c,d,e;\n");

	double a = 2.23e14;
	float b = 0.034;
	char c = 'C';
	unsigned int d = 3147483647;
	long e = 3146573547;
//	{ int sd = 234; }
//	int zero;

	printf("Ausgabe:\n");
	printf("a = %e\n",a );
	printf("b = %.10f\n",b ); 		//Wert abgeschnitten
	printf("c = %x\n",c );
	printf("d = %3ld\n",e );
	printf("e = %u\n",d );
//	printf("%i\n", sd);			// printf needs to be in block
//	printf("%i\n",zero );		// no value

	exit(0);
}