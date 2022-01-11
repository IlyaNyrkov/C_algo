//
// Created by ilya on 04.10.2021.
//

#ifndef TEST_DYNAMIC_ARRAY_H
#define TEST_DYNAMIC_ARRAY_H
#include "stdlib.h"

#define SUCCESS 0
#define NULL_ARRAY_ERR 101
#define NULL_DATA_IN_ARRAY_ERR 102
#define EMPTY_ARRAY_POP 201
#define MEM_ALLOC_ARRAY_ERR 301
#define ARR_RESIZE_ERR 401

typedef struct dynamic_array {
    int* data;
    int capacity;
    int size;
} dynamic_array;

dynamic_array* make_dynamic_array(int capacity);

int push_back(dynamic_array* array, int data);

int pop_back(dynamic_array* array);

int free_dynamic_array(dynamic_array* array);

int resize(dynamic_array* array, int new_size);

int copy(dynamic_array* original, dynamic_array* copy);

#endif //TEST_DYNAMIC_ARRAY_H
