/* Building a BST using its pre order Traversal */

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node{
	int data;
	struct Node *left,*right ;
};

struct Node* CreateNode(int data){
	struct Node*  n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

// Stack Implementation (each element of the stack is a Node)

struct Stack{	
	int top;
	unsigned size;
	struct Node* *a;
};

struct Stack* CreateS(unsigned size){
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = -1;
	s->size = size;
	s->a = (struct Node**)malloc(size*sizeof(struct Node*));
	int i=0;
	for(i=0;i<size;i++)
		s->a[i] = NULL;
	return s;
}
int isEmpty(struct Stack *s){
	return (s->top == -1);
}
int isFull(struct Stack *s){
	return (s->top == s->size-1);
}
struct Node* peek(struct Stack *s){
	return (s->a[s->top]);
}
void push(struct Stack *s,struct Node *item){
	if (isFull(s))
		return ;
	s->a[++s->top] = item;	
}
struct Node* pop(struct Stack *s){
	if (isEmpty(s))
		return NULL;
	return s->a[s->top--];
	
}

// Creating Tree
struct Node* CreateTree(int pre[],int size){
	
	struct Stack* s = CreateS(size);
	struct Node* root = CreateNode(pre[0]);
	
	push(s,root);
	int i;
	struct Node* temp;
	for(i=1 ; i<size ; i++){
		temp = NULL;		
		while(!isEmpty(s) && pre[i] > (peek(s)->data) )
			temp = pop(s);
			
		// make greater value as the right child and push to stack
		if (temp != NULL){
			temp->right = CreateNode(pre[i]);
			push(s,temp->right);
		}
		else{
			peek(s)->left = CreateNode(pre[i]);
			push(s,peek(s)->left);
		}
				 
	}
	return root;
}

void inorder(struct Node* root){
	if (root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}


int main(){
	
	int pre[] = {10, 5, 1, 7, 40, 50}; 
    int size = sizeof( pre ) / sizeof( pre[0] ); 
    struct Node* root = CreateTree(pre,size);
    printf("Inorder traversal of the constructed tree: \n"); 
    inorder(root); 
	
	
	
	return 0;
}
