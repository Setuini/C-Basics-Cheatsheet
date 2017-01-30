#include <stdio.h>

int main(void) {
  const int n = 1000; // Definiere Obergrenze
  int a = 0;    // Vorletzte oder letzte Fibonacci Zahl
  int b = 1;    // Vorletzte oder letzte Fibonacci Zahl

  // Ausgabe der ersten Zahl
  printf("%d ", a);

  // Wiederhole solange keine der beiden Zahlen > n ist
  while (a < n && b < n) {
    if (a > b) {        // Also ist a die letzte berechnete Zahl
      printf("%d ", a); // Ausgabe der letzten Zahl
      b = a + b;        // Berechnung der neuen Fibonacci Zahl
    } else {            // Also ist b die letzte berechnete Zahl
      printf("%d ", b); // Ausgabe der letzten Zahl
      a = b + a;        // Berechnung der neuen Fibonacci Zahl
    }
  }
  printf("\n"); // Ausgabe von Newline für schönere Formatierung
}
