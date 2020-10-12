#include <stdio.h>
#include <stdlib.h>

/* COMPLETE BINARY TREE */

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
int b = 0,level = 0,p=0;

struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

// Insertion function
struct Node* insert(struct Node *root,int item){ 
			
	struct Node* node = root;
	if (root == NULL)
        	return CreateNode(item);
        	
    if(node->left == NULL)
    	node->left = CreateNode(item);
    
   	else if(node->left != NULL && node->right == NULL)
        node->right = CreateNode(item);
    
    else if(node->left != NULL && node->right != NULL && p==0){
    	insert(node->left,item);
        p=1;
	}        
    else if(node->left!=NULL && node->right!= NULL && p==1){
    	insert(node->right,item);
        p=0; 
	}
        

    return node;
     
	
}

void search(struct Node *node,int item){

	struct Node *p = node;
	if (p->data == item){		
		b = 1	;		
		printf("\nElement FOUND at level %d : %d\n",level,node->data);
		
	}
	// moving levels downwards
	level++;
	
	if(p->left != NULL){
		search(p->left,item);
	}
	
	if(p->right != NULL){
		search(p->right,item);
	}
	// moving levels back upwards
	level--;

}
void display(struct Node *node){

	struct Node *p = node;
	if(p == node)		
		printf("\nElement present at level %d : %d\n",level,node->data); 	
	
	level++;
	
	if(p->left != NULL)
		display(p->left);
	
	
	if(p->right != NULL)
		display(p->right);
	
	level--;

}

// for inorder traversal 
void inorder(struct Node *node){ 	
	
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
	
} 

// Preorder Traversal
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
	printf("\t2. Search\n");
	printf("\t3. Traversal\n");
	printf("\t4. Quit\n");
	printf("\tEnter your choice : ");
        scanf("%d", &c);
	switch(c){
		case 1:							
			printf("Enter the Element to be inserted = ");
			scanf("%d",&x);			
			insert(root,x);
			printf("\nInserted!!\n");
			printf("root = %d\n",root->data);
			break;
		case 2: 			
			printf("Enter element to be searched = ");
			scanf("%d",&x);
			search(root,x);
			printf("\n");
			if (b==0)
				printf("ELEMENT NOT FOUND\n");		
			break; 		
		case 3:
			printf("\nTraversal of the Tree :\n");
			display(root);
			printf("\n");
			break;
		case 4:
			printf("\nTHANK YOU\n");
			exit(0);
	}
	
	}

	return 0;
}
