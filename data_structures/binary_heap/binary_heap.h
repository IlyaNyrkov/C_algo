
#ifndef TEST_BINARY_HEAP_H
#define TEST_BINARY_HEAP_H
#include <stdbool.h>
#include <stdlib.h>
typedef bool (*compare_func)(int*, int*);

typedef struct binary_heap {
    compare_func c_func;
    int* buffer;
    size_t buffer_size;
    size_t size;
} binary_heap;

binary_heap* create_binary_heap(const int* arr, size_t size, compare_func comp_func);

void free_binary_heap(binary_heap* heap);

int extract_max(binary_heap* heap);

int* peek_max(const binary_heap* heap);

void grow_buffer(binary_heap* heap);

#endif
