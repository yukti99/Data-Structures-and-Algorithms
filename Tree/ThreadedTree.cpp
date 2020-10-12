/*
Threaded Binary Tree:
a) Insertion 
b) Inorder Traversal without Recursion 

*/

#include <stdio.h>
#include <stdlib.h>


struct Tnode{
	
	struct Tnode *left,*right;
	int data;
	int lthread;
	int rthread;	
};

// Insertion in Binary Threaded Tree
struct Tnode* insert(struct Tnode* root,int data){
	
	struct Tnode* p = root;
	struct Tnode* par = NULL;
	
	// searching for location to insert the data
	while(p!= NULL){
		if (data == p->data){			
			printf("\nNo duplicates Allowed !\n");
			return root;			
		}
		par = p;
		if (data < p->data){
			if (p->lthread == 0)
				p = p->left;
			else
				break;			
		}
		else{
			if (p->rthread == 0 )
				p = p->right;			
			else
				break;	
			
		}  	
	}
	// new node
	struct Tnode* n = (struct Tnode*)malloc(sizeof(struct Tnode));
	n->lthread = n->rthread = 1;
	n->data = data;
	
	// insertion at  root
	if (par == NULL){
		root = n;
		n->left = n->right = NULL;
	}
	
	// insertion at parent's left
	else if (data < par->data){
		n->left = par->left;
		par->left = n;
		n->right = par;
		par->lthread = 0;		
	}
	// insertion at parent's right
	else{
		n->right = par->right;
		par->right = n;
		n->left = par;
		par->rthread = 0;
	}
	printf("\nInserted!!\n");
	return root;	
}

struct Tnode* Successor(struct Tnode* node){
	if (node->rthread == 1)
		return node->right;
	
	node = node->right;
	while(node->lthread == 0){
		node = node->left;		
	}
	return node;
}
struct Tnode* search(struct Tnode* node,int item){
	
	if (node == NULL || node->data == item)
		return node;
		
	if (item > node->data)
		return search(node->right,item);
		
	return search(node->left,item); 
}


void inorder(struct Tnode* root){
	if (root == NULL){
		printf("\nThe Tree is empty!\n");
		return ;
	}
	struct Tnode* p = root;
	while(p->lthread == 0)
		p = p->left;
		
	while(p != NULL){
		printf("%d ",p->data);
		p = Successor(p);
	}
}

int main(){
	
	printf("\n\tTHREADED BINARY TREE\n");
	struct Tnode* root = NULL;	
	int x,r,choice,h=0;
	printf("Enter the root of tree = ");
	scanf("%d",&r);
	root = insert(root,r);
	while(1){
		printf("\n\tWhat do you want to do?\n\n");
		printf("\t1. Insertion\n");
		printf("\t2. Search\n");
		printf("\t3. Inorder Traversal\n");
		printf("\t4. Quit\n");
		printf("\tEnter your choice : ");
	    scanf("%d", &choice);
		switch(choice){
			case 1:							
				printf("Enter the Element to be inserted = ");
				scanf("%d",&x);			
				insert(root,x);
				break;
			case 2: 			
				printf("Enter element to be searched = ");
				scanf("%d",&x);
				if (search(root,x))
					printf("\nElement Found!\n");
				else
					printf("\nElement NOT Found!\n");
				break;
		
			case 3:
				printf("\nInorder Traversal of the Tree :\n");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("\nThank you!!\n");
				exit(0);
			default:
				printf("\nWrong choice!\n");
			
		}
	
	}

	return 0;
}
