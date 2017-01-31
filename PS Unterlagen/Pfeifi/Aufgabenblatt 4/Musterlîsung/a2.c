#include <stdio.h>

const int upper = 12;
const int lower = 1;

int main(void) {
  // Initialisierung der beiden variablen mit den korrekten Werten
  int n = upper;
  int i = lower;

  // So lange die Variable welche hinauf gezählt wird kleiner ist als
  // die Variable welche hinunter gezählt wird: Gib beide Variablen
  // aus und zähle anschliessend hinauf bzw. hinunter.
  while (i <= n) {
    if (i == n) { // Falls beide Zahlen gleich sind gib nur eine davon aus
      printf("%d ", i++);
    } else {
      printf("%d %d ", i++, n--);
    }
  }

  printf("\n"); // Für nettere Formatierung: Ausgabe eines newline am ende
}
