/* Linked list implementation */

#include <stdio.h>
#include <stdlib.h>


struct Node{
	
	int data ;
	struct Node* next ;	
};
struct Node *list1 = NULL,*list2 = NULL ;


// printing the linked list starting from the head node
void printList(struct Node* node){
	
	printf("\nLinked List :");	
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
	printf("\n");
}

// to create linked list
void append(struct Node** head,int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head;
	new_node->next  = NULL;
	new_node->data = new_data;
	if (NULL == *head){		
		*head = new_node;
		return ;
	}
	while(NULL != last->next)
		last = last->next;
	last->next = new_node;
	return ;
}

/* Since head of first node never changes and that of second one
may change so double pointer required for second but single for the first
*/

void merge(struct Node* l1,struct Node** l2){

	
	struct Node *l1_cur = l1, *l1_next;
	struct Node *l2_cur = *l2, *l2_next;
	
	// while there are available positions in list1
	while(l1_cur != NULL && l2_cur != NULL){
		
		//storing next pointers
		l1_next = l1_cur->next;
		l2_next = l2_cur->next;
		
		//Make l1_cur as next of l2_cur
		l2_cur->next = l1_next;
		l1_cur->next = l2_cur;
		
		// Update current pointers for next iteration
		l1_cur = l1_next;
		l2_cur = l2_next;		
	}
	// Update head pointer of second list
	*l2 = l2_cur;
	
	
	

}



// Driver program 
int main(){
	
	int i,n1,n2,x1,x2;
	
	printf("Enter the number of elements you want in linked list 1 = ");
	scanf("%d",&n1);
	printf("Enter Linked list 1 elements: ");
	for(i=0;i<n1;i++){
		scanf("%d",&x1);
		append(&list1,x1);
	}	
	printList(list1);
	
	printf("Enter the number of elements you want in linked list 2 = ");
	scanf("%d",&n2);
	printf("Enter Linked list 2 elements: ");
	for(i=0;i<n2;i++){
		scanf("%d",&x2);
		append(&list2,x2);
	}	
	printList(list2);
	
	merge(list1,&list2);
	printf("Modified First Linked List:\n");
    printList(list1);
 
    printf("Modified Second Linked List:\n");
    printList(list2);
	
	return 0;
}
