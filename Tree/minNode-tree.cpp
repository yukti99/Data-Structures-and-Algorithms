/*Find the node with minimum value in a Binary Search Tree*/

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

void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);	
} 
// function to find the min node
int MinNodeValue(struct Node* root){
	struct Node* n  = root;
	while(n->left != NULL)
		n = n->left;
	return n->data;
		
} 

int MaxNodeValue(struct Node* root){
	struct Node* n = root;
	while(n->right != NULL)
		n = n->right;
	return n->data;
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

	int m = MaxNodeValue(root);
	printf("\nThe Minimum Node  = %d\n",m);
	
	return 0;
}
