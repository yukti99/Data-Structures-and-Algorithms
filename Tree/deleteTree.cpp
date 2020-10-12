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
// Insertion 
struct Node* insert(struct  Node* root,int data){
	if (root == NULL)
		return CreateNode(data);
	if (data > root->data)
		root->right =  insert(root->right,data);
	else if (data < root->data)
		root->left = insert(root->left,data);	
	return root;
}

// Preorder Traversal
void preorder(struct Node* node){
	if (node == NULL)
		return ;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
} 
 // for inorder traversal 
void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
	
} 
// for Postorder traversal
void  postorder(struct Node *node){
	if (node == NULL)
		return ;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}


int nodes(struct Node* node){
	if (node == NULL)
		return 0;
	return (1 + nodes(node->left) + nodes(node->right) );
}

struct Node* minValue(struct Node* root){
	struct Node* temp = root;
	while(temp->left)
		temp = temp->left;
	return temp;
}

// Delete function
struct Node* Delete(struct Node* root,int item){
	
	if (root == NULL)
		return root;
		
	if (item > root->data)
		root->right =  Delete(root->right,item);
		
	else if (item < root->data)
		root->left =  Delete(root->left,item);
		
	// found the node to be deleted
	else{
		// node with no children
		if (root->left == NULL  && root->right == NULL){
			free(root);
			root = NULL;
			return root;			
		}
		// node with one child
		else if (root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else  if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		// node with two children
		struct Node* temp = minValue(root->right);
		root->data = temp->data;
		root->right = Delete(root->right,temp->data);
	}
	return root;
}
int l=0,r=0;
int height(struct Node* root){
	if (root){
		l = 1 + height(root->left);
		r = 1 + height(root->right);
		return (l>r?l:r);		
	}
	else
		return 0;
}
struct Node* Search(struct Node* node,int item){
	if (node == NULL || node->data == item)
		return node;
	if (item > node->data)
		return Search(node->right,item);
	return Search(node->left,item); 
}

int main(){
	
struct Node* root = NULL;
	int x,r,choice,h=0;
	printf("Enter the root of tree = ");
	scanf("%d",&r);
	root = insert(root,r);
	while(1){
		printf("\n\tWhat do you want to do?\n\n");
		printf("\t1. Insertion\n");
		printf("\t2. Search\n");
		printf("\t3. Inorder Traversal\n");
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
				if (Search(root,x))
					printf("\nElement Found!\n");
				else
					printf("\nElement NOT Found!\n");
				break;
		
			case 3:
				printf("\nInorder Traversal of the Tree :\n");
				inorder(root);
				printf("\nThe number of nodes = %d\n",nodes(root));
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
				printf("\nThe height of the given tree = %d\n",height(root)-1);
				break;
			case 6:
				printf("\nThank you!!\n");
				exit(0);
			default:
				printf("\nWrong choice!\n");
			
		}
	
	}

	return 0;
	
}
