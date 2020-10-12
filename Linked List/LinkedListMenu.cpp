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
	
	printf("\nLinked List : ");	
	while(NULL != node){
		printf("%d ",node->data);
		node = node->next;		
	}
}


// insertion at the beginning
void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;

}

// Insertion at any position
void insertAt(int position,int new_data){
	
	printf("\nLinked List after insertion of value %d at position %d : ",new_data,position);
	int counter=0;
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
	new_node->data = new_data;
	if (temp == NULL){
		printf("The linked list cannot be empty\n");
		return;
	}
	if (0 == position){
		new_node->next = head;
		head = new_node;
		return ;	
	}

	while (counter != position-1){
		temp = temp->next;
		counter++;		
	}
	//temp = temp->next;
	new_node->next = temp->next;
	temp->next = new_node;
	
	
}
// insertion from the end

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
void Delete(int key){
	
	
	struct Node* temp = head;
	struct Node* prev ;
	// if head node is to be deleted
	if (temp != NULL && temp->data == key){
		head = temp->next;
		free(temp);
		return ;
	}
	while(temp!= NULL && temp->data != key){
		
		prev = temp;
		temp = temp->next;	
	}
	// key does not exist in the linked list
	if (NULL == temp)
		return ;
	prev->next = temp->next;
	free(temp);
}

// returns the position of the element to be the search else -1
int Search(int key){
	
	struct Node* temp = head;
	int index = 0;
	while( temp!=NULL && temp->data != key){
		index++;
		temp = temp->next;		
	}
	return (temp!=NULL?index:-1);
	
}

int isPalindrome(){
	
	struct Node *left=head,*right=head;
	if (head==NULL)
		return 1;
	while(right->next != NULL){
		right = right->next;
	}
	while(left != right){
		if (left->data != right->data){
			return 0;
		}
		left = left->next;
		right = right->next;
	}
	return 1;	
}


// swapping nodes not without swapping data
void swap_nodes(int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct Node *prevX = NULL, *currX =head;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct Node *prevY = NULL, *currY = head;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       head = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       head = currX;
 
   // Swap next pointers
   struct Node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
 

int count(int k){
	int c=0;
	struct Node*n = head;
	if (head == NULL){
		return -1;
	}
	while(n!=NULL){
		if (n->data == k)
			c++;
		n = n->next;
	}
	return c;
}
struct Node* SortedMerge(struct Node* a, struct Node* b)  
{ 
  struct Node* result = NULL; 
  
  /* Base cases */
  if (a == NULL)  
     return(b); 
  else if (b==NULL)  
     return(a); 
  
  /* Pick either a or b, and recur */
  if (a->data <= b->data)  
  { 
     result = a; 
     result->next = SortedMerge(a->next, b); 
  } 
  else 
  { 
     result = b; 
     result->next = SortedMerge(a, b->next); 
  } 
  return(result); 


void fromlast(int n){
	int c=0;
	struct Node *p1=head,*p2=head;
	if (NULL!=head){
		while(c!=n) {
			if (p1 == NULL){
				printf("Out of bound!\n");
				return ;
			}
			p1 = p1->next;
			c++	;		
		}
		while(p1 != NULL){
			p1 = p1->next;
			p2 = p2->next;
		}
		printf("n The %dth node from end = %d\n",n,p2->data);
	}
}

int length(){
	
	int l=0;
	struct Node* n = head;
	while(n!= NULL){
		l++;
		n = n->next ;
	}
	return l;
}


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
	Delete(1);		
	printList(head);	
	swap_nodes(2,5);
	printList(head);
	/*
	printf("\ncount = %d\n",count(2));
	//fromlast(4);
	printf("\nEnter the element you want to insert at beginning = ");
	scanf("%d",&a);
	push(a);
	printList(head);
	printf("\nEnter the element you want to insert at end = ");
	scanf("%d",&b);
	append(b);
	printList(head);
	printf("\nEnter the element to be inserted in the middle = ");
	scanf("%d",&c);
	printf("\nEnter the position = ");
	scanf("%d",&p);
	insertAt(p,c);
	printList(head);
	printf("\nEnter the element you want to delete = ");
	scanf("%d",&d);
	Delete(d);
	printf("\nAfter deleting linked list is : ");
	printList(head);	
	printf("\nEnter the element you want to search = ");
	scanf("%d",&s);
	printf("\nElement found at index = %d\n",Search(s));
	*/
	return 0;
}
