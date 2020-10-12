#include <stdio.h>
#include <stdlib.h>

// Inorder Successor in a Binary Search Tree

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->left = n->right = NULL;
	n->data = data;
	return n; 	
}

struct Node* insert(struct Node* root, int item){
	if (root == NULL){
		return CreateNode(item);
	}
	if (item > root->data)
		root->right = insert(root->right,item);
	else if (item <root->data)
		root->left = insert(root->left,item);
	return root;
}
struct Node* leftmost (struct Node* root){
	
	while(root->left)
		root = root->left;
	return root;
	
}

struct Node* inorderSucc(struct Node* root,struct Node* n){
	if (n->right != NULL)
		return leftmost(n->right);
	struct  Node* succ = NULL;
	while(root != NULL){
		if (n->data < root->data){
			succ = root;
			root = root->left;
		}
		else if (n->data > root->data) {
			root = root->right;			
		}
		else{
			break;
		}
	}
	return succ;
}

struct Node* search(struct Node* root,int item){
	if (root == NULL || root->data == item)
		return root;
	if (item > root->data)
		return search(root->right,item);
	return search(root->left,item);
}

void inorder(struct Node* root){
	if (root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main(){
	
	struct Node* root = NULL;
	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10);   
	root = insert(root, 14);  
	printf("\nInorder Traversal : \n");
	inorder(root);
	printf("\n");
	int n = 22;
	struct Node* temp = search(root,n);
	if (temp){
		printf("Found  = %d\n",temp->data);
		struct Node* s = inorderSucc(root,temp);
		if (s)
			printf("\nInorder Successor of %d : %d\n",temp->data,s->data);
		else
			printf("\nInorder Successor of %d : NULL\n",temp->data);		
	}
	else{
		printf("\nNode not  present in BST!!\n");
	}
	
	
	
	return 0;
}
