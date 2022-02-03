#include "linked_list.h"

linked_list* create_int_linked_list(int data) {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->data = data;
    list->next = NULL;
    return list;
}

linked_list* push_back_lin_lst(int data, linked_list* begin_pos) {
    linked_list* iter = begin_pos;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = create_int_linked_list(data);
    return iter->next;
}

linked_list* push_front_lin_lst(int data, linked_list* begin_pos) {
    linked_list* new_front = create_int_linked_list(data);
    new_front->next = begin_pos;
    return new_front;
}

void free_linked_list(linked_list* head) {
    linked_list* iter = head;
    while (iter != NULL) {
        linked_list* node_to_delete = iter;
        iter = iter->next;
        free(node_to_delete);
    }
}

void traverse_lin_lst(linked_list* head, void (*func)(int*)) {
    linked_list* iter = head;
    while (iter != NULL) {
        func(&iter->data);
        iter = iter->next;
    }
}
