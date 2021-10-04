#include "int_linked_list.h"

int_linked_list* create_int_linked_list(int data) {
    int_linked_list* list = (int_linked_list*)malloc(sizeof(int_linked_list));
    list->data = data;
    list->next = NULL;
    return list;
}

int_linked_list* push_back_int_linked_list(int data, int_linked_list* begin_pos) {
    int_linked_list* iter = begin_pos;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = create_int_linked_list(data);
    return iter->next;
}

int_linked_list* push_front_int_linked_list(int data, int_linked_list* begin_pos) {
    int_linked_list* new_front = create_int_linked_list(data);
    new_front->next = begin_pos;
    return new_front;
}

void free_int_linked_list(int_linked_list* head) {
    int_linked_list* iter = head;
    while (iter != NULL) {
        int_linked_list* node_to_delete = iter;
        iter = iter->next;
        free(node_to_delete);
    }
}

void traverse_int_linked_list(int_linked_list* head, void (*func)(int*)) {
    int_linked_list* iter = head;
    while (iter != NULL) {
        func(&iter->data);
        iter = iter->next;
    }
}
