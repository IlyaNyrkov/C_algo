//
// Created by ilya on 13.01.2022.
//

#ifndef TEST_HASH_TABLE_H
#define TEST_HASH_TABLE_H
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef size_t (*hasher_func)(const char*, size_t capacity);
typedef enum hash_table_cell_state {
    EMPTY,
    OCCUPIED,
    DELETED,
} hash_table_cell_state;

typedef struct hash_table_cell {
    enum hash_table_cell_state cell_state;
    char* value;
} hash_table_cell;

typedef struct hash_table {
    hash_table_cell* table;
    size_t keys_count;
    size_t capacity;
    hasher_func hasher;
} hash_table;

bool has(hash_table* h_table, char* key);

// if tries to add elem present in h_table returns false
bool add(hash_table* h_table, char* key);

// if tries to delete non existent elem in h_table returns false
bool delete_key(hash_table* h_table, char* key);

// initial capacity for keys
hash_table* create_hash_table(size_t capacity, hasher_func hasher);

hash_table_cell* create_cell_table(size_t capacity);

void free_cell_table(hash_table_cell* cell_table, size_t capacity);

void free_hash_table(hash_table* h_table);

int resize(hash_table* h_table);

size_t gorner_hash(const char* value, size_t capacity);
#endif //TEST_HASH_TABLE_H
