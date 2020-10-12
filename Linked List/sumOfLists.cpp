#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head,int item){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	n->next = *head;
	*head = n;
}
struct Node* CreateNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

void printList(struct Node* head){
	if (head == NULL){
		printf("\nEmpty!!\n");
		return ;
	}
	printf("\nLinked List : \n");
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct Node* addTwoLists(struct Node* first,struct Node* second){
	
	struct Node* temp, *prev = NULL;
	struct Node* res = NULL;
	int sum=0,carry = 0;
	
	while(first || second){
		sum = carry+ (first?first->data:0)+(second?second->data:0);		
		carry = (sum>=10)?1:0;
		sum = sum%10;
		
		temp = CreateNode(sum);
		if (res == NULL)
			res = temp;
		else
			prev->next =temp;
			
		prev = temp;
		if (first)first = first->next;
		if (second)second = second->next;	
	}
	if (carry>0)
		temp->next = CreateNode(carry);
	return res;
	
} 
int main(){
	struct Node* res = NULL; 
    struct Node* first = NULL; 
    struct Node* second = NULL; 
  
    // create first list 7->5->9->4->6 
    push(&first, 6); 
    push(&first, 4); 
    push(&first, 9); 
    push(&first, 5); 
    push(&first, 7); 
    printf("First List is "); 
    printList(first); 
  
    // create second list 8->4 
    push(&second, 4); 
    push(&second, 8); 
    push(&second, 9);
    printf("Second List is "); 
    printList(second); 
    
     // Add the two lists and see result 
    res = addTwoLists(first, second); 
    printf("Resultant list is "); 
    printList(res); 
  
	
	
	return 0;
}
