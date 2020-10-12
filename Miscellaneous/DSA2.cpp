#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* right;
	struct Node* down ;
};

struct Node* Create(int i,int j,int m,int n){
	
	if (i>m-1 || j>n-1)
		return NULL;
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = rand()%10 + 1;
	new_node->right = Create(i,j+1,m,n);
	new_node->down = Create(i+1,j,m,n);
	return new_node;
}

void display(struct Node* head){
	
	struct Node *rp;
	struct Node *dp = head;
	while(dp){
		rp = dp;
		while(rp){
			printf("%d ",rp->data);
			rp = rp->right;
		}
		printf("\n");
		dp = dp->down;
		
	} 
}
void display_node(struct Node* head,int i, int j){
	
	int a=0,b=0;
	
	struct Node *rp;
	struct Node *dp = head;
	while(dp != NULL){
		rp = dp;
		while(rp != NULL){
			if (a == i && b==j){
				printf("%d\n",rp->data);
				return ;				
			}				
			rp = rp->right;
			b++;
		}
		printf("\n");
		dp = dp->down;
		a++;
		
	} 
}


int main(){
	
	struct Node* head = Create(0,0,3,3);
	//display(head);
	//printf("\n");
	display_node(head,1,2);
	
	return 0;
}
