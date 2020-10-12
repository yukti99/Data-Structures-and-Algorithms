#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data ;
	struct Node *next;
	
}*head ;

void push(int new_data){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;	
}

int getnode(int index){
	
	int i=0;
	struct Node* temp = head;
	if(temp == NULL){
		printf("List cannot be empty!\n");
		return 0;
	}
	while(temp!= NULL && i<index){
		temp = temp->next;
		i++;
	}
	if (temp == NULL){
		printf("Given index does not exist!\n");
		return 0;
	}
	return temp->data;
		
}/*
// recursive function
int getnode(struct Node* node,int index){
	
	int count=0;
	if (count == index)
		return node->data;
	return getnode(node->next,index-1);
		
}*/

int freq = 0;
int occurence(int key){
	
	int count=0;
	struct Node* temp = head;
	while (temp != NULL){
		if (key == temp->data)
			count++;
		temp = temp->next;
	}
	return count;
	
}
void printList(struct Node* node){
	
	while(NULL != node ){
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}


int main(){
	
	push(1);
	push(2);
	push(1);
	push(3);
	push(2);
	push(1);
	printList(head);
	int item = 1;
	printf("The occurence in the list = %d\n",occurence(item));
	//int index = 3;
	//printf("The node at index %d is = %d\n",index,getnode(index)) ;
	
	return 0;
}
