
/* BINARY SEARCH TREE */


#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* CreateNode(int data){
	
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL ;
	return n ; 
}
// for inorder traversal 
void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
	
}
// for preorder traversal
void preorder(struct Node *node){
	if (node == NULL)
		return ;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
	
}
// for postorder traversal
void  postorder(struct Node *node){
	if (node == NULL)
		return ;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}
	
    
// Inserting a node into the BST
struct Node* insert(struct Node *node,int item){
	if (node == NULL)
		return CreateNode(item);
	
	if (item > node->data)
		node->right = insert(node->right,item);
	
	else if (item < node->data)
		node->left = insert(node->left,item);
	
	return node; // unchanged 
	
}

// Searching an item in the tree
// Search Function
struct Node* search(struct Node* node,int item){
	if (node == NULL || node->data == item)
		return node;
	if (item > node->data)
		return search(node->right,item);
	
	return search(node->left,item); 		
} 

struct Node* minNode(struct Node *n){
	
	struct Node* temp = n;
	while(n->left)
		n = n->left;
	return n;	
}

//  delete node function that returns the root after deletio
struct Node* deleteNode(struct Node *root,int item){
	
	// if root is NULL
	if (root == NULL)
		return root;
		
	if (item < root->data)
		root->left = deleteNode(root->left,item);
	
	else if (item > root->data)
		root->right = deleteNode(root->right,item);
	
	// if item is same as root's data, then This is the node
    // to be deleted
	else{
		// node with one or no child
		if (root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		// node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
		
	}
	return root;
	
}


int main(){ 	
int x;

	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("traversal of the given tree \n");
    preorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    
    printf("traversal of the given tree \n");
    preorder(root);
    
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    
    printf("traversal of the given tree \n");
    preorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    
    printf("traversal of the given tree \n");
    preorder(root);
	
	/*
	printf("What do you want to search");
	scanf("%d",&x);
	struct Node *s = search(root,x);
	if (s)
		printf("The Item -%d found!\n",s->data);
	else
		printf("The Item - %d not found !\n",x);
		
	*/
	return 0;
}

	/*struct Node *root = CreateNode(1);
	insert(root,3);
	insert(root,6);
	insert(root,2);
	insert(root,4);
	insert(root,5);
	struct Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);*/
    	/*printf("\nInorder Traversal of  BST : \n");
	inorder(root);	
	printf("\n");
	printf("\nPreorder Traversal of  BST : \n");
	preorder(root);	
	printf("\n");
	printf("\nPostorder Traversal of  BST : \n");
	postorder(root);	
	printf("\n");*/


