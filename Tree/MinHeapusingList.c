#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 100

/* Minimum and Maximum binary heap using Linked List*/


// Queue Implementation in c

struct Queue{
	
	int front,rear;
	int size;
	struct Node* *a;
};

struct Queue *CreateQ(int size){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->size = size;
	q->front = q->rear = -1;      
	q->array = (struct Node**)malloc(sizeof(size * sizeof(struct Node*)));
	return q;
}

int isFull(struct Queue *q){
	return (q->size-1 == q->rear);   //  or q->rear = q->size-1
}

int isEmpty(struct Queue *q){
	return (q->front == -1);    // q->rear = -1
}
void Enqueue(struct Queue *q,struct Node* item){
	if (isFull(q))
		return ;
	if (q->front == -1)
		q->front = 0;      
	q->rear++ ;
	q->a[q->rear] = item ;
	
}
struct Node* Dequeue(struct Queue *q){
	
	if (isEmpty(q))
		return INT_MIN;
	int x = q->a[q->front];
	q->front++ ;	
	if (q->front > q->rear)       
		q->front = q->rear = -1;
	return x;
}

struct Node* front(struct Queue *q){
	
	if (isEmpty(q))		
		return INT_MIN;	
	return ( q->a[q->front] );
}

struct Node* rear(struct Queue *q){	
	if (isEmpty(q))		
		return INT_MIN;	
	return (q->a[q->rear]);
}

void swap(int *a, int *b){
	int t  = *a;
	*a = *b;
	*b = t;
}
struct Node{
	int data;
	struct Node *left,*right;
	struct Node *parent;
};

struct Node *Createnode(int x,struct Node* parent){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->left = n->right = NULL;
	n->data = x;
	n->parent = parent;
}


struct Node* insert(struct Node* root,int data){
	struct Node* n = Createnode(data);
	if (root == NULL){
		root = n;
		return root;
	}
	struct Queue* q = CreateQ(SIZE);
	Enqueue(q,root);
	struct Node* temp = root;
	while(temp){
		if (temp->left)
			Enqueue(q,temp->left);
		else{
			temp->left=n;
			if (temp->data > data){
				swap(&temp->data,&n->data);			
			}			
			break;			
	        }
		if (temp->right)
			Enqueue(q,temp->right);
		else{
			temp->right=n;
			if (temp->data > data){
				swap(&temp->data,&n->data);			
			}				
			break;			
		}
}


int main(){
    int n,x,i;
    printf("\nEnter the no of elements you want to enter in the Minimum heap = ");
    scanf("%d",&n);
    struct Minheap* root = Createheap(n);
    printf("\nEnter the node values of the Min heap = ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        
    }
    printf("\nThe level order traversal of the Minheap: \n");
    levelOrder(root);
    return 0;
    
}



























