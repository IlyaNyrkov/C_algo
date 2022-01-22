#include "gtest/gtest.h"
extern "C" {
    #include "bloom_filter.h"
}

size_t gorner_hash(const char* key, size_t capacity) {
    size_t hash_value = 0;
    size_t ind = 0;
    while (key[ind] != '\0') {
        hash_value += hash_value * 7 + key[ind];
    }
    return hash_value % capacity;
}

TEST(bloom_filter, alocating) {
    bloom_filter* b_filer = create_bloom_filter(10, gorner_hash);
    ASSERT_TRUE(1);
    free(b_filer);
}