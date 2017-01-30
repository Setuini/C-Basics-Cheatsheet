#include <stdio.h>
#include <stdlib.h>

int whichNumber(void);
int fibonacci (int n);

int main(int argc, char** args)
{	int n = whichNumber();
	int result = fibonacci(n);
	printf("Die %i-te Zahl der Fibonacci Folge ist: %i \n",n,result);
	return 0;
}

int whichNumber(void){
	int n = 0;
	printf("Geben sie einen Wert für n ein:     (n < 47)\n");
	scanf("%i",&n);
	return n;
}

int fibonacci (int n){

	if(n == 0)
      return 0;
   	else if (n == 1)
      return 1;
   	else
      return ( fibonacci(n-1) + fibonacci(n-2) );
	
}




/*	Antworten:


- Nein

- Stack Overflow


*/