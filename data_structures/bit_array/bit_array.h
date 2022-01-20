
#ifndef TEST_BIT_ARRAY_H
#define TEST_BIT_ARRAY_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct bit_array {
    int32_t* array;
    size_t array_size; //array count in integers
    size_t bits_count;
} bit_array;

bit_array* create_bit_array(size_t bits_count);

void free_bit_array(bit_array* b_array);

void set_bit(bit_array* b_array, size_t index);

void clear_bit(bit_array* b_array, size_t index);

bool check_bit(bit_array* b_array, size_t index);

#endif //TEST_BIT_ARRAY_H
