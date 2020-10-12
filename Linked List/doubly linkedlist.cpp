// A complete working C program to demonstrate all
// insertion before a given node
#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}
 
/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct Node* next_node, int new_data)
{
    /*1. check if the given new_node is NULL */
    if (next_node == NULL) {
        printf("the given next node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make prev of new node as prev of next_node */
    new_node->prev = next_node->prev;
 
    /* 5. Make the prev of next_node as new_node */
    next_node->prev = new_node;
 
    /* 6. Make next_node as next of new_node */
    new_node->next = next_node;
 
    /* 7. Change next of new_node's previous node */
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
}
 
// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    push(&head, 7);
 
    push(&head, 1);
 
    push(&head, 4);
 
    // Insert 8, before 1. So linked list becomes 4->8->1->7->NULL
    insertBefore(head->next, 8);
 
    printf("Created DLL is: ");
    printList(head);
 
    getchar();
    return 0;
}
// A complete working C program to demonstrate all insertion methods
#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 3. put in the data  */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;
 
    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;
 
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
 
/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    struct Node* last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->data = new_data;
 
    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
 
    return;
}
 
// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);
 
    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);
 
    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);
 
    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    append(&head, 4);
 
    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
 
    printf("Created DLL is: ");
    printList(head);
 
    getchar();
    return 0;
}

