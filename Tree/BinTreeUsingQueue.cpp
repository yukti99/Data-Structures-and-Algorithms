#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

// Tree Node
struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* CreateNode(int data){
	
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	n->left = n->right = NULL;
	n->data = data;
	return n;
}

// Implemenatation of Queue which stores tree nodes

struct Queue{
	
	int front,rear;
	int size;
	struct Node **a ;
};

struct Queue* CreateQ(int size){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = -1;
	q->size = size;
	q->a = (struct Node**)malloc(sizeof(struct Node*)*size);
	int i=0;
	for(i=0;i<size;i++)
		q->a[i] = NULL;
	return q;
	
}
int isEmpty(struct Queue *q){
	return (q->front == -1);
}
int isFull(struct Queue *q){
	return (q->rear == q->size-1);	
}
int hasOneItem(struct Queue *q){
	return (q->front == q->rear);
}
struct Node* front(struct Queue *q){
	return q->a[q->front];
}
void Enqueue(struct Queue *q,struct Node *root){
	if (isFull(q))
		return ;
	if (isEmpty(q))
		q->front++;
	q->a[++q->rear] = root;
}

struct Node* Dequeue(struct Queue *q){
	if (isEmpty(q))
		return NULL;
	
	struct Node* popped =  q->a[q->front++];
	if (q->front > q->rear)
		q->front = q->rear = -1;
	return popped;
	
}
int hasBothchild(struct Node *n){
	return (n && n->left && n->right);
}
// Insertion in a binary Tree using queue
void insert(struct Node *root,int item){
	
	struct Queue* q = CreateQ(SIZE);
	Enqueue(q,root);
	while(!isEmpty(q)){
		struct Node* temp = front(q);
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
// Insertion in Complete Binary Tree
void insertC(struct Node **root,int item,struct Queue*q){
	
	struct Node *temp = CreateNode(item);
	if (*root==NULL)
		*root = temp;
	else{
		struct Node* Front = front(q);
		if (!Front->left)
			Front->left = temp;
		else if (!Front->right)
			Front->right = temp;
			
		if (hasBothchild(Front))
			Dequeue(q);
		
	}
	Enqueue(q,temp);
	
}

// Level order Traversal using a queue
void levelOrder(struct Node *root){
	struct Queue *q = CreateQ(SIZE);
	Enqueue(q,root);
	
	while(!isEmpty(q)){
		
		struct Node* temp = Dequeue(q);
		printf("%d ",temp->data);
		if (temp->left)
			Enqueue(q,temp->left);
		if (temp->right)
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
	struct Node* root = NULL;
	struct Queue* q = CreateQ(SIZE); 
   /* root->left = CreateNode(11); 
    root->left->left = CreateNode(7); 
    root->right = CreateNode(9); 
    root->right->left = CreateNode(15); 
    root->right->right = CreateNode(8);*/
	insertC(&root,1,q);
	insertC(&root,2,q);
	insertC(&root,3,q);
	insertC(&root,4,q);
	//insert(root,6);  
  
   	printf("\nTraversal before Insertion : "); 
    levelOrder(root); 
    //inorder(root);
  
    int key = 5; 
    insertC(&root, key,q); 
 
   
    printf("\nTraversal after Insertion : "); 
    levelOrder(root); 
    //inorder(root);
    printf("\n%d",root->left->left->data);
	
	
	
	return 0;
}
