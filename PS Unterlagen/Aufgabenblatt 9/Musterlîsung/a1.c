// Pow implemented manually by iteratively multiplying because why not
// ... In practice this is a very bad idea (because it's very slow)!

#include <stdio.h>

enum { INT, FLOAT, DOUBLE }; // Used as types in pow_void

// Calculate exponent of an int
void pow_int(int *base, int exponent) {
  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result = result * *base;
  }
  *base = result;
}

// Calculate exponent of a float
void pow_float(float *base, int exponent) {
  float result = 1;
  for (int i = 0; i < exponent; i++) {
    result = result * *base;
  }
  *base = result;
}

// Calculate exponent of a double
void pow_double(double *base, int exponent) {
  double result = 1;
  for (int i = 0; i < exponent; i++) {
    result = result * *base;
  }
  *base = result;
}

// Calculate exponent of a number with specified type
void pow_void(void *base, int exponent, int type) {
  switch (type) {
  case INT: {
    pow_int((int *)base, exponent);
    break;
  }
  case FLOAT: {
    pow_float((float *)base, exponent);
    break;
  }
  case DOUBLE: {
    pow_double((double *)base, exponent);
    break;
  }
  default:
    break;
  }
}

int main() {
  // Use specific functions for each type
  printf("Using individual functions:\n");
  int i_base = 2;
  pow_int(&i_base, 4);
  printf("int: 2 pow 4 = %d\n", i_base);

  float f_base = 2;
  pow_float(&f_base, 4);
  printf("float: 2.0 pow 4 = %f\n", f_base);

  double d_base = 2;
  pow_double(&d_base, 4);
  printf("double: 2.0 pow 4 = %f\n", d_base);

  // Use void pointer method
  printf("Using pow_void:\n");
  int vi_base = 2;
  pow_void(&vi_base, 4, INT);
  printf("int: 2 pow 4 = %d\n", vi_base);

  float vf_base = 2;
  pow_void(&vf_base, 4, FLOAT);
  printf("float: 2.0 pow 4 = %f\n", vf_base);

  double vd_base = 2;
  pow_void(&vd_base, 4, DOUBLE);
  printf("double: 2.0 pow 4 = %f\n", vd_base);
}
