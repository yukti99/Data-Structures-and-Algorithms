/* Linked list implementation */

#include <stdio.h>
#include <stdlib.h>


struct Node{
	
	int data ;
	struct Node* next ;	
};
struct Node* head = NULL;

// printing the linked list starting from the head node
void printList(struct Node* node){
	
	printf("\nLinked List :");	
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
}


// insertion at the beginning
void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;

}

// Insertion in the middle
void insertAt(int position,int new_data){
	printf("\nLinked List after insertion of value %d at position %d : ",new_data,position);
	int counter=0;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
	if (temp == NULL){
		printf("The linked list cannot be empty\n");
		return;
	}
	new_node->data = new_data;
	if (counter != position){
		counter++;
		temp = temp->next;
	}
	temp = temp->next;
	new_node->next = temp->next;
	temp->next = new_node;
	printList(head);
	
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
void delete(int key){
	
	
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


// Driver program 
int main(){
	
	int i,n,x,d,s,a,b,c,p;	
	printf("Enter the number of elements you want in linked list = ");
	scanf("%d",&n);
	printf("Enter Linked list elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		append(x);
	}	
	printList(head);
	printf("\nEnter the element you want to insert at beginning = ");
	scanf("%d",&a);
	push(a);
	printList(head);
	printf("\nEnter the element you want to insert at end = ");
	scanf("%d",&b);
	append(b);
	printList(head);
	printf("\nEnter the element to be inserted in the middle = ");
	scanf("%d",&c);
	printf("\nEnter the position = ");
	scanf("%d",&p);
	insertAt(p,c);
	printf("\nEnter the element you want to delete = ");
	scanf("%d",&d);
	delete(d);
	printf("\nAfter deleting linked list is : ");
	printList(head);	
	printf("\nEnter the element you want to search = ");
	scanf("%d",&s);
	printf("\nElement found at index = %d\n",Search(s));
	
	return 0;
}
