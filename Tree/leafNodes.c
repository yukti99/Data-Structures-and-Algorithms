#include <stdio.h>
#include <stdlib.h>
#include "s.c"
// Leaf Nodes of Binary Tree

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	int order;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->left = n->right = NULL;
	n->data = data;
	n->order = 0;  
	return n;	
}

/*
void inorder(struct Node* root){
	
	struct Stack* s = CreateS(100);
	struct Node* cur = root;
	while(!isEmptyS(s) || cur!=NULL){
		while(cur){
			push(s,cur);
			cur = cur->left;
		}
		cur = pop(s);
		printf("%d ",cur->data);
		cur = cur->right;		
	}
	
}*/

void inorder(struct Node* root){
	if (root == NULL)
		return ;
	inorder(root->left);
	inorder(root->right);
	

}



int main(){
	struct Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->left = newNode(14); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(7); 
    root->left->left->right = newNode(13); 	
    inorder(root);
	
	return 0;
}
