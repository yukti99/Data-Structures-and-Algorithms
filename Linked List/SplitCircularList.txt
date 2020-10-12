#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* Create(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

struct Node* AddtoEmpty(struct Node* last,int item){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	last = n;
	last->next = last;
	return last;	
}

struct Node* push(struct Node* last,int item){
	
	if (last == NULL){
		return AddtoEmpty(last,item);
	}
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->next = last->next;
	last->next = n;
	return last;	
}

/*
IF HEAD IS FIRST ELEMENT OF THE CIRCULAR LINKED LIST
void splitList(struct Node *head,struct Node **head1_ref,struct Node **head2_ref){	
	//struct Node* head = l1->next;
	struct Node *slow = head, *fast = head;
	
	while(fast->next != head && fast->next->next != head){
		//printf("\n%d,%d\n",slow->data,fast->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast->next->next == head)
		fast = fast->next;
	//printf("\n%d,%d\n",slow->data,fast->data);
	(*head1_ref) = head;
	if (head->next != head)
		(*head2_ref) = slow->next;
	
	slow->next = (*head1_ref);
	fast->next = (*head2_ref);	
}
*/
void SplitList(struct Node* l1,struct Node **l2,struct Node **l3){
	
	struct Node* head = l1->next;
	struct Node *slow = head, *fast = head;
	
	while(fast->next != head && fast->next->next != head){
		//printf("\n%d,%d\n",slow->data,fast->data);
		slow = slow->next;
		fast = fast->next->next;
		
	}
	if (fast->next->next == head)
		fast = fast->next;
	//printf("\n%d,%d\n",slow->data,fast->data);
	(*l3) = fast;
	(*l3)->next = slow->next;
	(*l2) = slow;
	(*l2)->next = head;
	
}

void print(struct Node* last){
	if (last == NULL){
		printf("\nThe list is empty!\n");
		return ;
	}	
	struct Node* first = last->next;
	while(first != last){
		printf("%d ",first->data);
		first = first->next;
	}
	printf("%d ",first->data);
	printf("\n");
}

int main(){
	
	struct Node *l1 = NULL;
	struct Node *l2 = NULL;
	struct Node *l3 = NULL;
	l1 = push(l1,1);
	l1 = push(l1,2);
	l1 = push(l1,3);
	l1 = push(l1,4);
	l1 = push(l1,5);
	l1 = push(l1,6);
	l1 = push(l1,7);
	print(l1);
	SplitList(l1,&l2,&l3);	
	printf("Partition-1 : \n");
	print(l2);
	printf("Partition-2 : \n");
	print(l3);
	return 0;
}
