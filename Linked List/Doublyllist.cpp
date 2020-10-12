#include <stdio.h>
#include <stdlib.h>


// Node of a doubly linked list
struct Node{
	
	int data;
	struct Node* prev;
	struct Node* next;
}*head;

// Adding a node in the front
void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;	
	new_node->next = head;
	new_node->prev = NULL;
	if (head != NULL)
		head->prev = new_node;
	head = new_node;
}
// Adding a node at the  end
void append(int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = head ;
	new_node->data = new_data;
	new_node->next = NULL;
	// if the list is empty make the new node as the head node
	if (head == NULL){
		new_node->prev = NULL;
		head = new_node;
		return ;		
	}
	// else traverse till the end
	while(last->next!=NULL)
		last = last->next ;

	last->next = new_node;
	new_node->prev = last;

}
// adding a node after a particular node
void insertAfter(int key, int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *node = head;
	new_node->data = new_data;
	while(node != NULL && node->data != key ){
		node = node->next;
	}
	new_node->next = node->next;	
	node->next = new_node;
	new_node->prev = node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	
}
void insertBefore(int key,int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *next_node = head;
	new_node->data = new_data;
	// key is the head node
	if (head->data == key){
		new_node->prev = NULL;
		new_node->next = head;
		head = new_node;
		return ;
	}
	while(next_node!= NULL && next_node->data != key){
		next_node = next_node->next;
	}	
	
	new_node->prev = next_node->prev;
	next_node->prev = new_node;
	new_node->next = next_node;
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	
	
}
// deleting a particular element from linked list
void deleteNode(int key){
	struct Node *temp = head;
	
	// if head node to be deleted 	
	if (temp->data == key)
		head = temp->next;
				
	
	while(temp != NULL && temp->data != key)
		temp = temp->next;
	
	// change next if the node to be deleted is NOT last node
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	
	//change prev only if node to be deleted is NOT first node
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	// free memory occupied by temp	
	free(temp);
	
	
}

void reverseList(){
	struct Node *current,*next,*prev;
	if (head == NULL)
		return;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = current->prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	head = prev;	
}
void length(){
	int c=0;
	struct Node* temp = head;
	while(temp!=NULL){
		c++;
		temp = temp->next;
	}
	printf("\nLength of the Double Linked list is : %d\n",c);
	
}
void printList(){
	
	printf("\nDoubly Linked List : ");
	struct Node *node = head, *last;
	while(node!=NULL){
		
		printf("%d ",node->data);
		last = node;
		node = node->next; 
	}
	/*
	printf("\nReverse Doubly Linked List : ");
	while(last != NULL){
		
		printf("%d ",last->data);
		last = last->prev;
	}*/
	
}


int main(){
	
	push(3);
	push(2);
	push(1);
	append(5);
	insertAfter(3,4);
	deleteNode(2);
	printList();
	//insertBefore(1,8);
	printf("\nAfter reversing\n");
	reverseList();
	printList();
	length();	
	
	return 0;
}
