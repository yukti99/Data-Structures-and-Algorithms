#include <stdio.h>
#include <stdlib.h>

/* BINARY TREE  using a Queue */

// Tree Node

struct Node{
	int data;
	struct Node *left,*right ;
};

struct Node* CreateNode(int item){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->left = n->right = NULL;
	return n;
}

// Queue implementation : A queue that stores nodes
struct Queue{
	
	int front,rear;
	int size;
	int *a ;	
};

struct Queue* CreateQ(int size){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = -1;
	q->size = 0;
	q->a = (struct Node**)malloc(size* sizeof(struct Node*));
	int i=0;
	for(i;i<size;i++)
		q->a[i] = NULL;
	return q; 	
}

int isFull(struct Queue *q){
	return (q->rear == q->size -1);
}
int isEmpty(struct Queue *q){
	return (q->front == -1);
}
int Front(struct Queue *q){
	return q->a[q->front] ;
}
void Enqueue(struct Queue *q,struct Node* root){
	
	if (isFull(q))
		return ;		
	 
	if (q->front == -1)
		q->front = 0;
	q->a[++q->rear] = root;
	q->size++;  		
}

struct Node* Dequeue(struct Queue *q){
	
	if (isEmpty(q))
		return ;
	
	struct Node* temp =  q->a[q->front];
	q->front++;
	q->size--;
	if (q->front > q->rear)
		q->front = q->rear = -1;
	return temp;
}

int hasBothchild(struct Node*n){
	return (n && n->left && n->right);
}

// insertion using queue
void insert(struct Node* t,int item){
	struct Node *q = CreateQ()
}


// level Order Traversal 
void levelOrder(struct Node* root){
	
}

int main(){
	
	
	return 0;
}
