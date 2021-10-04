//
// Created by ilya on 04.10.2021.
//

#ifndef TEST_INT_DYNAMIC_ARRAY_H
#define TEST_INT_DYNAMIC_ARRAY_H
#include "stdlib.h"

typedef struct int_dynamic_array {
    int* data;
    int capacity;
    int size;
} int_dynamic_array;

int_dynamic_array* create_int_dynamic_array(int capacity);

void push_back_int_dyn_arr(int data);

void pop_back_int_dyn_arr();

void free_int_dyn_arr(int_dynamic_array* array);

#endif //TEST_INT_DYNAMIC_ARRAY_H
