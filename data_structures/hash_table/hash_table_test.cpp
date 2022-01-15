#include "gtest/gtest.h"

extern "C" {
#include "hash_table.h"
}

TEST(hash_table_add, adding_and_checking) {
    hash_table* h_table = create_hash_table(8, gorner_hash);
    const size_t number_cnt = 12;
    const size_t number_size = 3;
    char** numbers_separated = (char**) malloc(number_cnt * sizeof(char*));
    for (size_t i = 0; i < number_cnt; ++i) {
        char* number = (char*) malloc((number_size + 1) * sizeof(char));
        number[number_size] = '\0';
        for (size_t j = 0; j < number_size; ++j) {
            number[j] = 'a' + (j + i * i) % 20;
        }
        numbers_separated[i] = number;
    }
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(add(h_table, numbers_separated[i]));
    }
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(has(h_table, numbers_separated[i]));
    }
    free_hash_table(h_table);
}
