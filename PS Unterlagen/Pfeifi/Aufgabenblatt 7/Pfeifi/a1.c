#include <stdio.h>
#include <stdlib.h>


char menu(void);

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int getOperandsAndExecuteOperation(char function);
void print(int a);



int main(int argc, char** args)
{
	printf("*** Starting Calculator ***\n\n");

	while(1){
		char input = menu();

		if (input == 'b')
		{
			printf("\n*** Calculator Shutdown ***\n");
					break;
		}

		print(getOperandsAndExecuteOperation(input));
		printf("\n*** New Task ***\n\n");
	}

	exit(0);
}

char menu(void){
	char input;
	printf("Which operation would you like to execute?\n");
	printf("a = Addition\ns = Subtraction\nm = Multiplication\nb = Shutdown\n");
	scanf("%c", &input);
	while(getchar() != '\n');
	return input;
}


int getOperandsAndExecuteOperation(char function){
	printf("Give 2 Operands for the Operation.\n");
	int a = 0;
	int b = 0;
	double result = 0;

	scanf("%i",&a);
	while(getchar() != '\n');
	scanf("%i",&b);
	while(getchar() != '\n');

	switch(function){

			case 'a':
					result = add(a,b);
					break;

			case 's':
					result = sub(a,b);
					break;

			case 'm':
					result = mul(a,b);
					break;

			default: printf("Wrong Input! Try again...\n");
					break;
		}

	return result;
}


int add(int a, int b){
	return a+b;
}


int sub(int a, int b){
	double result = 0;
	return result = a-b;
}

int mul(int a, int b){
	return a*b;
}

void print(int a){
	printf("The result is %i.\n",a);
}