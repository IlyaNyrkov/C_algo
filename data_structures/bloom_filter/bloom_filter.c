
#include "bloom_filter.h"
#include <stdlib.h>
#include <stdbool.h>
#include "bit_array.h"
typedef size_t (*hasher_func)(const char*);

typedef struct bloom_filter {
    bit_array b_array;
    hasher_func hasher;
} bloom_filter;

bloom_filter* create_bloom_filter(size_t number_of_expected_elements);

void free_bloom_filter(bloom_filter* filter);

void add(bloom_filter* filter, char* key);

bool has_not(bloom_filter* filter, char* key);


