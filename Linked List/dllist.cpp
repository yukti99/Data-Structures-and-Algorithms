#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct Node{
	int data ;
	struct Node *next;
	struct Node *prev;
}*head;

// addition at the beginning
void push(int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	new_node->prev = NULL;
	if (head != NULL)
		head->prev = new_node;
	head = new_node;
}

//addition at the end
void append(int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = head;
	new_node->data = new_data;
	new_node->next = NULL;
	// if list is empty,make new node as the head
	if (head == NULL){
		new_node->prev = NULL;
		head = new_node;
		return ;
	}
	while(last->next != NULL)
		last = last->next;
	
	last->next = new_node;
	new_node->prev = last;
}
void insertAfter(int key, int new_data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = head;
	new_node->data = new_data;
	while(temp!= NULL && key != temp->data){
		temp = temp->next;
	}
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next = new_node;
	if (new_node->next !=  NULL)
		new_node->next->prev = new_node;	
}
void insertBefore(int key,int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
	new_node->data = new_data;
	
	while(temp != NULL && key != temp->next->data){
		temp = temp->next;
	}
	new_node->prev = temp->prev;
	new_node->next = temp;
	temp->prev = new_node;
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;

}

void printList(){
	
	printf("\nDoubly Linked List : ");
	struct Node *node = head, *last;
	while(node!=NULL){
		
		printf("%d ",node->data);
		last = node;
		node = node->next; 
	}
	printf("\nReverse Doubly Linked List : ");
	while(last != NULL){
		
		printf("%d ",last->data);
		last = last->prev;
	}
	
}



int main (){
	push(2);
	push(3);
	push(4);
	push(5);
	append(6);
	insertAfter(3,9);
	insertBefore(5,0);
	printList();
	
	
	return 0;
}
