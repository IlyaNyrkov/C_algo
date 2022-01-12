#include "dynamic_array.h"


dynamic_array* make_dynamic_array(int capacity) {
    dynamic_array* array = (dynamic_array*) malloc(sizeof(dynamic_array));
    array->data = (int*) malloc(capacity);
    array->capacity = capacity;
    array->size = 0;
    return array;
}

int push_back(dynamic_array* array, int data) {
    if (array == NULL) {
        return NULL_ARRAY_ERR;
    }
    if (array->data == NULL) {
        return NULL_DATA_IN_ARRAY_ERR;
    }
    if (array->size + 1 > array->capacity) {
        int new_size = array->capacity * 2;
        if (array->capacity == 0) {
            array->capacity = 1;
        }
        if (resize(array, new_size) == MEM_ALLOC_ARRAY_ERR) {
            return ARR_RESIZE_ERR;
        };
    }
    array->data[array->size] = data;
    array->size += 1;
    return SUCCESS;
}

int pop_back(dynamic_array* array) {
    if (array->size == 0) {
        return EMPTY_ARRAY_POP;
    }
    array->size -= 1;
    return SUCCESS;
}

int free_dynamic_array(dynamic_array* array) {
    if (array == NULL) {
        return NULL_ARRAY_ERR;
    }
    if (array->data == NULL) {
        return NULL_DATA_IN_ARRAY_ERR;
    }
    free(array->data);
    free(array);
    return SUCCESS;
}

int resize(dynamic_array* array, int new_size) {
    int* new_data = (int*)malloc(sizeof(int) * new_size);
    if (new_data == NULL) {
        return MEM_ALLOC_ARRAY_ERR;
    }
    for (int i = 0; i < array->size; ++i) {
        new_data[i] = array->data[i];
    }
    free(array->data);
    array->data = new_data;
    array->capacity = new_size;
    return SUCCESS;
}
