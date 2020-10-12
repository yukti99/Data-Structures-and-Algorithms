// Vertical order of a tree using hashing

#include <bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* left,*right;
};

Node* newNode(int data){
	Node* n = new Node;
	n->left = n->right = NULL;
	n->data = data;
	return n;
}
// using preorder traversal
void getVO(Node* root,int hd,map<int,vector<int>> &m){
	if (root == NULL)
		return ;
	m[hd].push_back(root->data);
	getVO(root->left,hd-1,m);
	getVO(root->right,hd+1,m);	
	
}


void printVerticalOrder(Node* root){
	
	map <int,vector<int>> m;
	int hd = 0;
	getVO(root,hd,m);
	
	
	// traverse map and print nodes at every horizontal distance
	//map < int,vector<int> > :: iterator it;	
	//for(it=m.begin();it!=m.end() ;it++){
	for(auto it = m.begin();it!=m.end();it++){
		for(int i=0; i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
	
	
	
}

int main(){
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
    return 0; 
}
