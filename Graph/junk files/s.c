#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Stack{
	
	int top;
	int size;
	int *a;
	
};

struct Stack *CreateS(int  size){
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = -1;
	s->size = size;
	s->a = (int *)malloc(s->size *  sizeof(int));
	return s;
}

int isFullS(struct Stack *s){
	return (s->top == s->size -1) ;
}
	

int isEmptyS(struct Stack *stack){
	return (s->top == -1);
}
	
	
void push(struct Stack *s,int item){	
	if (isFull(s))
		return ;
	s->a[++s->top] = item;
		
}
void peek(struct Stack *s){
	
	if (isEmpty(s))
		return ;
	return s->a[s->top];
}
int pop(struct Stack *s){
	if (isEmpty(s))
		return s->top;	
	return s->array[s->top--];
}

void  displayS(struct Stack *s){
	if (isEmpty(s))	
		return ;	
	int c = s->top ;
	for(int i = s->top; i>=0 ; i--)
		printf("%d\n",s->a[i]);
	
	printf("\n");
}

