#include <stdio.h>

int main(void) {
  double a = 2.23e14;
  float b = 0.034;
  char c = 'C';
  unsigned int d = 3147483647;
  long e = 31474836472;
  { int sd = 234; }
  int zero;

  // Korrekte Asugaben
  printf("a = %f\n", a);
  printf("b = %f\n", b);
  printf("c = %c\n", c);
  printf("d = %u\n", d);
  printf("e = %ld\n", e);
  
  // Ausgabe als hex
  printf("hex(c) = 0x%X\n", c);
  // Ausgabe als Exponentialzahl
  printf("exp(a) = %e\n", a);
  // Ausgabe mit 10 Nachkommastellen
  printf("b mit 10 Nachkomma = %.10f\n", b);
  // Ausgabe ist nicht 0.03400000... wegen ungenauigkeit von float
  // Ausgabe mit fixer Anzahl an Stellen
  printf("c als int mit 3 Stellen = %03d\n", c);
  // Ausgabe von Zero
  // Ist nicht initialisiert und daher möglicherweise nicht null
  printf("Zero? = %d\n", zero);
}
