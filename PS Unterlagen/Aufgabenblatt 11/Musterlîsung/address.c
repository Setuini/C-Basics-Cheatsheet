#include "address.h"
#include <stdio.h>

// Clears input buffer until newline and puts newline back on buffer
void clear_buffer(void) {
  while (getchar() != '\n')
    ungetc('\n', stdin);
  ;
}

struct address input_address(void) {
  struct address new_dataset;
  clear_buffer();
  printf("Vorname: ");
  gets(new_dataset.vorname);
  printf("Nachname: ");
  gets(new_dataset.nachname);
  printf("Adresse: ");
  gets(new_dataset.adresse);
  printf("Alter: ");
  scanf("%d", &new_dataset.alter);

  return new_dataset;
}

void print_address(const struct address *addr) {
  printf("Vorname: %s\n", addr->vorname);
  printf("Nachname: %s\n", addr->nachname);
  printf("Adresse: %s\n", addr->adresse);
  printf("Alter: %d Jahre\n", addr->alter);
}
