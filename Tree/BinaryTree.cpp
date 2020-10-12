#include <stdio.h>
#include <stdlib.h>

/* BINARY TREE  using a Queue */


struct Node{
	
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* CreateNode(int item){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->left = n->right = NULL;
	return n;
}

struct Queue{
	
	int front,rear,size;
	int capacity;
	struct Node **a ;
	
};
struct Queue* CreateQ(int cap){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = -1;
	q->capacity = cap;
	q->size = 0;
	q->a = (struct Node**)malloc(q->capacity*sizeof(struct Node*));
	int i; 
    for (i = 0; i < cap; ++i) 
        q->a[i] = NULL; 
  
	return q; 	
}

int isFull(struct Queue *q){
	return (q->size == q->capacity);
}
int isEmpty(struct Queue *q){
	return (q->front  == -1);
}
struct Node* Front(struct Queue *q){
	return q->a[q->front] ;
}
void Enqueue(struct Queue *q,struct Node *root){
	
	if (isFull(q)){
		return ;		
	} 
	if (q->front == -1)
		q->front = 0;
	
	q->a[++q->rear] = root;
	q->size++;  		
}

struct Node* Dequeue(struct Queue *q){
	
	if (isEmpty(q))
		return NULL ;
	
	struct Node* popped = q->a[q->front];
	q->front++;
	q->size--;
	if (q->front > q->rear)
		q->front = q->rear = -1;
	return popped;
}


// insertion using queue
void insert(struct Node* temp,int item){
	struct Queue *q = CreateQ(15);
	Enqueue(q,temp);
	
	// Do level order traversal until we find 
    // an empty place.
	while(!isEmpty(q)){
		struct Node* temp = Front(q);
		Dequeue(q);
		if (!temp->left){
			temp->left = CreateNode(item);
			break;			
		}			
		else
			Enqueue(q,temp->left);
			
		if (!temp->right){
			temp->right = CreateNode(item);
			break;
		}
		else
			Enqueue(q,temp->right);
	}	
	
}


void inorder(struct Node* node){
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}


int main(){
	
	struct Node* root = CreateNode(10); 
    root->left = CreateNode(11); 
    root->left->left = CreateNode(7); 
    root->right = CreateNode(9); 
    root->right->left = CreateNode(15); 
    root->right->right = CreateNode(8); 
  
   	printf("Inorder traversal before Insertion : "); 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
   
    printf("Inorder traversal after Insertion : "); 
    inorder(root); 
	
	
	return 0;
}
