#include <stdio.h>

// Clears input buffer
void clearBuffer(void) {
  while (getchar() != '\n')
    ;
}

// Frage Benutzer nach nächster Operation
char menu(void) {
  printf("[a]ddieren\n");
  printf("[s]ubtrahieren\n");
  printf("[m]ultiplizieren\n");
  printf("[b]eenden\n");

  char c;
  do {
    printf("Was wollen Sie als nächstes tun?: \n");
    scanf("%c", &c);
    clearBuffer();
    while (getchar() != '\n')
      ; // Entferne alle restlichen Zeichen aus dem Input buffer
  } while (c != 'a' && c != 's' && c != 'm' && c != 'b');
  return c;
}

int add(int a, int b) { return a + b; } // Addiere a und b
int sub(int a, int b) { return a - b; } // Subtrahiere b von a
int mul(int a, int b) { return a * b; } // Multipliziere a und b

// Frage Benutzer nach den beiden Operanden und liefere das Ergebnis der
// korrekten operation zurück
int getOperandsAndExecuteOperation(char function) {
  printf("Geben Sie die Operanden, getrennt durch ein Leerzeichen ein: ");
  int a, b;
  scanf("%d %d", &a, &b);
  clearBuffer();

  // Wähle die richtige Operation und speichere das Resultat
  int result = 0;
  switch (function) {
  case 'a': {
    result = add(a, b);
    break;
  }
  case 's': {
    result = sub(a, b);
    break;
  }
  case 'm': {
    result = mul(a, b);
    break;
  }
  default:
    break;
  }

  return result;
}

// Gibt den Parameter a als Ergebnis aus
void print(int a) { printf("Das Ergebnis der Berechnung is %d\n", a); }

int main(void) {
  char currentOperation;
  while ((currentOperation = menu()) != 'b') { // Bis b im Menü gewählt wurde
    print(getOperandsAndExecuteOperation(currentOperation));
  }

  printf("Auf Wiedersehen!\n");
}
