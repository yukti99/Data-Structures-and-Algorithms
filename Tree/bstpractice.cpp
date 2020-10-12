#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* CreateNode(int data){
	struct  Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

struct Node* insert(struct Node* root,int data){

	if (root == NULL)
		return CreateNode(data);
	if (data > root->data)
		root->right = insert(root->right,data);	
	else if (data < root->data)
		root->left = insert(root->left,data);
	return root;	
}

struct Node* minValue(struct Node* node){
	struct Node* temp = node;
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

struct Node* Delete(struct Node*root,int data){
	if (root == NULL)
		return root;
	if (data > root->data)
		root->right = Delete(root->right,data);
	else if (data < root->data)
		root->left = Delete(root->left,data);
		
	// found the element to be deleted	
	else{
		if (root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
			return root;
		}
		else if (root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;					
		}
		else if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}		
		// Case of the node with two children
		struct Node* temp = minValue(root->right);
		root->data = temp->data;
		root->right = Delete(root->right,temp->data);		
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

void preorder(struct Node* root){
	if (root == NULL)
		return ;
	printf("%d ",root->data);
	preorder(root->left);	
	preorder(root->right);
}

int main(){
	
	struct Node* root = NULL;
	root = insert(root,1);
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,6);
	root = insert(root,4);
	printf("\nThe Preorder Traversal of the Tree = \n");
	preorder(root);
	int x;
	printf("\nEnter the item to delete = ");
	scanf("%d",&x);
	root = Delete(root,x);
	printf("\nAfter Deletion  = \n");
	preorder(root); 
	
	return 0;
}
