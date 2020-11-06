#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define SIZE 5

int main() {
    int a[SIZE] = {1, 2, 3, 4, 5};
    LinkedList list;
    for (int i = 0; i < SIZE; i++) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->value = i;
        list_insert(&list, node);
    }
    list_print(&list);
    list_free(&list);
    printf("List size is %d", list_size(&list));
    return 0;
}
