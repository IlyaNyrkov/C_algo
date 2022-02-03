#ifndef C_ALGO_INT_LINKED_LIST_H
#define C_ALGO_INT_LINKED_LIST_H
#include <stdlib.h>

typedef struct linked_list linked_list;

struct linked_list {
    linked_list* next;
    int data;
};

linked_list* create_int_linked_list(int data);

//return pointer to the tail of linked list
linked_list* push_back_lin_lst(int data, linked_list* begin_pos);

//return point to the head of linked list
linked_list* push_front_lin_lst(int data, linked_list* begin_pos);

//free memory from linked list
void free_linked_list(linked_list* head);

//traverse list and do something with every element
void traverse_lin_lst(linked_list* head, void (*func)(int*));

#endif //C_ALGO_INT_LINKED_LIST_H
