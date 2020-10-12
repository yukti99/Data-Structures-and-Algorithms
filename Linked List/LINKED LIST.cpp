/* Creating a linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data ; 
	struct Node* next ;
};

// This function prints contents of linked list starting from 
// the given node
void printlist(struct Node* n){
	
	while(n != NULL){
		printf("%d ",n->data);
		n  = n->next ;
	}
}
int main(){
	
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	
	// allocate three nodes in a heap
	head = (struct Node*)malloc(sizeof(struct Node));   // typecasting required as malloc returns a void pointer
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	printlist(head);
	
}
