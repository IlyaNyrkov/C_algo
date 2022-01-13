//
// Created by ilya on 13.01.2022.
//

#ifndef TEST_HASH_TABLE_H
#define TEST_HASH_TABLE_H
#include <stdbool.h>
#include "stdlib.h"

typedef size_t (*hasher_func)(char*);
typedef enum hash_table_cell_state {
    EMPTY,
    DELETED,
    OCCUPIED,
} cell_state;

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

bool has(hash_table* table, char* key);

// if tries to add elem present in table returns false
bool add(hash_table* table, char* key);

// if tries to delete non existent elem in table returns false
bool delete(hash_table* table, char* key);

// initial capacity for keys
hash_table* create_hash_table(size_t keys_count);

bool free_hash_table(hash_table* table);

int resize(hash_table* table);

#endif //TEST_HASH_TABLE_H
