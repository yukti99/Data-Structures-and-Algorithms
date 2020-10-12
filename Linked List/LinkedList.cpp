/* Implemention of linked list in C */

#include <stdio.h>

struct Node{
	int data;
	struct Node* link;
};


int main(){
	
	Node* A;
	A = NULL;
	Node* temp = (Node*)malloc(sizeof(Node));
	*temp.data = 2;           // temp->data = 2;
	*temp.link = NULL;        // temp->link = NULL;
	A = temp;
	
	
	
	return 0;
}
