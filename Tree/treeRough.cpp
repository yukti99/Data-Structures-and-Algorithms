#include <stdio.h>
#include <stdlib.h>
/*
// Search Function
struct Node* search(struct Node *root,int item){
	int c = count;
	struct Node *p1,*p2;
	
	if (root->data == item)
        return root;
	 
	if (root == NULL){
		printf("0\n");
		return NULL;
	}
     
	while(c){
		c--;						
		if (root->left && root->right){
			p1 = root->left;
			p2 = root->right;
			if (p1->data == item){
				printf("1\n");
				return p1; 	
			} 				
			else if (p2->data == item){
				printf("2\n");
				return p2;
			} 
			else {
				printf("3\n");
				search(p1,item);
				printf("4\n");
				search(p2,item);			
			} 	
			
	}
	else if (root->left && !root->right){
		printf("5\n");
		search(root->left,item);
	}
		
			
	else if (!root->left && root->right){
		printf("6\n");
		search(root->right,item); 
	}
		
}
int hasBothChild(struct Node* temp){
    return temp && temp->left && temp->right;
}
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
while(temp != NULL){
		if(temp->left == NULL && cl<cr){
			cl++;
            temp->left = n;
			break;
 		}       
        else if(temp->right == NULL){
        	cr++;
            temp->right = n;
			break;
 		}        
        else if(hasBothChild(temp)){
			temp = temp->left; 	
		}
	}   

			
		 	 	
  			
}
void Search(struct Node* node,int item){
	
	if (node == NULL)
		return ;	
	search(node->left,item); 
	if (node->data == item)
		printf("\nElement Found!\n");	
	search(node->right,item);
	
}*/ 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct Node *minValueNode(struct Node* node)
{
    struct Node *current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct Node *deleteNode(struct Node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
/*int x;
	struct Node *root = CreateNode(1);
	insert(root,3);
	insert(root,6);
	insert(root,2);
	insert(root,4);
	insert(root,5);
	struct Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
	printf("What do you want to search");
	scanf("%d",&x);
	struct Node *s = Search(root,x);
	if (s)
		printf("The Item -%d found!\n",s->data);
	else
		printf("The Item - %d not found !\n",x);
	printf("\nInorder Traversal of  BST : \n");
	inorder(root);	
	printf("\n");
	printf("\nPreorder Traversal of  BST : \n");
	preorder(root);	
	printf("\n");
	printf("\nPostorder Traversal of  BST : \n");
	postorder(root);	
	printf("\n");*/
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

// Preorder Traversal
void preorder(struct Node* node){
	if (node == NULL)
		return ;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}  
int main(){
	
	
	return 0;
}
