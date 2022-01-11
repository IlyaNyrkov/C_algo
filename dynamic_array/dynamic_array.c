#include "dynamic_array.h"


dynamic_array* make_dynamic_array(int capacity) {
    dynamic_array* array = (dynamic_array*) malloc(sizeof(dynamic_array));
    array->data = (int*) malloc(capacity);
    array->capacity = capacity;
    array->size = 0;
    return array;
}
