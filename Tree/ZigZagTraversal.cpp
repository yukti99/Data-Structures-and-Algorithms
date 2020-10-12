#include <iostream> 
#include <stack> 
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* CreateNode(int data){
	struct Node* n = new struct Node;
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void ZigZag(struct Node* root){
	
	if (!root)
		return ;
	stack<struct Node*> current_level;
	stack<struct Node*> next_level;	
	
	current_level.push(root);
	bool leftToright = true;
	while(!current_level.empty()){	
		printf("hi\n");
		struct Node* temp = current_level.top();
		current_level.pop();
		
		if (temp){
			cout<<temp->data<<" ";		
			if (leftToright){
				if (temp->left)
					next_level.push(temp->left);
				if (temp->right)
					next_level.push(temp->right);			
			}
			else{
				if (temp->right)
					next_level.push(temp->right);
				if (temp->left)
					next_level.push(temp->left);
			}
				
		}
		
		if (current_level.empty()){
			leftToright = !leftToright;
			swap(current_level, next_level);
		}
		
	}
	cout<<endl;
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
	root->left = CreateNode(2); 
	cout<<root->left->data<<endl;
    root->right = CreateNode(3); 
    root->left->left = CreateNode(7); 
    root->left->right = CreateNode(6); 
    root->right->left = CreateNode(5); 
    root->right->right = CreateNode(4); 
    cout<< "\nInorder Traversal : \n";
    inorder(root);
    cout<<endl;
    cout << "\nZigZag Order traversal of binary tree is \n"; 
	//ZigZag(root);
	
	return 0;
}
