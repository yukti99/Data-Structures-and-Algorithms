#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

Node* newnode(int data){
	Node* n = new Node();
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void KdistNodes(Node* root,int k){
	if (root == NULL)
		return ;
	
	if (k == 0){
		cout<<root->data<<" ";
	}
	
	KdistNodes(root->left,k-1);
	KdistNodes(root->right,k-1);	

}

int printkdistanceNode(Node* root, Node* target , int k){
	if (root == NULL)
		return -1;
		
	// print down nodes from target if found
	if (root == target){
		KdistNodes(root,k);
		return 0;
	}
	// look for target in left subtree
	int dl = printkdistanceNode(root->left,target,k);
	
	// if target was found in the left subtree
	if (dl!=-1){
		if (dl+1==k){
			cout<<root->data<<" ";
		}
		else{
			KdistNodes(root->right,k-dl-2);
		}
		return dl+1;
		
		
	}
	// look for target in the right subtree
	int dr = printkdistanceNode(root->right,target,k);
	
	// if target was found in the right subtree
	if (dr!=-1){
		if (dr+1==k){
			cout<<root->data<<" ";
		}
		else{
			KdistNodes(root->left,k-dr-2);
		}
		return dr+1;
		
	}
	return -1;
	
	
}
bool search(Node* root,int item){
	if (root == NULL)
		return false;
	if (root->data == item )
		return true;
	
	return search(root->left,item) || search(root->right,item);
}
// To find the Lowest Common Ancestor of any two nodes
Node* LCA(Node* root,int n1,int n2){

	if (root == NULL)	
		return root;
	if (root->data == n1 || root->data == n2){
		return root;
	}
	if ( search(root->left,n1) && search(root->right,n2)){
		return root;
	}
	if ( search(root->left,n2) && search(root->right,n1)){
		return root;
	}
		
	if ( search(root->left,n1) && search(root->left,n2)){
		return LCA(root->left,n1,n2);
	}
	if ( search(root->right,n1) && search(root->right,n2)){
		return LCA(root->right,n1,n2);
	}
	
}	

int main(){
	Node *root = newnode(20); 
	root->left = newnode(8);
	root->right = newnode(22); 
	root->left->left = newnode(4); 
	root->left->right = newnode(12); 
	root->left->right->left = newnode(10); 
	root->left->right->right = newnode(14); 
	root->right->left = newnode(2);
	root->right->right = newnode(6);
	root->right->left->left = newnode(5); 
		
	//Node *target = root->left->right; 
	//printkdistanceNode(root, target, 2); 
	Node* lca = LCA(root,10,14);
	cout<<lca->data<<endl;

	return 0;
}
