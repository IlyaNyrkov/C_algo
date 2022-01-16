#include "hash_table.h"

bool has(hash_table* h_table, char* key) {
    size_t index = h_table->hasher(key, h_table->capacity);
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[index].cell_state == OCCUPIED) {
            if (strcmp(h_table->table[index].value, key) == 0) {
                return true;
            }
        } else if (h_table->table[index].cell_state == EMPTY){
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
        if (h_table->table[index].cell_state == DELETED) {
            if (h_table->table[index].value != NULL) {
                if (strcmp(h_table->table[index].value, key) != 0) {
                    free(h_table->table[index].value);
                    h_table->table[index].value = (char *) malloc((strlen(key) + 1) * sizeof(char));
                    strcpy(h_table->table[index].value, key);
                }
            }
            h_table->table[index].cell_state = OCCUPIED;
            h_table->keys_count++;
            return true;
        }
        if (h_table->table[index].cell_state == EMPTY) {
            h_table->table[index].value = (char*)malloc((strlen(key) + 1) * sizeof(char));
            strcpy(h_table->table[index].value, key);
            h_table->table[index].cell_state = OCCUPIED;
            h_table->keys_count++;
            return true;
        }
        if (h_table->table[index].cell_state == OCCUPIED &&
            h_table->table[index].value != NULL &&
            strcmp(h_table->table[index].value, key) == 0) {
            return false;
        }
        index = (index + i + 1) % h_table->capacity;
    }
    return false;
}

bool delete_key(hash_table* h_table, char* key) {
    size_t index = h_table->hasher(key, h_table->capacity);
    for (size_t i = 0; i < h_table->capacity; ++i) {
        if (h_table->table[index].value != NULL && strcmp(h_table->table[index].value, key) == 0) {
            switch (h_table->table[index].cell_state) {
                case OCCUPIED: {
                    h_table->table[index].cell_state = DELETED;
                    h_table->keys_count--;
                    return true;
                }
                case EMPTY:
                    break;
                case DELETED:
                    return false;
            }
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
    h_table->table = create_cell_table(h_table->capacity);
    return h_table;
}

hash_table_cell* create_cell_table(size_t capacity) {
    hash_table_cell* cell_table = (hash_table_cell*)malloc(capacity * sizeof(hash_table_cell));
    for (size_t i = 0; i < capacity; ++i) {
        cell_table[i].cell_state = EMPTY;
        cell_table[i].value = NULL;
    }
    return cell_table;
}

void free_cell_table(hash_table_cell* cell_table, size_t capacity) {
    for (size_t i = 0; i < capacity; ++i) {
        if (cell_table[i].value != NULL) {
            free(cell_table[i].value);
        }
    }
    free(cell_table);
}

void free_hash_table(hash_table* h_table) {
    if (h_table == NULL) {
        return;
    }
    if (h_table->table == NULL) {
        return;
    }
    free_cell_table(h_table->table, h_table->capacity);
    free(h_table);
}

int resize(hash_table* h_table) {
    size_t new_capacity = h_table->capacity * 2;
    if (h_table->capacity == 0) {
        new_capacity = 4;
    }
    hash_table_cell* new_table = create_cell_table(new_capacity);
    hash_table_cell* prev_table = h_table->table;
    h_table->table = new_table;
    size_t prev_table_capacity = h_table->capacity;
    h_table->capacity = new_capacity;
    h_table->keys_count = 0;
    for (size_t i = 0; i < prev_table_capacity; ++i) {
        if (prev_table[i].cell_state == OCCUPIED) {
            add(h_table, prev_table[i].value);
        }
    }

    free_cell_table(prev_table, prev_table_capacity);
    return 0;
}

size_t gorner_hash(const char* value, size_t capacity) {
    size_t index = 0;
    size_t i = 0;
    while (value[i] != '\0') {
        index = index * 7 + value[i];
        i++;
    }
    return index % capacity;
}
