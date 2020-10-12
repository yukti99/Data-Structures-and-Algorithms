#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	
	int data;
	struct Node* next;
};
struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

struct Queue{
	int size;
	int front,rear;
	struct Node* *a;
};

struct Queue* CreateQ(int size){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = size;
	q->front = q->rear = -1;
	q->a = (struct Node*)malloc(sizeof(struct Node)*size);
	return q;
	
}
int isEmpty(struct Queue *q){
	return (q->rear == -1);
}

int isFull(struct  Queue *q){
	return (q->rear == q->size-1);	
}

void peek(struct Queue *q){
	if (isEmpty(q))
		return ;
	struct Node* n = q->a[q->front];
	printf("%d ",n->data);
}

void push(struct Queue *q,struct Node* item){
	if (isFull(q))
		return ;
	q->a[++q->rear] = item;
	if (q->front == -1)
		q->front = 0;
}

struct Node* pop(struct Queue *q){
	if(isEmpty(q))
		return NULL;
	struct Node* popped = q->a[q->front++];
	if (q->front>q->rear)
		q->front = q->rear = -1;
	return popped;
}
void displayQ(struct Queue *q){
	
	if (isEmpty(q))
		return ;
	printf("\nQUEUE : \n");	
	int i;
	struct Node*n;
	for(i = q->front; i <= q->rear ;i++)
		n = q->a[i];			
		printf("\t%d\n",n->data); 
	printf("\n");
} 

int main(){	
	struct Queue*q = CreateQ(10);
	struct Node*  n1 = CreateNode(1);
	struct Node*  n2 = CreateNode(2);
	struct Node*  n3 = CreateNode(3);
	n1->next = CreateNode(4);	
	push(q,n1);
	push(q,n2);
	push(q,n3);
	displayQ(q);
	struct Node* popped = pop(q);
	printf("\n%d ",popped->data);
	peek(q);
	displayQ(q);	
	return 0;
}
