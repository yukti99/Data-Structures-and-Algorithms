#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Stack{	
	unsigned capacity;
	int top;
	int *a ;
};


struct Stack* CreateStack(unsigned cap){
	
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->capacity = cap;
	s->top = -1;
	s->a = (int *)malloc(sizeof(int)*s->capacity);
	return s;
}

int isEmpty(struct Stack *s){
	return (s->top == -1);
}
int isFull(struct Stack *s){
	return (s->top == s->capacity);
}

void push(struct Stack* s, int item){
	
	if (isFull(s)){
		printf("\nOverflow Condition!\n");
		return ;
	}
	s->a[++s->top] = item;
	//printf("\nPushed into Stack - %d\n",item);	
}

void peek(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return ;
	}
	printf("\nTop of the Stack = %d\n",s->a[s->top]);
}
int pop(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return INT_MIN;
	}
	int popped = s->a[s->top--];
	return popped;	
}

struct Stack* Reverse(struct Stack*s){
	
	struct Stack* temp = s;
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return s;
	}
	struct Stack *R = CreateStack(100);
	while(temp->top != -1){
		push(R,pop(temp));
	}
	return R;
	
}

void display(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nUnderflow Condition!\n");
		return ;
	}
	printf("\nSTACK : \n");
	for(int i=s->top;i>=0;i--){
		printf("\t%d\n",s->a[i]);
	}
	printf("\n");
}
int main(){
	
	struct Stack *s = CreateStack(100);
	push(s,5);push(s,4);push(s,3);push(s,2);push(s,1);
	display(s);
	/*printf("\nThe popped element is : %d\n",pop(s));
	display(s);
	peek(s);
	printf("\nThe popped element is : %d\n",pop(s));
	display(s);
	peek(s);*/
	printf("\nAfter Reversing : \n");
	struct Stack* R = Reverse(s);
	display(R);
	
	
	return 0;
}
