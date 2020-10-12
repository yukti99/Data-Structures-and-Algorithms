#include <stdio.h>
#include <stdlib.h>

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

/*function that stores inorder traversal of a tree rooted 
  with node */
// like inorder traversal
void storeInorder(struct Node *node,int inorder[],int *p){
	
	if (node == NULL)
		return ;
	storeInorder(node->left,inorder,p);
	inorder[(*p)++] = node->data;
	storeInorder(node->right,inorder,p);
	
}
int countNodes(struct Node *root){
	if (root == NULL)
		return 0;
	return (1 + countNodes(root->left) + countNodes(root->right) );
}
// for quick sort
int compare(const void *a,const void *b){
	return ( *(int*)a - *(int*)b );
}

//copying elements of sorted inorder array to tree
void arrayToBST(struct Node *root,int arr[],int *p){
	if (root == NULL)
		return ;
	arrayToBST(root->left,arr,p);
	root->data = arr[(*p)++];
	arrayToBST(root->right,arr,p);
}
//or 
void BubbleSort(int a[],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if (a[j]>a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	
}

// function to convert binary tree to binary search tree
void convert(struct Node* root){
	if (root == NULL)
		return ;
	int n = countNodes(root);
	int arr[n];
	int i=0;
	storeInorder(root,arr,&i);
	// Sort the array using library function for quick sort 
	qsort(arr,n,sizeof(arr[0]),compare);
	//BubbleSort(arr,n);
	i=0;
	arrayToBST(root,arr,&i);	
}
void inorder(struct Node* node)
{
	if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
	

int main(){
	struct Node *root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        2  	7 
       / \       
      8  4       
	*/
    root = CreateNode(10); 
    root->left = CreateNode(2); 
    root->right = CreateNode(7); 
    root->left->left = CreateNode(8); 
    root->left->right = CreateNode(4); 
  
    // convert Binary Tree to BST 
    convert(root); 
  
    printf("Following is Inorder Traversal of the converted BST: \n"); 
    inorder(root); 

	
	return 0;
}
