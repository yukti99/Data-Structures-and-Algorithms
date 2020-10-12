#include <stdio.h>
#include <stdlib.h>

//Inserting a Node Into a Sorted Doubly Linked List

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

void push(struct node** head,int item){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = item;
	n->prev = NULL;
	n->next = *head;
	if (*head != NULL){
		(*head)->prev = n;
	}
	*head = n;
}
void append(struct node **head,int item){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	struct node* temp = *head;
	n->data = item;
	n->next = NULL;
	if (*head ==  NULL){
		n->prev = NULL;
		*head = n;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;	
}
void insert(struct node**head,int item){
	struct node*n = (struct node*)malloc(sizeof(struct node));
	n->data = item;
	struct node* temp = *head;
	
	// empty list
	if (*head == NULL){
		n->next = *head;
		*head = n;
		n->prev = NULL;
		return ;
	}
	// in the beginning
	if (item <= (*head)->data){
		n->prev = NULL;
		n->next = *head;
		if(*head != NULL){
			(*head)->prev = n;
		}
		*head = n;
		return ;
	}
	
	while(temp->next!=NULL){
		if (item >= (temp->data) && (item) <= (temp->next->data))
			break;
		temp = temp->next;		
	}
	// in the end 
	if (temp->next == NULL){
		temp->next = n;
		n->next = NULL;
		n->prev = temp;
		return;
	}
	
	n->next  = temp->next;
	n->prev = temp;
	temp->next = n;
	
	// if insertion not happening in the end
	if (n->next != NULL){
		n->next->prev = n;
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
	push(&head,5);push(&head,4);push(&head,2);push(&head,1);
	append(&head,6);
	printList(head);
	insert(&head,0);
	insert(&head,3);
	insert(&head,7);
	printList(head);
	
	
	
	return 0;
}
