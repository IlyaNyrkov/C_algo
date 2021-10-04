#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void fill_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
}

void print_array(int* array, int size) {
    printf("{");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("}");
}

void test_array_func(int* array, int size, void (*arr_func)(int*, int)) {
    arr_func(array, size);
    print_array(array, size);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int));
    test_array_func(array, n, fill_array);
    free(array);
    array = NULL;
    return 0;
}
