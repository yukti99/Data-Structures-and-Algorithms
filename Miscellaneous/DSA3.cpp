/* Linked list implementation */

#include <stdio.h>
#include <stdlib.h>


struct Node{
	
	int data ;
	struct Node* next ;	
}*head;



void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

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
	while(temp!= NULL && temp->data != key){
		
		prev = temp;
		temp = temp->next;	
	}
	prev->next = temp->next;
	free(temp);
}
// for unsorted list
void remove_duplicate(){
	struct Node *p1 =head,*p2,*temp;
	
	while(p1 != NULL && p1->next !=NULL){
		
		p2 = p1;
		while(p2->next != NULL){
			if (p1->data == p2->next->data){
				temp = p2->next;
				p2->next = p2->next->next;
				free(temp);				
			}
			else
				p2 = p2->next;
			
		}
		p1 = p1->next;
	}
}

// for sorted list
void duplicate_sorted(){
	struct Node *p1 =head,*p2,*temp;
	
	while(p1 != NULL && p1->next !=NULL){
		
		p2 = p1;
		while(p2->next != NULL){
			if (p1->data == p2->next->data){
				temp = p2->next;
				p2->next = p2->next->next;
				free(temp);				
			}
			else
				break;
			
		}
		p1 = p1->next;
	}
}

void pairwise_swap(){
	
	struct Node *p1 = head;
	struct Node *p2 = p1->next ;
	while(p2 != NULL){
		int t = p1->data;
		p1->data = p2->data;
		p2->data = t;
		p1 = p2->next;
		if (p2->next == NULL)
			break;
		p2 = p1->next;
	}
	
}



// printing the linked list starting from the head node
void printList(struct Node* node){
	
	printf("\nLinked List : ");
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
}



// Driver program 
int main(){
	
	/*append(1);
	append(2);
	append(2);
	append(2);
	append(3);
	append(4);
	append(4);*/
	append(2);
	append(5);
	append(1);
	append(9);
	append(8);
	//append(7);
	printf("\nBefore Swapping : ");
	printList(head);
	pairwise_swap();
	printf("\nAfter Swapping : ");
	printList(head);
	//duplicate_sorted();
	//remove_duplicate();
	// 
	
	
	
	return 0;
}
