typedef struct Node {
    int value;
    struct Node *next;
} ListNode;

typedef struct {
    ListNode *head;
} LinkedList;


/**
* Insert a value to the list at the head
*/
void list_insert(LinkedList *list, ListNode *v);

/**
* List searching
* return a pointer to found item or NULL if not found
*/

ListNode *list_search(LinkedList *list, int key);

void list_print(LinkedList *list);

int list_size(LinkedList *list);

/**
* Delete at the head of the list
*/
void list_delete(LinkedList *list);

void list_free(LinkedList *list);
