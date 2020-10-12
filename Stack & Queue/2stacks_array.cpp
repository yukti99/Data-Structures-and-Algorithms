#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Implementing two Stacks using one array - Memore efficient Method*/
// elements can be pushed till there is diffrence between top1 and top2 so no overwriting or wastage of memory occurs

struct TwoStacks{
	
	unsigned size;
	int *a;
	int top1,top2;
};

struct TwoStacks* Create(unsigned size){
	
	struct TwoStacks* s = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
	s->size = size;
	s->top1 = -1;
	s->top2 = size;	
	s->a = (int*)malloc(sizeof(int)*size);
}

void push1(struct TwoStacks*s, int item){
	
	if (s->top1 < s->top2-1){
		
		s->a[++s->top1] = item;
		printf("\nPushed to Stack-1 %d\n",item);	
	}
	else{
		printf("\nStack Overflow!\n");
		return ;
	}
	
	
}
void push2(struct TwoStacks*s, int item){
	
	if (s->top1 < s->top2-1){		
		s->a[--s->top2] = item;
		printf("\nPushed to Stack-2 %d\n",item);	
	}
	else{
		printf("\nStack Overflow!\n");
		return ;
	}
}

int pop1(struct TwoStacks *s){
	
	if (s->top1 >= 0){
		int popped = s->a[s->top1--];
		return popped;
	}
	else{
		printf("\nStack Underflow\n");
		return INT_MIN;
	}
}

int pop2(struct TwoStacks *s){
	
	if (s->top2 < s->size){
		int popped = s->a[s->top2++];
		return popped;
	}
	else{
		printf("\nStack Underflow\n");
		return INT_MIN;
	}
}

void display1(struct TwoStacks *s){
	
	printf("\nSTACK-1 :\n");
	for(int i = s->top1;i>=0;i--){
		printf("\t%d\n",s->a[i]);
	}
	printf("\n");
}

void display2(struct TwoStacks *s){
	
	printf("\nSTACK-2 :\n");
	int i = s->top2;
	while(i != s->size){
		printf("\t%d\n",s->a[i]);
		i++;
	}
	printf("\n");
}





int main(){
	
	struct TwoStacks *ts = Create(15);
	push1(ts,5);push1(ts,4);push1(ts,3);push1(ts,2);push1(ts,1);push1(ts,6);push1(ts,7);push1(ts,8);
	push2(ts,10);push2(ts,11);push2(ts,12);push2(ts,13);push2(ts,14);push2(ts,15);push2(ts,16);
	display1(ts);
	display2(ts);
	printf("\nPopped Element from Stack-1 : %d\n",pop1(ts));
	display1(ts);
	printf("\nPopped Element from Stack-2 : %d\n",pop2(ts));
	display2(ts);
	
	return 0;
}
