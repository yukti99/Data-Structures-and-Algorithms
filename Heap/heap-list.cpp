#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "QN.c"
#define SIZE 100

/* Minimum and Maximum binary heap using Linked List*/



void swap(int *a, int *b){
	int t  = *a;
	*a = *b;
	*b = t;
}
struct Node{
	int data;
	struct Node *left,*right;

};

struct Node *Createnode(int x){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->left = n->right = NULL;
	n->data = x;
	return n;

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
}


int main(){
    int n,x,i;
    printf("\nEnter the no of elements you want to enter in the Minimum heap = ");
    scanf("%d",&n);
    struct Minheap* root = insert(n);
    printf("\nEnter the node values of the Min heap = ");
    for(i=0;i<n;i++){
        scanf("%d",&x);        
    }
    printf("\nThe level order traversal of the Minheap: \n");
    levelorder(root);
    return 0;
    
}



























