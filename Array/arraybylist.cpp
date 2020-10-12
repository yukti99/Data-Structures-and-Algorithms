/*2-D array using linked list */
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Node  {
	int data;
	struct Node* nxt;
	struct Node* digits;
};
// 324 5267 8843 98
struct Node* new_node(int data){
	
}
void digit(struct Node** head,int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->nxt = *head;
	*head = n;
	return;
}
void append(struct Node **head,int data){
	
	int d,r;	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *head;	
	n->data = data;
	n->digits= NULL;
	n->nxt = NULL;
	// for 1st node
	if (*head == NULL){
		*head = n;
	}
	else{
		while(temp->nxt!=NULL)
			temp = temp->nxt;		
		temp->nxt = n;			
	}
	
	while(data!=0){
		r = data % 10;
		data = data/10 ;		
		digit(&(n->digits),r);	
	}	
	
	
}
void push(struct Node**head,int data){
	
	int d,r;
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->nxt = *head;
	*head = n;
	n->digits = NULL;
	
	while(data!=0){
		r = data % 10;
		data = data/10 ;		
		digit(&(n->digits),r);	
	}	
}

void display(struct Node* head){
	
	// p1 moves vertically downwards while p2 moves horizontally rightwards	
	printf("\nTHE LINKED LIST :\n\n");
	struct Node* p1 = head;
	struct Node* p2 ;                   
	if (p1 == NULL){
		printf("\nThe list is empty\n");
		return ;
	}
	while(p1 != NULL){
		p2 = p1;
		printf("\t%d -> ",p1->data);	
		while(p2->digits != NULL){
			printf("%d -> ",p2->digits->data);
			p2->digits = p2->digits->nxt;			
		}
		printf("NIL\n");
		printf("\t|\n");
		p1 = p1->nxt;		
	}
	printf("\tNIL\n");	
	
}

int main(){
	
	struct Node* list = NULL;
	
	int n,i,x;
	printf("Enter n = ");
	scanf("%d",&n);
	printf("Enter n digits = ");
	for(int i=0;i<n;i++){
		scanf("%d",&x);	
		append(&list,x);	
	}
	display(list);
	
	
	return 0;
}
