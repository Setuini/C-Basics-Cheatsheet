#ifndef VERSATILE_ARRAY
#define VERSATILE_ARRAY

#include <stdlib.h>

typedef struct {
  unsigned long long length;
  size_t element_size;
  void *data;
} array_t;

// returns a new array which can store <length> elements of any
// type that can be stored in <element_size> bytes  <length> elements
array_t create_array(size_t element_size, unsigned long long length);

// initializes all bytes of the array to zero
void init_array(array_t array);

// clears any memory that is
void destroy_array(array_t array);

// sets element number <element_number> to the value given by the pointer
// <new_value>
void set_element(array_t array, unsigned long long element_number,
                 void *new_value);

// returns a pointer to element number <element_number>
void *get_element(array_t array, unsigned long long element_number);

#endif
