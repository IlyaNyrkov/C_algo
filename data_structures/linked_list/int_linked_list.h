//
// Created by ilya on 04.10.2021.
//

#ifndef C_ALGO_INT_LINKED_LIST_H
#define C_ALGO_INT_LINKED_LIST_H
#include <stdlib.h>

typedef struct int_linked_list int_linked_list;

struct int_linked_list {
    int_linked_list* next;
    int data;
};

int_linked_list* create_int_linked_list(int data);

//return pointer to the tail of linked list
int_linked_list* push_back_int_linked_list(int data, int_linked_list* begin_pos);

//return point to the head of linked list
int_linked_list* push_front_int_linked_list(int data, int_linked_list* begin_pos);

//free memory from linked list
void free_int_linked_list(int_linked_list* head);

//traverse list and do something with every element
void traverse_int_linked_list(int_linked_list* head, void (*func)(int*));

#endif //C_ALGO_INT_LINKED_LIST_H
