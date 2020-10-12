#include <stdio.h>
#include <stdlib.h>

// Rotating a Linked List Counter-Clockwise by k nodes
struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head,int item){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->next = *head;
	*head = n;
}
void printList(struct Node* head){
	if (head == NULL){
		printf("\nEmpty!!\n");
		return ;
	}
	printf("\nLinked List : \n");
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}
// O(n^2) complexity
void rotate(struct Node** head,int k){
	int i,cnt=0;
	struct Node* temp = *head,*p;
	for(i=0;i<k;i++){ 	
		while(temp->next!=NULL){
			cnt++;		
			temp = temp->next;
		}
		p = (*head)->next;
		temp->next = *head;
		temp->next->next = NULL;
		*head = p;
		printList(*head);
	
	}
}
// O(n) complexity
void rotateList(struct Node** head,int k){
	struct Node* temp = *head, *n = *head;
	int cnt = 0;
	while(temp->next){
		temp = temp->next;
	}	
	temp->next = *head;
	while( cnt != k ){
		temp = temp->next;
		cnt++;
	}
	*head = temp->next;
	temp->next = NULL;	
}




int main(){
	
	struct Node* head = NULL;
	for (int i = 60; i > 0; i -= 10) 
        push(&head, i); 
  
    printf("Given linked list \n"); 
    printList(head); 
    rotateList(&head, 5); 
  
    printf("\nRotated Linked list \n"); 
    printList(head); 
  
	
	
	
	return 0;
}
