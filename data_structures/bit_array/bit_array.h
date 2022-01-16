//
// Created by ilya on 17.01.2022.
//

#ifndef TEST_BIT_ARRAY_H
#define TEST_BIT_ARRAY_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct bit_array {
    int* bit_array;
    size_t array_size; //array count in integers
} bit_array;

bit_array* create_bit_array(size_t bits_count);

void free_bit_array(bit_array* array);

void set_bit(bit_array* array, size_t index);

void clear_bit(bit_array* array, size_t index);

bool check_bit(bit_array* array, size_t index);

#endif //TEST_BIT_ARRAY_H
