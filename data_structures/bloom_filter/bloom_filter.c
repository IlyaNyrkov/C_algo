
#include "bloom_filter.h"

bloom_filter* create_bloom_filter(size_t number_of_expected_elements, hasher_func h_func) {
    bloom_filter* filter = (bloom_filter*) malloc(sizeof(bloom_filter));
    filter->b_array = create_bit_array(number_of_expected_elements);
    filter->hasher = h_func;
    return filter;
}

void free_bloom_filter(bloom_filter* filter) {
    if (filter == NULL) {
        return;
    }
    if (filter->b_array == NULL) {
        free(filter);
        return;
    }
    free_bit_array(filter->b_array);
    free(filter);
}

void add(bloom_filter* filter, char* key) {
    size_t index = filter->hasher(key, filter->b_array->bits_count);
    set_bit(filter->b_array, index);
}

bool has_not(bloom_filter* filter, char* key) {
    size_t index = filter->hasher(key, filter->b_array->bits_count);
    return !check_bit(filter->b_array, index);
}
