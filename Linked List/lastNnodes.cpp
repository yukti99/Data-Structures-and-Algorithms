#include <bits/stdc++.h>
using namespace std;

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
void push(struct  Node** head,int item){
	struct Node* n = Create(item);
	n->next = *head;
	*head = n;	
}
// Iterative Method
int Product(struct Node* head,int N){
	if (N<=0)
		return 0;
	stack<int>s;
	int p = 1;
	while(head != NULL){
		s.push(head->data);
		head = head->next;
	}
	while(N--){
		p *= s.top();
		s.pop();
	}
	return p;
}
// Recursive Method
int prod = 1;
void Prod(struct Node* head,int *N){
	if (head == NULL)
		return ;
	Prod(head->next,N);
	if (*N>0){
		prod *= head->data;
		(*N)--;
	}	
}

int ProductN(struct Node* head,int N){
	if (N<=0)
		return 0;
	Prod(head,&N);
	return prod;
}

void display(struct Node* head){
	if (head == NULL)
		return ;
	while(head){
		printf("%d ",head->data);
		head = head->next;
	}
}



int main(){
	struct Node* head = NULL;
	push(&head, 12); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 6); 
    push(&head, 10);   
    display(head);
    printf("\n");
    int N = 2;
	cout<<"Product of last "<<N<<" nodes = "<<ProductN(head,N);	
	return 0;
}
