
#ifndef TEST_BINARY_HEAP_H
#define TEST_BINARY_HEAP_H
#include <stdbool.h>
#include <stdlib.h>
#include "dynamic_array.h"
typedef bool (*compare_func)(const int*, const int*);

typedef struct binary_heap {
    compare_func c_func;
    dynamic_array* array;
} binary_heap;

binary_heap* create_binary_heap(const int* arr, size_t size, compare_func comp_func);

void free_binary_heap(binary_heap* heap);

int extract_max(binary_heap* heap);

int* peek_max(const binary_heap* heap);

void insert(binary_heap* heap, const int elem);

void build_heap(binary_heap* heap);

void sift_down(int i); // if parent is small then children

void sift_up(int); /// if child is bigger than parent

#endif
