#include <stdio.h>
#include <stdlib.h>

#define N 100
struct Stack{
	
	int top;
	int size;
	int *a;
};

struct Stack* Create(int size){
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = -1;
	s->size = size;
	s->a = (int*)malloc(sizeof(int)*size);
	return s;
}

int isEmpty(struct Stack*s){
	return (s->top==-1);
}
int isFull(struct Stack*s){
	return (s->top == s->size -1);
}
int peek(struct Stack*s){
	return (s->top);
}

void push(struct Stack* s,int x){
	
	if (!isFull(s))
		s->a[++s->top] = x;	
	
}

int pop(struct Stack* s){
	if (!isEmpty(s))
		return s->a[s->top--];
	
}





int main(){
	
	return 0;
}
