#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

const int LOWER_LETTER_OFFSET = 97;

// Encodes or decodes character c using key k
// The character c has to be a lower case letter
char endecode_char(char c, long k) {
  c = c - LOWER_LETTER_OFFSET; // Transform character to range 0 ... 26
  int tmp = (c + k) % 26; // Apply key
  // Special case if we get a negative number
  if (tmp < 0)
    tmp = tmp + 26;
  return tmp + LOWER_LETTER_OFFSET; // Transform character back to ASCII
}

// Encodes or decodes a string with key k
void endecode(char *s, long k) {
  for (; *s != 0; s++) {
    *s = endecode_char(*s, k);
  }
}

// Return true if a string contains only lower case letters
bool is_lower(char *s) {
  for (; *s != 0; s++) {
    if (*s < LOWER_LETTER_OFFSET || *s > LOWER_LETTER_OFFSET + 26)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Bitte übergeben Sie den Schlüssel und ein Wort zum "
           "ver-/entschlüsseln!\n");
    return EXIT_FAILURE;
  }
  if (!is_lower(argv[2])) {
    printf("Bitte geben sie nur Kleinbuchstaben ein!\n");
    return EXIT_FAILURE;
  }

  // Read key
  char *endptr;
  errno = 0; // So we can check if conversion from string to long worked
  long key = strtol(argv[1], &endptr, 10);
  if ((errno == ERANGE && (key == LONG_MAX || key == LONG_MIN)) ||
      (errno != 0 && key == 0)) {
    printf("Bitte geben Sie eine Zahl als Schlüssel ein\n");
    return EXIT_FAILURE;
  }

  endecode(argv[2], key);
  printf("%s\n", argv[2]);
}
