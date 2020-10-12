// AVL TREE - INSERTION, DELETION AND INORDER TRAVERSAL 

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;
    struct Node *left,*right;
};
struct Node* CreateNode(int item){
    
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = item;    
    n->left = n->right = NULL;
    n->height = 1;
    return n;
    
}
int height(struct Node* node){
	if (node == NULL)
		return 0;
	return node->height;
	
}
int greater(int a,int b){
	return (a>b)?a:b;
}

int Balance(struct Node* node){
	if (node == NULL)
		return 0;
        return (height(node->left) - height(node->right));	
}


struct Node* rotateLeft(struct Node* node){
	struct Node* a = node->right;
	struct Node* b = a->left;
	// rotaion
	a->left = node;
	node->right = b;

        node->height = greater(height(node->left),height(node->right)) + 1;
	a->height = greater(height(a->left),height(a->right)) + 1;
	return a;
	
}


struct Node* rotateRight(struct Node* node){

      struct Node* a = node->left;
      struct Node* b = a->right;
      // rotation
      a->right = node;
      node->left = b;
      node->height = greater(height(node->left),height(node->right)) + 1;
      a->height = greater(height(a->left),height(a->right)) + 1;
      return a;
}






struct Node* insert(struct Node* node,int item){
    if (node == NULL)
        return CreateNode(item);
    if (item < node->data)
        node->left = insert(node->left,item);
    else if (item >node->data)
        node->right = insert(node->right,item);
    else
        return node;

    node->height = 1 + greater(height(node->left),height(node->right));
    int balance  = Balance(node);
    // left - left rotation
    if (balance > 1 && item < node->left->data)
	return rotateRight(node);
    // left-right rotation
    if (balance > 1 && item > node->left->data){
	node->left = rotateLeft(node->left);
	return rotateRight(node);
    }
    // right-right rotation
    if (balance < -1 && item > node->right->data)
	return rotateLeft(node);
    // right-left rotation
    if (balance < -1 && item < node->right->data){
	node->right = rotateRight(node->right);
	return rotateLeft(node);    
    }
    return node;  
    
}
struct Node* minNode(struct Node* node) 
{ 
	struct Node* p = node;	
	while (p->left != NULL) 
		p = p->left; 

	return p; 
} 


struct Node* deleteNode(struct Node* root, int item) {	

	if (root == NULL) 
		return root; 
	if (item< root->data ) 
		root->left = deleteNode(root->left,item); 
	else if( item > root->data ) 
		root->right = deleteNode(root->right, item); 
	else{ 
		if( (root->left == NULL) || (root->right == NULL) ){ 
			struct Node *temp = root->left ? root->left : root->right;								

			if (temp == NULL){ 
				temp = root; 
				root = NULL; 
			} 
			else 
				*root = *temp; 							
			free(temp); 
		} 
		else{ 
			struct Node* temp = minNode(root->right);
			root->data = temp->data; 
			root->right = deleteNode(root->right, temp->data); 
		} 
	} 

	if (root == NULL) 
		return root; 

	root->height = 1 + greater(height(root->left),height(root->right)); 
	int balance = Balance(root); 
 	//ll
	if (balance > 1 && Balance(root->left) >= 0) 
		return rotateRight(root); 
 	//lr
	if (balance > 1 && Balance(root->left) < 0) { 
		root->left = rotateLeft(root->left); 
		return rotateRight(root); 
	} 
	
 	//rr
	if (balance < -1 && Balance(root->right) <= 0) 
		return rotateLeft(root); 
	//rl
	if (balance < -1 && Balance(root->right) > 0){ 
		root->right = rotateRight(root->right); 
		return rotateLeft(root); 
	} 

	return root; 
} 



void inorder(struct Node* root){
	if (root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main() {
	struct Node* root = NULL;
	int x,r,c;
	printf("Enter the root of tree = ");
	scanf("%d",&r);
	root = insert(root,r);
	while(1){
	printf("\tWhat do you want to do?\n");
	printf("\t1. Insertion\n");
	printf("\t2. Deletion\n");
	printf("\t3. Inorder Traversal\n");
	printf("\t4. Quit\n");

	printf("\tEnter your choice : ");
        scanf("%d", &c);
	switch(c){
		case 1:							
			printf("Enter the Element to be inserted = ");
			scanf("%d",&x);			
			root = insert(root,x);
			printf("\nInserted!!\n");
			break;
		case 2: 			
			printf("Enter item to be deleted = ");
			scanf("%d",&x);
			root = deleteNode(root,x);
			printf("\nDeleted!!\n");			
			break;
	
		case 3:
			printf("\nInorder Traversal of the AVL Tree :\n");
			inorder(root);
			printf("\n");
			break;
	
		case 4:
			printf("\nThank you!!!\n");
			exit(0);
	}
	
	}

	return 0;
}




