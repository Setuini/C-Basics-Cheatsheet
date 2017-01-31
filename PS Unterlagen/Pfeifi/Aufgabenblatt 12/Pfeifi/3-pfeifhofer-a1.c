#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 40
#define AUSGABE printf("Milimeter    :  "); scanf("%d", &data.milimeters);
#define AUSGABE_ptr printf("Milimeter:  %d \n", prod->milimeters);
#ifdef INCH
#undef AUSGABE
#undef AUSGABE_ptr
#define AUSGABE_ptr printf("Zoll:  %lf \n", prod->zoll);
#define AUSGABE printf("Zoll    :  "); scanf("%lf", &data.zoll);
#endif

struct product input_product(void);
void print_address(const struct product *prod);
struct product {
	char name[MAXCHAR];
	#ifdef INCH
	double zoll;
	#endif
	#ifndef INCH
	int milimeters;
	#endif
	int quantity;
};

int main(void) {
	char decision = '0';
	int array_counter =0;
	struct product prod[10];
		while(decision!='b'){
			printf("e für einfügen \np für anzeigen der Datensätze \nb zum Beenden\n");
			scanf("%c", &decision);
			while (getchar() != '\n');
			switch(decision){
			case 'e': prod[array_counter] = input_product();
			array_counter=array_counter+1;
			break;
			case 'p': for(int j =0; j<array_counter; j++){
				printf("Datensatz: %d \n", j);
				print_address(&prod[j]);
				printf("\n \n");
			}
			printf("\n"); break;
			}
		}

	return EXIT_SUCCESS;
}


struct product input_product(){
	struct product data;
	printf("Produktname    :  ");
	fgets(data.name, MAXCHAR, stdin);
	AUSGABE //define
	while (getchar() != '\n');
	printf("Anzahl   :  ");
	scanf("%d", &data.quantity);
	while (getchar() != '\n');
	return data;
}
void print_address(const struct product *prod){
	printf("Produktname:  %s", prod->name);
	AUSGABE_ptr //define abhängig von EN oder DE
	printf("Anzahl:  %d \n", prod->quantity);

}
