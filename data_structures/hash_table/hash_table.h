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
    // we need to mark deleted elements in case:
    // use less free operations: we just mark elem as deleted and then mark as occupied if we add same element again
    // searching: if we didn't have this state
    // we would need to rehash after each delete, it's better to explain with example:
    // let's add elements to table: add 1, add 2, ... add 10
    // for each element we add hash is counted so we have a sequence of counted and occupied by elements cells
    // when we search for some element we count hash for it and make same iteration like when we add it to table
    // if we don't mark a cell by delete state and just make it empty then search would stop because of this 'hole' in sequence
    // search looks for given key in cells until it finds it or cell with empty state
    // let's delete element: delete 6
    // let's search for 9 element: we suppose that when we added 9 after 6, 9 had same hash as 6 so we needed to make one more probing
    // for cell index of element 9. when we search for 9 element it checks first cell where 6 element was, if we did't have deleted state
    // and just empty, then search would stop and hash table would answer that there is no 9 element in table
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
