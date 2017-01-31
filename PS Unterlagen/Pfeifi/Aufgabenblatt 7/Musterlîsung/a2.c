#include <stdio.h>

// Rekursive implementierung von Fibonacci (Berechne die n-te Fibonacci Zahl)
int fibonacci(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

// Frage Benutzer welche Fibonacci-Zahl berechnet werden soll und liefere die
// Eingabe zurück
int whichNumber(void) {
  int n = 0;
  do { // Wiederhole Eingabe so lange der Benutzer eine negative Zahl eingibt
    printf("Welche Fibonacci-Zahl (wievielte) soll berechnet werden? Start bei "
           "0: ");
    scanf("%d", &n);
  } while (n < 0);
  return n;
}

int main(void) {
  int n = whichNumber();
  printf("Die %d-te Fibonacci Zahl is %d\n", n, fibonacci(n));
}
