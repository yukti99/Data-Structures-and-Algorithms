/* Stack implementation using linked List */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
	
	int data;
	struct StackNode* next;
};

struct StackNode* CreateNode(int data){
	struct StackNode *stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode; 
}

void push(struct StackNode** top){
	
	int item;
	printf("Enter the item you want to push in the stack : ");
	scanf("%d",&item);
	struct StackNode* s = CreateNode(item);
	//it is like changing head of a linked list
	s->next = *top;
	*top = s;
	printf("\nPushed to stack -%d\n",item);
}
int isEmpty(struct StackNode*top){
	return (!top);
}

int pop(struct StackNode** top){
	if (isEmpty(*top)){
		printf("\nThe Stack is Empty!\n");
		return INT_MIN;		
	}		
	struct StackNode* temp = *top;
	*top = (*top)->next;
	int popped = temp->data;
	free(temp);
	return popped;	
}

void peek(struct StackNode* top){
	if (isEmpty(top)){
		printf("\nThe Stack is Empty!\n");
		return ;		
	}
	printf("\nTop of the Stack : %d\n",top->data);
			
}

void display(struct StackNode* top){
	
	if (isEmpty(top)){
		printf("\nThe Stack is Empty!\n");
		return ;		
	}
	printf("\nSTACK : \n");
	struct StackNode* temp = top;
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	
	struct StackNode *s = NULL;
	int choice;
	while (1)
	{
	    printf("\n\n******************** STACK IMPLEMENTATION IN C USING LINKED LIST ********************\n\n");
		printf("\t\t\t1. Push element to stack \n");
	    printf("\t\t\t2. Delete element from stack \n");
	    printf("\t\t\t3. Display the top  of stack \n");
	    printf("\t\t\t4. Display all elements of stack \n");
	    printf("\t\t\t5. Quit \n");
	    printf("\t\t\tEnter your choice : ");
	    scanf("%d", &choice);
	    printf("\n");
	    switch (choice)
	    {
	        case 1:
	        	push(&s);
	        	break;
	        case 2:
	        	printf("\nPopped Element : %d\n\n",pop(&s));
	        	break;
	        case 3:
	        	peek(s);
	        	break;	        
	        case 4:
	        	display(s);
	        	break;
	        case 5:
	        	printf("Thank you!\n");
	        	exit(0);
	        default:
	        	printf("\a\nWrong choice! \n\n");
	    } 
	}	
		
}
