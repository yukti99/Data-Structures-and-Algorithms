#include <bits/stdc++.h>
using namespace std;

// Vertical order of a BST

struct Node{
	int data;
	Node *left,*right;
};
Node* newNode(int data){
	Node* n = new Node;
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void printVerticalOrder(Node* root){
	if (root==NULL)
		return ;
		
	// a map to use horizontal distance as index to a vector containing node-keys
	map<int,vector<int>> m;
	int hd=0;
	
	// a queue that stores a node-hd pair to do level order traversal of BST
	queue< pair<Node*,int> > q;
	
	// make a pair of current hd and root and push into queue
	q.push(make_pair(root,hd));
	
	while(!q.empty()){
		// pop pairs from queue one by one
		pair<Node*,int> temp = q.front();
		q.pop();
		
		
		hd = temp.second;
		Node* node = temp.first;
		
		m[hd].push_back(node->data);
		
		if (node->left != NULL)
			q.push(make_pair(node->left,hd-1));
		if (node->right != NULL)
			q.push(make_pair(node->right,hd+1));
	
	}
	
	for(auto i = m.begin(); i!=m.end(); i++){
		for(int j=0;j<i->second.size();j++){
			cout<<i->second[j]<<" ";
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
    root->right->right->left= newNode(10); 
    root->right->right->left->right= newNode(11); 
    root->right->right->left->right->right= newNode(12); 
    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
    return 0; 
  }
