/* Traversal in a tree using stacks */

#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right ;
};

struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

// inorder = Left->root->right
void inorder(struct Node* root){
	stack <Node*> s;
	struct Node* cur = root;
	s.push(cur);
	
	while (cur != NULL || s.empty() == false){
		while(cur != NULL){
			s.push(cur);
			cur = cur->left;
		}	
		cur = s.top();
		s.pop();			
		cout<<cur->data<<" ";
		cur = cur->right;
	}
}



int main(){
	
	struct Node* root = CreateNode(1);
	root->left        = CreateNode(2); 
    root->right       = CreateNode(3); 
    root->left->left  = CreateNode(4); 
    root->left->right = CreateNode(5); 
    inorder(root); 
	return 0;
}
