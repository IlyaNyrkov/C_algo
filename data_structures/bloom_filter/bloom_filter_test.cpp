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
    bloom_filter* filter = create_bloom_filter(10, gorner_hash);
    ASSERT_TRUE(1);
    free_bloom_filter(filter);
}

TEST(bloom_filter, adding_and_checking) {
    bloom_filter* filter = create_bloom_filter(10, gorner_hash);
    char test_str[5] = "test";
    ASSERT_TRUE(has_not(filter, test_str));
    char test_str2[5] = "abcd";
    add(filter, test_str2);
    ASSERT_TRUE(has_not(filter, test_str));
    ASSERT_FALSE(has_not(filter, test_str2));
    free_bloom_filter(filter);
}