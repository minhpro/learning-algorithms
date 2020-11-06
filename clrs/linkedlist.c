#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void list_print(LinkedList *list) {
    ListNode *i = list->head;
    while (i != NULL) {
        printf("%d->", i->value);
        i = i->next;
    }
    printf("\n");
}

void list_insert(LinkedList *list, ListNode *v) {
    v->next = list->head;
    list->head = v;
}

int list_size(LinkedList *list) {
    int t = 0;
    ListNode *i = list->head;
    while (i != NULL && t < 1000) {
        t++;
        i = i->next;
    }

    return t;
}

void list_delete(LinkedList *list) {
    if (list->head != NULL) {
        ListNode *t = list->head;
        list->head = list->head->next;
        free(t);
    }
}

void list_free(LinkedList *list) {
    while (list->head != NULL) {
        list_delete(list);
    }
}
