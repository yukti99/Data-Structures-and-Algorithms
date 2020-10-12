#include <stdio.h>
#include <stdlib.h>

// Reverse in Groups
// Linked List Implementation

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head,int item){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->next = *head;
	*head = n;
}

void printList(struct Node* head){
	if (head == NULL){
		printf("\nEmpty!!\n");
		return ;
	}
	printf("\nLinked List : \n");
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}
// reversing whole list
void reverse(struct Node** head){
	struct Node *cur = *head,*prev = NULL,*next = NULL;
	while(cur != NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur  = next;
	}
	*head = prev;	
}
// reversing list in groups of size k
struct Node* reverseK(struct Node *head,int k){
	
	struct Node* cur = head,*prev = NULL,*next = NULL;
	int count = 0;
	while(cur != NULL && count < k){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}
	if (next!=NULL)
		head->next = reverseK(next,k);

	return prev;	
}
struct Node *Reverse (struct Node *head, int k) 
{ 
    struct Node* current = head; 
    struct Node* next = NULL; 
    struct Node* prev = NULL; 
    int count = 0;    
      
    /*reverse first k nodes of the linked list */ 
    while (current != NULL && count < k) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
      
    /* next is now a pointer to (k+1)th node  
       Recursively call for the list starting from current. 
       And make rest of the list as next of first node */
    if (next !=  NULL) 
       head->next = Reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev; 
} 
  

int main(){
	
	struct Node* head = NULL;
	push(&head,7);push(&head,6);push(&head,5);push(&head,4);push(&head,3);push(&head,2);push(&head,1);
	printList(head);
	Reverse(head,3);
	printList(head);	
	return 0;
}
