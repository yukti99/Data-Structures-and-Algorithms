/*
Swap the alternate nodes in a doubly linked list 
Eg: 1 2 3 4 5 6
	3 2 1 4 5 6 
	3 4 1 2 5 6
	3 4 5 2 1 6
	3 4 5 6 1 2
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

void append(struct node** head,int data){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	struct node* temp = *head;
	n->data = data;
	n->next = NULL;
	// list is empty
	if (NULL == *head){
		n->prev = NULL;
		*head = n;
		return ;		
	}
	while(NULL != temp->next){
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
	
}

void AltNodes(struct node* head){
	struct node *p1 = head,*p2 = p1;
	while(p2->next != NULL){
		p2 = p1->next->next;
		// swapping p1 and p2
		int t = p1->data;
		p1->data = p2->data;
		p2->data = t;
		p1 = p1->next;		
	}	
}
void printList(struct node* head){
	struct node* n = head;
	while(n!=NULL){
		printf("%d ",n->data);
		n = n->next;
	}
	printf("\n");
}

int main(){
	
	struct node* head = NULL;
	append(&head,1);append(&head,2);append(&head,3);append(&head,4);append(&head,5);append(&head,6);
	printList(head);
	AltNodes(head);
	printList(head);
	
	return 0;
}
