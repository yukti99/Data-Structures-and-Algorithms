#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100

struct TwoStacks{
	
	int size;
	int *a;
	int top1,top2;
};

struct TwoStacks* Create(int size){
	
	struct TwoStacks* s = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
	s->size = size;
	s->top1 = -1;
	s->top2 = size;	
	s->a = (int*)malloc(sizeof(int)*size);
}


void push1(struct TwoStacks*s, int item){
	
	if (s->top1 < s->top2-1){
		
		s->a[++s->top1] = item;
		printf("\nPushed to Stack-1 : %d\n",item);	
	}
	else{
		printf("\nStack Overflow!\n");
		return ;
	}
	
	
}
void push2(struct TwoStacks*s, int item){
	
	if (s->top1 < s->top2-1){		
		s->a[--s->top2] = item;
		printf("\nPushed to Stack-2 : 	%d\n",item);	
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
	int i;
	for(i = s->top1;i>=0;i--){
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
	
	struct TwoStacks *ts = Create(N);
	int item,choice;	
	while (1){
	   printf("\n\tEnter what you want to do");
	   printf("\n\t1.Add element to stack-1 \n");
	   printf("\n\t2.Add element to stack-2 \n");
	   printf("\n\t3.Pop element from stack-1 \n");
	   printf("\n\t4.Pop element from stack-2 \n");
	   printf("\n\t5.Display Stack-1 \n");
	   printf("\n\t6.Display Stack-2 \n");
	   printf("\n\t7.Quit \n\n");
	   scanf("%d",&choice);
	   printf("\n");
	   switch (choice){
	    
	        case 1:
			printf("Enter the element you want to push to stack-1 : ");
			scanf("%d",&item);
			push1(ts,item);
			break;
		case 2:
			printf("Enter the element you want to push to stack-2 : ");
			scanf("%d",&item);
			push2(ts,item);
			break;
		case 3:
			printf("\nPopped Element from Stack-1 : %d\n",pop1(ts));
			break;
		case 4:
			printf("\nPopped Element from Stack-2 : %d\n",pop2(ts));
			break;
		case 5:
			display1(ts);
			break;
		case 6:
			display2(ts);
			break;
		case 7:
			printf("\nThank You\n");
			exit(0);
		default:
			printf("\nWrong choice!!\n");
	    } 
	}		
	
	
	return 0;
}
