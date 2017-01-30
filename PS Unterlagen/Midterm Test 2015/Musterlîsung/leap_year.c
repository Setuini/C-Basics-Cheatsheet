#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MIN_YEAR = 1582;
const int MAX_YEAR = 2400;

// Check if year is a leap year or not
bool is_leap_year(int year) {
  bool leap_year = false;
  if (year % 4 == 0)
    leap_year = true;
  if (year % 100 == 0)
    leap_year = false;
  if (year % 400 == 0)
    leap_year = true;

  return leap_year;
}

int main(void) {
  for (int i = MIN_YEAR; i <= MAX_YEAR; i++) {
    printf("Jahr %d: %s\n", i, is_leap_year(i) ? "ja" : "nein");
  }
}
