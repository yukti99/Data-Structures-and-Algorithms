#include <stdio.h>
#include <stdlib.h>

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

struct Node* insert(struct Node *node,int item){
	if (node == NULL)
		return CreateNode(item);	
	if (item > node->data)
		node->right = insert(node->right,item);	
	else if (item < node->data)
		node->left = insert(node->left,item);	
	return node; 
	
}

void postorder(struct Node* node){
	if (node == NULL)
		return ;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
} 
void inorder(struct Node* node){
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
} 

void preorder(struct Node* node){
	if (node == NULL)
		return ;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
} 

int main(){
	struct Node* root = NULL;
	int x,r,c;
	printf("Enter the root of tree = ");
	scanf("%d",&r);
	root = insert(root,r);
	while(1){
	printf("\tWhat do you want to do?\n");
	printf("\t1. Insertion\n");	
	printf("\t2. InorderTraversal\n");
	printf("\t3. Preorder Traversal\n");
	printf("\t4. Postorder Traversal\n");
	printf("\t5. Quit\n");	
	printf("\tEnter your choice : ");
        scanf("%d", &c);
	switch(c){
		case 1:							
			printf("Enter the Element to be inserted = ");
			scanf("%d",&x);			
			insert(root,x);
			printf("\nInserted!!\n");
			break;
		case 2: 
			printf("\nInorder Traversal of the Tree :\n");
			inorder(root);
			printf("\n");
			break;			
	
		case 3:
			printf("\nPreorder Traversal of the Tree :\n");
			preorder(root);
			printf("\n");
			break;
		case 4:
			printf("\nPostorder Traversal of the Tree :\n");
			postorder(root);
			printf("\n");
			break;
		case 5:
			printf("\nThank you!!\n\n");
			exit(0);
			
		default:
			printf("\nWrong Choice!!\n");
	}
	
	}

	return 0;
}
