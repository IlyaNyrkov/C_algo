#include "gtest/gtest.h"

extern "C" {
#include "hash_table.h"
}

TEST(hash_table_add, adding_and_checking) {
    hash_table* h_table = create_hash_table(8, gorner_hash);
    size_t number_cnt = 3;
    size_t number_size = 10;
    char** numbers = (char**)malloc(number_cnt * sizeof(char));
    for (size_t i = 0; i < number_cnt; ++i) {
        numbers[i] = (char*) malloc(number_size);
    }
    strcpy(numbers[0], "one\0");
    strcpy(numbers[1], "two\0");
    strcpy(numbers[2], "three\0");
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(add(h_table, numbers[i]));
    }
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(has(h_table, numbers[i]));
    }
    free_hash_table(h_table);
}
