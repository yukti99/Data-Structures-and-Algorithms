
// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
using namespace std; 
  
/* A binary tree Node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Iterative function for inorder tree 
   traversal */
void inorder(struct Node *root){	
	stack <Node*> s;
	Node* cur = root;	
	while(cur != NULL || !s.empty()){
		while(cur){
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		printf("%d ",cur->data);
		cur = cur->right; 		
	}
}
void preorder(struct Node *root){	
	stack <Node*> s;
	Node* cur = root;	
	while(cur != NULL || !s.empty()){
		while(cur){
			printf("%d ",cur->data);
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();		
		cur = cur->right; 		
	}
}

void postorder(struct Node* root){
	
	stack <Node*> s1;
	stack <Node*> s2;
	Node *cur = root;	
	s1.push(root);
	while(!s1.empty()){
		cur = s1.top();
		s1.pop();
		s2.push(cur);
		if (cur->left)
			s1.push(cur->left);
		if (cur->right)
			s1.push(cur->right);		
	}
	while(!s2.empty()){
		cur = s2.top();
		s2.pop();
		printf("%d ",cur->data);
	}
}

// require queue

void levelOrder(struct Node* root){
	
	queue <Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* n = q.front();
		q.pop();
		printf("%d ",n->data);
		if (n->left)
			q.push(n->left);
		if (n->right)
			q.push(n->right); 		
	}
	
}
 
  
/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3
	              \
				   8 
				   /
        /  \      9
      4     5 
           | \
           7  6
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2);     
    root->right       = new Node(3);
	root->right->right = new Node(8); 
	root->right->right->left = new Node(9); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5);
	root->left->right->right = new Node(6); 
	root->left->right->left = new Node(7); 
  
    levelOrder(root); 
    return 0; 
} 
