/* CIRCULAR LINKED LIST
we take a pointer to the last node of the list and the first node if always the next of the last node  
i.e. first = last->next 
we have taken the last node so that the insertion in the beginning or at the end takes constant 
time irrespective of the length of the list.

Insertion
A node can be added in three ways:

Insertion in an empty list
Insertion at the beginning of the list
Insertion at the end of the list
Insertion in between the nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;
	struct Node *next;
	
};

// for insertion in an empty list
struct Node* addToEmpty(struct Node *last,int data){
	
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	last = temp;
	last->next = last;
	return last;
	
}

// for insertion at the beginning of the list
struct Node* push(struct Node *last,int data){ 	

	// if the list is Empty
	if (last == NULL){		
		return addToEmpty(last,data); 				
	}
	
	// if list is not  empty
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));	
	n->data = data;
	n->next = last->next;
	last->next = n ;        // last points to the first node and now n is the new first node 
	return last;	
	
}

// for insertion at the beginning of the list
struct Node* append(struct Node* last,int data){
	
	// if list is Empty
	if (last == NULL){		
		return addToEmpty(last,data); 			
	}
	
	// if list is not empty
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));	
	n->data = data;
	n->next = last->next;
	last->next = n;
	last = n; 
	return last;	
}
// for insertion in between the nodes
struct Node* insertAfter(struct Node *last,int item,int data){
	
	if (last == NULL){
		printf("\nThe list cannot be Empty!\n");
		return NULL;
	}
	struct Node *p = last->next,*temp ;    // p points to the first node
	do{
		if (p->data == item){
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = p->next;
			p->next = temp;
			
			if (p == last)
				last = temp;
			return last;
			
		}
		p = p->next;
	}
	while(p != last->next);
	
	printf("\nThe item is not present in the list!\n");
	return last; 
	
}


void printList(struct Node *last){ 	
	
	if (last == NULL){
		printf("\nThe List is Empty!!\n");
		return ; 
	}
	struct Node *first = last->next;   // to start from the first node
	
	do{
		printf("%d ",first->data);
		first = first->next;
	}
	while(first != last->next); 
	printf("\n");	
}
int main(){
	
	struct Node *last = NULL;
	int n,x,i;
	printf("Enter the no of elements in Circular Linked List : ");
	scanf("%d",&n);
	printf("\nEnter the Elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		last = push(last,x);		
	} 
    printf("Circular Linked List : \n");
    printList(last);
    printf("Enter the item you want to insert = ");
    scanf("%d",&x);
    printf("Enter the item after which you want insertion = ");
    scanf("%d",&i);
    last = insertAfter(last,i,x);
     

	
	return 0;
}
