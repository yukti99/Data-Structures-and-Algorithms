/* To check if a Tree is a Binary Search Tree and Height of the Tree*/

#include <stdio.h>
#include <stdlib.h>


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

// Insertion function
struct Node* insert(struct Node *node,int item){
	if (node == NULL)
		return CreateNode(item);	
	if (item > node->data)
		node->right = insert(node->right,item);	
	else if (item < node->data)
		node->left = insert(node->left,item);	
	return node;	
}

int height(struct Node* root){
	if (root){
		 int l = height(root->left) + 1;
		 int r = height(root->right) + 1;
		 return (l>r?l:r);			
	}	
	else
		return 0;
}

void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);	
} 
// function to check if a tree is a binary Search Tree

int check(struct Node* root){
	
	static struct Node *prev = NULL;
	if (root){
		if (!check(root->left))
			return 0;
		if (prev != NULL && prev->data >= root->data)
			return 0;
		prev = root;
		return check(root->right);		
	}
	return 1;
}



int main(){
	
	struct Node *root = NULL;
	int i,x,n;
	printf("Enter the number of elements of Binary Search Tree = ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		root = insert(root,x);		
	}
	printf("\nInorder Taversal of BST is  : \n");
	inorder(root);
	// Considering the height of root is 0 
	printf("\nHeight of the Tree = %d\n",height(root)-1);
	
	// Checking if the given tree is Binary Search Tree 
	if (check(root))
		printf("\nYes it is a BST\n");
	else
		printf("\nNo it is not a BST\n"); 	
	return 0;
}
