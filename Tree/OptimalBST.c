// Optimal Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "QN.c"
#define N 4


// Binary Search Tree Implementation
struct Node{
	int data;
	struct Node *left,*right;
};
struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}
struct Node* insert(struct Node* head,int item){
	if (!head)
		return CreateNode(item);
	if (item > head->data)
		head->right = insert(head->right,item);
	else if (item < head->data)
		head->left = insert(head->left,item);
	return head;
}
// Level Order Traversal of the BST created
void levelOrder(struct Node* root){
	struct Queue* q = CreateQ(100);
	Enqueue(q,root);
	while(!isEmpty(q)){
		struct Node* temp = Dequeue(q);
		printf("%d ",temp->data);
		if (temp->left)
			Enqueue(q,temp->left);
		if (temp->right)
			Enqueue(q,temp->right);
	}
	printf("\n");
	
}

void ConstructBST(int a[],int n){
	struct Node* root = NULL;
	int i=0;
	for(i=0;i<n;i++){
		root = insert(root,a[i]);
	}
	printf("\nLevel Order traversal of Optimal BST with minimum cost : \n");
	levelOrder(root);
		
	
}
/* OPTIMAL BINARY SEARCH TREE PROBLEM */

int MIN(int a,int b){
	return a<b?a:b;
}
int freqsum(int freq[],int i,int j){
	int k=0,sum=0;
	for(k=i;k<j;k++){
		sum+=freq[k];		
	}
	return sum;
}

int l=0;
// Recursive function to store bst structure in an array b
void func(int keys[],int root[N+1][N+1],int b[],int i,int j){
	if (i == j)
		return ;
	int r = root[i][j];
	b[l++] = keys[r-1];
	func(keys,root,b,i,r-1);
	func(keys,root,b,r,j);
}

int OptimalBST(int keys[],int freq[],int n){
	
	int cost[n+1][n+1],root[n+1][n+1];
	int i=0,j=0,k=0,d=0,r=0;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++){
			cost[i][j] = 0;
			root[i][j] = 0;
		}		
	for(d=1;d<=n;d++){
		for(i=0;i<=n-d;i++){
			j = i+d;			
			cost[i][j] = INT_MAX;
			int s = freqsum(freq,i,j);			
			for(r=i;r<=j;r++){
				int c = cost[i][r] + cost[r+1][j] + s;
				if (c < cost[i][j]){
					cost[i][j] = c;
					root[i][j] = r+1;					
				}								
			}
			k++;			 			
		}
	}
	printf("\nCost Matrix\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	printf("\n\n");
	printf("\nRoot Matrix\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",root[i][j]);
		printf("\n");
	}
	printf("\n");
	int b[n];
	func(keys,root,b,0,n);
	ConstructBST(b,n);
	return cost[0][n];
	
}

int main(){

    int keys[] = {10,20,30,40}; 
    int freq[] = {4,2,6,3}; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    printf("\nCost of Optimal BST is %d\n",OptimalBST(keys, freq, n)); 
    return 0;
}
