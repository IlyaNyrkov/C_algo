//
// Created by ilya on 17.01.2022.
//

#ifndef TEST_BLOOM_FILTER_H
#define TEST_BLOOM_FILTER_H

#include <stdlib.h>
#include <stdbool.h>
#include "bit_array.h"
typedef size_t (*hasher_func)(const char*, size_t);

typedef struct bloom_filter {
    bit_array b_array;
    hasher_func hasher;
} bloom_filter;

bloom_filter* create_bloom_filter(size_t number_of_expected_elements, hasher_func h_func);

void free_bloom_filter(bloom_filter* filter);

void add(bloom_filter* filter, char* key);

bool has_not(bloom_filter* filter, char* key);


#endif //TEST_BLOOM_FILTER_H
