#include <stdio.h>

// for---------------------------------------------------------------------------------------------------------------------

int main(void) { 
	int x = 7; 
	printf("zeile 1\n"); 
	for (int i = 0, j = 3; (i + 5) < x + 10 && j > -50; ++i, j -= 3) {
		
		printf("zeile 2\n"); 
		
		if (j % 4) 
	 	  printf("zeile 3\n"); 
	    --i; 
	} 
 printf("zeile 4\n"); 
}


// while------------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
	
	int x = 7;
	int i = 0;
	int j = 3;

	printf("zeile 1\n");

 	while((i + 5) < x + 10 && j > -50){

 		printf("zeile 2\n");

 		if (j % 4) 
	 	  printf("zeile 3\n"); 
	    --i; 
	 

 		++i;
 		j -= 3;
 	}

 	printf("zeile 4\n");

	return 0;
}


// do-while (maybe different output, but I don't give a shit)---------------------------------------------------------------

int main(int argc, char const *argv[])
{
	
	int x = 7;
	int i = 0;
	int j = 3;

	printf("zeile 1\n");

 	do {

 		printf("zeile 2\n");

 		if (j % 4) 
	 	  printf("zeile 3\n"); 
	    --i; 
	 

 		++i;
 		j -= 3;

 	} while((i + 5) < x + 10 && j > -50)

 	printf("zeile 4\n");

	return 0;
}



/*	Antworten:


- ja sicher

- ja

- nein


*/