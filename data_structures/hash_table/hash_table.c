#include "hash_table.h"

bool has(hash_table* h_table, char* key) {
    return false;
}

bool add(hash_table* h_table, char* key) {
    return false;
}

bool delete(hash_table* h_table, char* key) {
    return false;
}

hash_table* create_hash_table(size_t capacity, hasher_func hasher) {
    hash_table* h_table = (hash_table*) malloc(sizeof(hash_table));
    if (h_table == NULL) {
        return NULL;
    }
    if (hasher == NULL) {
        return NULL;
    }
    h_table->capacity = capacity;
    h_table->keys_count = 0;
    h_table->hasher = hasher;
    h_table->table = (hash_table_cell*)malloc(h_table->capacity * sizeof(hash_table_cell));
    return h_table;
}

void free_hash_table(hash_table* h_table) {
    if (h_table == NULL) {
        return;
    }
    if (h_table->table == NULL) {
        return;
    }
    free(h_table->table);
    free(h_table);
}

int resize(hash_table* h_table) {
    size_t new_capacity = h_table->capacity * 2;
    if (h_table->capacity == 0) {
        new_capacity = 4;
    }
    hash_table_cell* new_table = (hash_table_cell*)malloc(new_capacity * sizeof(hash_table_cell));
    for (size_t i = 0; i < h_table->capacity; ++i) {
        new_table[i] = h_table->table[i];
    }
    free(h_table->table);
    h_table->table = new_table;
    h_table->keys_count = h_table->capacity;
    h_table->capacity = new_capacity;
    return 0;
}

size_t gorner_hash(char* value, size_t capacity) {
    size_t index = 0;
    size_t i = 0;
    while (value[i] != '\0') {
        index = index * 7 + value[i];
    }
    return index % capacity;
}