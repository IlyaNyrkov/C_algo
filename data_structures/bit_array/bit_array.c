#include "bit_array.h"

bit_array* create_bit_array(size_t bits_count) {
    size_t int_array_size = bits_count / 4;
    if (bits_count % int_array_size != 0) {
        int_array_size++;
    }
    bit_array* b_array = (bit_array*) malloc(sizeof(bit_array));
    b_array->array = (int32_t*) malloc(sizeof(int) * int_array_size);
    return b_array;
}

void free_bit_array(bit_array* b_array) {
    free(b_array->array);
    free(b_array);
}

void set_bit(bit_array* b_array, size_t index) {
    b_array->array[index / 32] |= 1 << (index % 32);
}

void clear_bit(bit_array* b_array, size_t index) {
    b_array->array[index / 32] &= ~(1 << (index % 32));
}

bool check_bit(bit_array* b_array, size_t index) {
    if ((b_array->array[index / 32] & (1 << (index % 32)))) {
        return true;
    }
    return false;
}
