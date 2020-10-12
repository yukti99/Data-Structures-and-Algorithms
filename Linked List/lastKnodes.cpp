/* Last k nodes of a linked list in reverse order */

#include <stdio.h>
#include <stdlib.h>


struct Node{	
	int data ;
	struct Node* next ;	
};
struct Node* head = NULL;


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

void lastKnodes(struct Node* node,int *k){
	if (node == NULL)	
		return ;
	lastKnodes(node->next,k);
	if (*k>0){
		printf("%d ",node->data);
		*k = *k-1;
	}
	
}
// printing the linked list starting from the head node
void printList(struct Node* node){
	
	printf("\nLinked List : ");
	while(NULL != node){
		printf("%d->",node->data);
		node = node->next;		
	}
	printf("NULL\n");
}

// Driver program 
int main(){
	
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	append(6);
	printList(head);
	int k = 4;
	printf("\nLast K nodes : ");
	lastKnodes(head,&k);
	
	
	return 0;
}
