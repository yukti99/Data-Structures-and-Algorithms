/* Remove alternate nodes from a singly linked list

Eg : 1 2 3 4 5 6 
output : 1 3 5
Eg : 1 2 3 4 5
output: 1 3 5 
 */

#include <stdio.h>
#include <stdlib.h>



struct Node{
	int data;
	struct Node* next;
};

void append(struct Node** head,int data){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *head;
	n->data = data;
	n->next = NULL;
	// empty list
	if (NULL == *head){
		*head = n;
		return ;		
	}
	while(NULL!= temp->next){
		temp = temp->next;
	}
	temp->next = n;
	
}
//This function removes alternative nodes from the singly linked list
void remove(struct Node**head){
	struct Node *p1 = *head;
	while(p1!=NULL&& p1->next !=NULL){
		struct Node *p2 = p1->next;
		p1->next = p2->next;
		p1 = p2->next;
		free(p2);		
	}
}

void printList(struct Node* head){
	struct Node* n = head;
	while(n!=NULL){
		printf("%d ",n->data);
		n = n->next;
	}
	printf("\n");
}

int main(){
	struct Node* head = NULL;
	append(&head,1);append(&head,2);//append(&head,3);append(&head,4);append(&head,5);append(&head,6);append(&head,7);
	printList(head);
	remove(&head);
	printList(head);
	
	
	return 0;
}
