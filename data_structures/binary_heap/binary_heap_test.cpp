#include "gtest/gtest.h"
extern "C" {
#include "binary_heap.h"
}

void fill_arr(int* arr, size_t arr_size) {
    for (size_t i = 0; i < arr_size; ++i) {
        arr[i] = (int)i;
    }
}

bool less(const int* left, const int* right) {
    return *left < *right;
}

TEST(binary_heap, peeking_extracting) {
    const size_t arr_size = 10;
    int arr[arr_size];
    binary_heap* b_heap = create_binary_heap(arr, arr_size, less);
    for (size_t i = arr_size - 1; i > 0; ++i) {
        ASSERT_EQ(peek_max(b_heap), i);
        ASSERT_EQ(extract_max(b_heap), i);
    }
    free_binary_heap(b_heap);
}