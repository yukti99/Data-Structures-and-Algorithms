#include <stdio.h>
#include <stdlib.h>
using namespace std;



struct Node{
	
	int data;
	struct Node* next;
	struct Node* down;
	
} *head;
struct Node *tempv1=head,*tempv2=head;

void create(int n,int new_data){
	
	int i=0,j=0;	
	while(i<=n){
    	struct Node *temph1 = tempv1;
    	if (i)
    		struct Node *temph2 = tempv2->next;
    	while(j<=n){
    		j++;
    		struct Node *newh = (struct Node*)malloc(sizeof(struct Node));
    		newh->data = newh;
	    	newh->next = NULL;
	    	newh->down = NULL;
	    	temph1->next = newh;
	    	temph1 = newh;
	    	if (i && j-2){
	    		temph2->down = temph1;
	    		temph2 = temph2->next; 
			}
		}
		i++;
		struct Node *newv = (struct Node*)malloc(sizeof(struct Node));
		newv->next = NULL;
		newv->down = NULL;
		newv->data = new_data;
		tempv2 = tempv1;
		tempv1->down = newv;
		tempv1 = newv;    
    	
	}
    
    	
}
/*
void column(int new_data){
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node == NULL)
	{
		printf("\nOut of Memory Space:\n");
		exit(0);
    }
    new_node->data = new_data;
    
	
	
}*/

int main(){
	
	
	
	
	return 0;
}
