/* Merge Sort in Linked List in C */

#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	
	int data;
	struct Node* next;
};

void push(struct Node** head,int data){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = *head;
	*head = n;
}
/*
void FrontBackSplit(struct Node *head,struct Node **front_ref,struct Node **back_ref){
	
	struct Node *slow, *fast;
	slow = head;
	fast = head->next;	
	while(fast && fast->next){
		
		slow = slow->next;
		fast = fast->next->next;
	}
	*front_ref = head;
	*back_ref = slow->next;
	slow->next = NULL;
}*/
struct Node* SortedMerge(struct Node *a,struct Node *b){
	
	struct Node* result = NULL;
	
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->data <= b->data){
		result = a;
		result->next = SortedMerge(a->next,b);		
	}
	else{
		result = b;
		result->next = SortedMerge(a,b->next);
	}
	
	return result;
}
/*
void MergeSort(struct Node **head_ref){
	struct Node *head = *head_ref;
	struct Node *a,*b;
	if (head == NULL || head->next == NULL){
		return ;
	}
	FrontBackSplit(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*head_ref = SortedMerge(a,b);
	
}*/


void printList(struct Node* head){
	
	printf("\nLinked list : ");
	struct Node* n = head;
	while(n!= NULL){
		printf("%d ",n->data);
		n = n->next ;
	}
	printf("\n");
}
int M(struct Node* head,int v){
	int c=0;
	struct Node* n = head,*prv;
	while(n!= NULL&&c!=v){
		prv = n;
		n = n->next ;
		c++;
	}
	printf("%d,%d\n",prv->data,n->data);
	return (prv->data+n->data)/2 ;
}

int main(){
	
	/*struct Node *n = NULL;
	push(&n,1);
	push(&n,5);
	push(&n,3);
	push(&n,6);
	push(&n,4);
	push(&n,2);*/
	struct Node* h2 = NULL;
	struct Node* h1 = NULL;
	
	push(&h2,10);push(&h2,6);push(&h2,3);push(&h2,0);
	push(&h1,7);push(&h1,5);push(&h1,2);push(&h1,1);
	
	printList(h1);
	printList(h2);
	struct Node* c = SortedMerge(h1,h2);
	printList(c);
	printf("%d\n",M(c,4));
/*	MergeSort(&n);
	printf("\nAfter Sorting\n");
	printList(n);*/  
	return 0;
}
