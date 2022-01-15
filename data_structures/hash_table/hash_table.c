#include "hash_table.h"

bool has(hash_table* h_table, char* key) {
    size_t index = h_table->hasher(key, h_table->capacity);
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[index].cell_state == OCCUPIED) {
            if (strcmp(h_table->table[index].value, key) == 0) {
                return true;
            }
        } else {
            return false;
        }
        index = (index + i + 1) % h_table->capacity;
    }
    return false;
}

bool add(hash_table* h_table, char* key) {
    if (h_table->capacity * 3 / 4 < h_table->keys_count + 1) {
        resize(h_table);
    }
    size_t index = h_table->hasher(key, h_table->capacity);
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[index].cell_state != OCCUPIED) {
            if (h_table->table[index].value == NULL) {
                break;
            }
            if (strcmp(h_table->table[index].value, key) == 0) {
                return false;
            }
            break;
        }
        index = (index + i + 1) % h_table->capacity;
    }

    h_table->table[index].value = (char*)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(h_table->table[index].value, key);
    h_table->table[index].cell_state = OCCUPIED;
    h_table->keys_count++;
    return true;
}

bool delete_key(hash_table* h_table, char* key) {
    size_t index = h_table->hasher(key, h_table->capacity);
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[index].cell_state == OCCUPIED) {
            if (strcmp(h_table->table[index].value, key) == 0) {
                h_table->table[index].cell_state = EMPTY;
                free(h_table->table[index].value);
                h_table->table[index].value = NULL;
                return true;
            }
        } else {
            return false;
        }
        index = (index + i + 1) % h_table->capacity;
    }
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
    for (size_t i =0; i < h_table->capacity; ++i) {
        h_table->table[i].cell_state = EMPTY;
        h_table->table[i].value = NULL;
    }
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
    for (size_t i = 0; i < new_capacity; ++i) {
        h_table->table[i].cell_state = EMPTY;
        h_table->table[i].value = NULL;
    }
    hash_table_cell* prev_table = h_table->table;
    h_table->table = new_table;
    size_t prev_table_capacity = h_table->capacity;
    h_table->capacity = new_capacity;
    h_table->keys_count = 0;
    size_t i = 0;
    for (i = 0; i < prev_table_capacity; ++i) {
        if (prev_table[i].cell_state == OCCUPIED) {
            add(h_table, prev_table[i].value);
        }
    }

    free(prev_table);
    return 0;
}

size_t gorner_hash(char* value, size_t capacity) {
    size_t index = 0;
    size_t i = 0;
    while (value[i] != '\0') {
        index = index * 7 + value[i];
        i++;
    }
    return index % capacity;
}
