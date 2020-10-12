#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* BINARY SEARCH TREE */
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}
// Insertion function
struct Node* insert(struct Node *node,int item){
	if (node == NULL)
		return CreateNode(item);	
	if (item > node->data)
		node->right = insert(node->right,item);
	
	else if (item < node->data)
		node->left = insert(node->left,item);
	
	return node;	
}

// Search Function
struct Node* search(struct Node* node,int item){
	if (node == NULL || node->data == item)
		return node;
	if (item > node->data)
		return search(node->right,item);
	
	return search(node->left,item); 		
}  

// Preorder Traversal
void preorder(struct Node* node){
	if (node == NULL)
		return ;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
} 
int n=0;
void height(struct Node* node){
	if (node == NULL)
		return ;
	height(node->left);
	n++;
	height(node->right);	
}
 // for inorder traversal 
void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
	
} 
// for postorder traversal
void  postorder(struct Node *node){
	if (node == NULL)
		return ;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}
struct Node* minValue(struct Node* node){
	struct Node* temp = node;
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

struct Node* Delete(struct Node*root,int data){
	if (root == NULL)
		return root;
	if (data > root->data)
		root->right = Delete(root->right,data);
	else if (data < root->data)
		root->left = Delete(root->left,data);
		
	// found the element to be deleted	
	else{
		if (root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
			return root;
		}
		else if (root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;					
		}
		else if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}		
		// Case of the node with two children
		struct Node* temp = minValue(root->right);
		root->data = temp->data;
		root->right = Delete(root->right,temp->data);		
	}
	return root;	
}





int main(){
	struct Node* root = NULL;
	int x,r,choice;
	printf("Enter the root of tree = ");
	scanf("%d",&r);
	root = insert(root,r);
	while(1){
		printf("\tWhat do you want to do?\n");
		printf("\t1. Insertion\n");
		printf("\t2. Search\n");
		printf("\t3. Preorder Traversal\n");
		printf("\t4. Delete a Node\n");
		printf("\t5. Height of the BST\n");
		printf("\t6. Quit\n");
		printf("\tEnter your choice : ");
	    scanf("%d", &choice);
		switch(choice){
			case 1:							
				printf("Enter the Element to be inserted = ");
				scanf("%d",&x);			
				insert(root,x);
				printf("\nInserted!!\n");
				break;
			case 2: 			
				printf("Enter element to be searched = ");
				scanf("%d",&x);
				struct Node* s = search(root,x);
				if (s)
					printf("\nElement Found!\n");
				else
					printf("\nElement NOT Found!\n");
				break;
		
			case 3:
				printf("\nPreorder Traversal of the Tree :\n");
				preorder(root);
				printf("\n");
				break;
			case 4:
				printf("\nEnter the Item to delete = ");
				scanf("%d",&x);
				root = Delete(root,x);
				printf("\n%d has been deleted successfully from the tree!!\n",x);
				printf("After Deletion : \n");
				preorder(root);				
				break;
			case 5:
				height(root);
				printf("\nThe number of nodes in the tree = %d\n",n);
				printf("\nlog2(n+1) = %d\n",ceil(log2(n+1)) );
				int h = (int)(log2(n+1));
				printf("\nThe height of the given tree = %d\n",h);
				break;
					
			case 6:
				printf("\nTHANK YOU!!\n");
				exit(0);
			default:
            	printf("\a\nWrong choice! \n\n");
		}
	
	}

	return 0;
}
