#include "gtest/gtest.h"
#include "time.h"
extern "C" {
#include "hash_table.h"
}

void print_strings(char** numbers_separated, size_t number_cnt) {
    for (size_t i = 0; i < number_cnt; ++i) {
        printf("%s", numbers_separated[i]);
    }
}

char** generate_strings(size_t number_cnt, size_t number_size) {
    char** numbers_separated = (char**) malloc(number_cnt * sizeof(char*));
    for (size_t i = 0; i < number_cnt; ++i) {
        char* number = (char*) malloc((number_size + 1) * sizeof(char));
        number[number_size] = '\0';
        for (size_t j = 0; j < number_size; ++j) {
            number[j] = 'a' + rand() % 50;
        }
        numbers_separated[i] = number;
    }
    return numbers_separated;
}

void free_strings(char** strings, size_t number_cnt) {
    for (size_t i = 0; i < number_cnt; ++i) {
        free(strings[i]);
    }
    free(strings);
}

void print_hash_keys(hash_table* h_table) {
    size_t key_count = 0;
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[i].cell_state == OCCUPIED && h_table->table[i].value != NULL) {
            printf("%zu %s\n", i, h_table->table[i].value);
            key_count++;
        }
    }
}

TEST(hash_table, adding_and_checking) {

    hash_table* h_table = create_hash_table(8, gorner_hash);
    const size_t number_cnt = 1000;
    const size_t number_size = 100;
    char** numbers_separated = generate_strings(number_cnt, number_size);
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(add(h_table, numbers_separated[i]));
    }

    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(has(h_table, numbers_separated[i]));
    }
    free_strings(numbers_separated, number_cnt);
    free_hash_table(h_table);
}

TEST(cell_table, create_free) {
    const size_t size = 10;
    hash_table_cell* table = create_cell_table(size);
    free_cell_table(table, size);
    ASSERT_TRUE(1);
}

TEST(hash_table, create_delete) {
    hash_table* table = create_hash_table(10, gorner_hash);
    free_hash_table(table);
    ASSERT_TRUE(1);
}

TEST(hash_table, adding_deleting_checking) {
    hash_table* h_table = create_hash_table(8, gorner_hash);
    const size_t number_cnt = 1000;
    const size_t number_size = 100;
    char** numbers_separated = generate_strings(number_cnt, number_size);
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(add(h_table, numbers_separated[i]));
    }
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(has(h_table, numbers_separated[i]));
        ASSERT_TRUE(delete_key(h_table, numbers_separated[i]));
        ASSERT_FALSE(has(h_table, numbers_separated[i]));
    }
    free_strings(numbers_separated, number_cnt);
    free_hash_table(h_table);
}

TEST(hash_table, adding_deleting_alternating_checking) {
    hash_table* h_table = create_hash_table(8, gorner_hash);
    const size_t number_cnt = 1000;
    const size_t number_size = 100;
    char** numbers_separated = generate_strings(number_cnt, number_size);
    for (size_t i = 0; i < number_cnt; ++i) {
        ASSERT_TRUE(add(h_table, numbers_separated[i]));
        ASSERT_TRUE(delete_key(h_table, numbers_separated[i]));
        ASSERT_FALSE(has(h_table, numbers_separated[i]));
    }
    free_strings(numbers_separated, number_cnt);
    free_hash_table(h_table);
}