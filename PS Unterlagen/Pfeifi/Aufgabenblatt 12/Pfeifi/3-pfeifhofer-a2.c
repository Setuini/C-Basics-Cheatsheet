#include <stdio.h>
#include <stdlib.h>
#define DEBUG(z) printf("---> %s, Funktion %s, \n Zeile %d, Datei %s \n", z,__func__,__LINE__,__FILE__);
int add(int a);
int main(void) {
	int b=2;
	b = add(b);
	printf("%d", b);
	return EXIT_SUCCESS;
}
int add(int a){
	a+=a;
	DEBUG("Hilfe");
	return a;
}
