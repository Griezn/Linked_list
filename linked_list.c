//
// Created by seppe on 5/3/2023.
//

#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

void *create_linked_list(bool sorted) {
    struct linked_list *ll = malloc(sizeof(struct linked_list));
    ll->size = 0;
    ll->sorted = sorted;

    struct list_item *tail = malloc(sizeof(struct list_item));
    tail->data = 0;
    tail->next = NULL;

    struct list_item *head = malloc(sizeof(struct list_item));
    head->data = 0;
    head->next = tail;

    ll->head = head;
    ll->tail = tail;

    return ll;
}

void free_list(struct linked_list *ll) {
    struct list_item *p;
    for (int i = 0; i < ll->size; ++i) {
        p = ll->head->next;
        free(ll->head);
        ll->head = p;
    }

    free(ll->tail);
    free(ll);
}


inline void insert_normal(struct linked_list *ll, int item) {
    ll->tail->data = item;
    ll->tail->next = malloc(sizeof(struct list_item));
    ll->tail = ll->tail->next;
    ll->tail->data = 0;
    ll->tail->next = NULL;
    ll->size++;
}

struct list_item *search(const struct linked_list *ll, int item) {
    ll->tail->data = item;

    struct list_item *lst = ll->head->next;
    while (lst->data != item)
        lst = lst->next;

    if (lst != ll->tail)
        return lst;
    else
        return NULL;
}

void insert_sorted(struct linked_list *ll, int item) {
    struct list_item *p, *pp, *n, **lli;

    n = malloc(sizeof(struct list_item));
    n->data = item;

    lli = &ll->head->next;
    if (*lli == NULL || (*lli)->data == item) {
        n->next = *lli;
        *lli = n;
    } else {
        pp = *lli;
        p = pp->next;

        while ((p != NULL) && (p->data < item)) {
            pp = p;
            p = p->next;
        }

        n->next = p;
        pp->next = n;
    }
}

void insert_item(struct linked_list *ll, int item) {
    if (ll->sorted)
        insert_sorted(ll, item);
    else
        insert_normal(ll, item);
}