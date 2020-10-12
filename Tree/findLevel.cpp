int findLevel(struct Node* node,int item,int l){
    if (node==NULL)
	    return 0;
	if (node->data == item)
	    return l;
	int dl = findLevel(node->left,item,l+1);
	if (dl!=0)
	    return dl;
	dl = findLevel(node->right,item,l+1);
	return dl;
}


int getLevel(struct Node *node, int target)
{
	return findLevel(node,target,1);
}
void printKdistance(Node *root, int k)
{
    int level = 0;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
	    int size = q.size();
	    while(size--){
	        Node* t = q.front();
    	    q.pop();
    	    if (t->left!=NULL){
    	        q.push(t->left);
    	        
    	    }
    	    if (t->right!=NULL){
    	        q.push(t->right);
    	       
    	    }
    	    if (level == k)
    	       cout<<t->data<<" ";
    	    }
	   
	    level++;
	}
  
}

/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node
int getLevel(struct Node *node, int target)
{
	int level = 1;
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
	    int size = q.size();
	    while(size--){
	        Node* t = q.front();
    	    q.pop();
    	    
    	    
    	    if (t->left!=NULL){
    	        q.push(t->left);
    	        
    	    }
    	    if (t->right!=NULL){
    	        q.push(t->right);
    	       
    	    }
    	    if (t->data == target)
    	        return level;
    	    }
	   
	    level++;
	    
	    
	}
	
	
}

