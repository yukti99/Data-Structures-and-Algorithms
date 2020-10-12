/* Implementation of  Min Heap using Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left,*right ;
	struct Node *parent;
};

struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int main(){
	
	
	
	return 0;
}
