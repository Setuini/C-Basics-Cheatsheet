/*
Antworten: 

- Hier werden Werte übergeben und innerhalb der Funktion vertauscht. 
  Da dies aber keine pointer sind und die Funktion keinen Rückgabewert hat, verändert sich nichts.

- Die Parameter der Funktion sind Pointer. die Variable aux bekommt den Wert auf den Pointer a zeigt (1).
  Der Wert von a wird zum Wert von b (2). Anschließend bekommt b den Wert von aux. Nun wurden die Werte ausgetauscht.

- Weil char 8 bit und int 32 bit hat. Bei 2 gleichen Datentypen sollte das Ergebnis gleich sein

- Die Variable Char beinhaltet nur 1 Wert, dieser wird ausgegeben. 
  Aber die schleife iteriert weiter und es gibt keine weiteren Werte also wird 0 ausgegeben. 

  Segmentation Fault  --> WTF ????

- es wird kein Pointer zurückgegeben sondern eine Adresse.

~ return_local_pointeretzten 2 Antworten ungenau ~

*/

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
   return a + b;
}

void swap_arguments(int a, int b) {
   int aux = a;
   a = b;
   b = aux;
   return;
}

void swap_pointer(int* a, int* b) {
   int aux = *a;
   *a = *b;
   *b = aux;
   return;
}

int* return_local_pointer() {
   int* a = 17;
   return &a;
}

int main(void) {
   int one = 1;
   int two = 2;
   printf("Zeile 1: %d %d\n", one, two);
   swap_arguments(&one, &two);
   printf("Zeile 2: %d %d\n", one, two);
   swap_pointer(&one, &two); 
   printf("Zeile 3: %d %d\n", one, two);


   int int_value = 3;
   int* int_pointer = &int_value;
   char* char_pointer = &int_value;
   if (int_pointer + 1 == char_pointer + 1) {
      puts("Zeile 4: Selbe Speicheradresse.");
   } else {
      puts("Zeile 4: Unterschiedliche Speicheradresse.");
   }
   printf("Zeile 5: ");
   for(int i = 0; i < 4; i++) {
      printf("%hhu ", *(char_pointer + i));
   }
   printf("\n");


   int* pointer_returned = return_local_pointer();
   add(17, 06);
   add(1, 1);
   printf("Zeile 6: %d\n", *pointer_returned);
   return EXIT_SUCCESS;
}
