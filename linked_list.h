//
// Created by seppe on 5/3/2023.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

struct list_item {
    int data;
    struct list_item *next;
};

struct linked_list {
    size_t size;
    bool sorted;

    struct list_item *head;
    struct list_item *tail;
};

void *create_linked_list(bool sorted);

void free_list(struct linked_list *ll);

void insert_item(struct linked_list *ll, int item);

struct list_item *search(const struct linked_list *ll, int item);

#endif //LINKED_LIST_H
