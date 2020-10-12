/* Inorder Tree Traversal without Recursion */ 


#include<bits/stdc++.h> 
using namespace std; 

struct Node {
	int data;
	Node *left,*right;
};

struct Node* CreateNode(int data){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

// function for Inorder Traversal
void inorder(Node* root){
	
	stack <struct Node*> s ;
	struct Node* cur = root;
	while(cur != NULL || s.empty() == false){
		while(cur != NULL){			
			s.push(cur);
			cur = cur->left ;
		}
		cur = s.top();
		s.pop();
		cout<<cur->data<<" ";
		cur = cur->right;		
	}
}

int main(){
	/* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = CreateNode(1); 
    root->left        = CreateNode(2); 
    root->right       = CreateNode(3); 
    root->left->left  = CreateNode(4); 
    root->left->right = CreateNode(5);   
    printf("\n Inorder Traversal \n");
    inorder(root); 
    return 0; 
}
