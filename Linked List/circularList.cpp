/* CIRCULAR LINKED LIST  */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node **head,int data){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *head;
	n->data = data;
	n->next = *head;
	
	//if list is empty
	if (NULL == *head){
		n->next = n ;
		*head = n;
		return ;
	}
	while(temp->next != *head){
		temp = temp->next;
	}
	temp->next = n;
	*head = n;	
}
void printList(struct Node* head){
	struct Node* n = head;
	if (head == NULL)
		return ;
	do{
		printf("%d ",n->data);
		n = n->next ;
		
	}while(n != head);
	printf("\n");
}

int main(){
	
	struct Node* head = NULL;
	push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("Circular Linked List : \n ");
    printList(head);
	
	
	return 0;
}
