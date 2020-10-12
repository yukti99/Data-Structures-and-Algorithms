#include <stdio.h>
#include <stdlib.h>


// Tree Node
struct Node{
	int data;
	struct Node *left,*right;
};


struct Node* CreateNode(int data){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

// O(n) Time complexity
struct Node* createTree(int pre[],int *preIndex,int key,int min,int max,int size){
	
	if (*preIndex > size)
		return NULL;
		
	struct Node* root = NULL;
	
	if (key > min && key < max){
		root = CreateNode(key);
		*preIndex += 1;
		
		if (*preIndex < size){
			root->left = createTree(pre,preIndex,pre[*preIndex],min,key,size);
			root->right = createTree(pre,preIndex,pre[*preIndex],key,max,size);			
		}		
	}
	return root;
}

struct Node* Tree(int pre[],int size){
	int preIndex = 0;
	return createTree(pre,&preIndex,pre[0],INT_MIN,INT_MAX,size);	
}
/*
// Constructing the Binary Search Tree using its Preorder traversal
// O(n^2) time complexity
struct Node* constructTree(int pre[],int* preIndex,int low,int high,int size){
	
	if (*preIndex > size || low>high)
		return NULL;
	
	// making node at preIndex as the root
	struct Node* root = CreateNode(pre[*preIndex]);
	
	// increment preIndex
	*preIndex += 1;
	
	// if only one element left in subarray,no  need to recur
	if (low == high)
		return root;
	
	// Search for the first element greater than root
	int i;
	for(i=low ; i<high ;i++){
		if (pre[i] > root->data)
			break;
	}
	// Use the index of element found in preorder to divide preorder array in
    // two parts. Left subtree and right subtree
    root->left = constructTree(pre,preIndex,*preIndex,i-1,size);
    root->right = constructTree(pre,preIndex,i,high,size);
	
}
// Constructing the Binary Search Tree using its Preorder traversal
// O(n^2) time complexity

struct Node* Tree(int pre[], int size)
{
    int preIndex = 0;
    return constructTree(pre, &preIndex, 0, size - 1, size);
}*/
void Inorder(struct Node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    //int pre[] = {10,6,4,8,12,11,13};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct Node* root = Tree(pre, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    Inorder(root);
 
    return 0;
}
