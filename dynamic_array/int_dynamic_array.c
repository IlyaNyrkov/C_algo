#include "int_dynamic_array.h"


int_dynamic_array* create_int_dynamic_array(int capacity) {
    int_dynamic_array* array = (int_dynamic_array*) malloc(sizeof(int_dynamic_array));
    array->data = (int*) malloc(capacity);
    array->capacity = capacity;
    array->size = 0;
    return array;
}
