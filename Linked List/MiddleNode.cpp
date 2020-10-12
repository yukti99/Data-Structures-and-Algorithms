/* Linked list implementation */

#include <stdio.h>
#include <stdlib.h>


struct Node{
	
	int data ;
	struct Node* next ;	
};
struct Node* head = NULL;

// printing the linked list starting from the head node
void printList(struct Node* node){
	
	printf("\nLinked List :");	
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
}

void append(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = head;
	new_node->next  = NULL;
	new_node->data = new_data;
	if (NULL == head){		
		head = new_node;
		return ;
	}
	while(NULL != last->next)
		last = last->next;
	last->next = new_node;
	return ;
}

void printMiddle()
{
    int f=0;
	struct Node *n1= head;
    struct Node *n2 = head,*prev = head;
 
    if (head!=NULL)
    {
        while (n2 != NULL && n2->next != NULL)
        {
            n2 = n2->next->next;
			prev = n1;  // to print two middle values in case of even length of linked list
            n1 = n1->next;
    
            if (n2 == NULL){
            	f=1;
            	break;            	
			}			
        }
        if (f==1)
        	printf("\nThe middle elements are [%d],[%d]\n",prev->data,n1->data);
        else
        	printf("\nThe middle element is [%d]\n\n", n1->data);
    }
}
/*
OR
int length(){
	
	int l=0;
	struct Node* n = head;
	while(n!= NULL){
		l++;
		n = n->next ;
	}
	return l;
}
int middle(int l){
	int i=0;
	struct Node*n = head;
	if (n==NULL){
		return ;
	}
	while(n!= NULL && i!= l/2){
		i++;
		n = n->next;
	}
		
	printf("\nMiddle Element = %d\n",n->data);
	
}
*/
// Driver program 
int main(){
	
	int i,n,x,d,s,a,b,c,p;	
	printf("Enter the number of elements you want in linked list = ");
	scanf("%d",&n);
	printf("Enter Linked list elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		append(x);
	}	
	printList(head);
	printMiddle();
	return 0;
}
