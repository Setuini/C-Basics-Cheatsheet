#include <stdio.h>

int main(void) {
  const int n = 1000; // Definiere Obergrenze
  int a = 0;    // Vorletzte Zahl
  int b = 1;    // Letzte Zahl

  printf("%d ", a); // Ausgabe der ersten Zahl
  
  while (b < n) {
    printf("%d ", b);  // Ausgabe der letzten berechneten Zahl
    int new_b = a + b; // Berechnung der nächsten Zahl
    a = b;             // Die letzte Zahl wird nun die Vorletzte
    b = new_b;         // Die neu berechnete Zahl wird die neue, letzte Zahl
  }
  
  printf("\n"); // Ausgabe von Newline für schönere Formatierung
}
