#include "int_linked_list.h"

int_linked_list* create_int_linked_list(int data) {
    int_linked_list* list = (int_linked_list*)malloc(sizeof(int_linked_list));
    list->data = data;
    list->next = NULL;
    return list;
}
