/* Linked list implementation */

#include <stdio.h>
#include <stdlib.h>


struct Node{
	
	int data ;
	struct Node* next ;	
};
struct Node* head = NULL;

// insertion at the beginning
void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

// insertion in the middle 
void insertAfter(struct Node* prev_node,int new_data){
	
	if (NULL == prev_node){
		printf("Previous Node cannot be NULL\n");
		return ;
	}	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node ;
	
}
// insertion from the end
void append(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = head;
	new_node->next  = NULL;
	new_node->data = new_data;
	if (NULL == head){		
		head = new_node;
		return ;
	}
	while(NULL != last->next)
		last = last->next;
	last->next = new_node;
	return ;
}
//  deleting the first occurence of a given key from the list 
void deleteNode(int key){
	
	
	struct Node* temp = head;
	struct Node* prev ;
	// if head node is to be deleted
	if (temp != NULL && temp->data == key){
		head = temp->next;
		free(temp);
		return ;
	}
	while(temp!= NULL && temp->data != key){
		
		prev = temp;
		temp = temp->next;	
	}
	// key does not exist in the linked list
	if (NULL == temp)
		return ;
	prev->next = temp->next;
	free(temp);
}
// deletes the node at a particular position
void deletePos(int position){
	
	// linked list empty
	if (head == NULL)
		return ;
	
	struct Node* temp = head;
	
	// head to be deleted
	if (position == 0){
		head = temp->next;
		free(temp);
		return ;
	}
	// find previous node of the node to  be deleted
	for(int i=0; temp != NULL && i<position-1 ;i++)
		temp = temp->next;
	
	// if positon is more than number of nodes
	if (temp==NULL && temp->next== NULL)
		return;
	
	struct Node* next = temp->next->next ;
	free(temp->next);
	temp->next = next;
	return ;
	
}
// function to reverse a linked list (Iterative method)
void Reverse(){
	
	struct Node *prev=NULL,*current=head,*next=NULL;
	while(current != NULL ){
		next = current->next;
		current->next = prev;  // actual reversing
		prev = current;   // moving prev & current forward
		current = next;
	}
	head = prev;
}

// returns the position of the element to be the search else -1
int Search(int key){
	
	struct Node* temp = head;
	int index = 0;
	while( temp!=NULL && temp->data != key){
		index++;
		temp = temp->next;		
	}
	return (temp!=NULL?index:-1);
	
}

int length(){
	
	int l=0;
	struct Node* n = head;
	while(n!= NULL){
		l++;
		n = n->next ;
	}
	return l;
}


// printing the linked list starting from the head node
void printList(struct Node* node){
	
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
}



// Driver program 
int main(){
	
	append(2);
	append(5);
	push(1);
	insertAfter(head->next,4);
	insertAfter(head->next,3);
	push(0);
	append(6);
	printf("\nLinked List :");
	printList(head);
	printf("\nLength of linked list = %d",length());
	deletePos(6);
	deleteNode(0);
	printf("\nElement found at = %d",Search(3));
	printf("\nAfter deleting linked list is : ");
	printList(head);
	printf("\nLength of linked list = %d",length());
	Reverse();
	printf("\nAfter Reversing the linked list : ");
	printList(head);
	
	
	return 0;
}
