#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Cqueue{
	int rear,front;
	int size;
	int *a;
};

struct Cqueue* Create(int size){
	struct Cqueue* q = (struct Cqueue*)malloc(sizeof(struct Cqueue));
	q->a = (int*)malloc(sizeof(int)*size);
	q->size = size;
	q->front = q->rear = -1;
	return q;
}
int isFull(struct Cqueue* q){
	if ((q->front == 0 && q->rear == q->size-1)|| (q->front == q->rear+1))
		return 1;
	return 0;
}
int isEmpty(struct Cqueue* q){
	return (q->front == -1);
}
void Enqueue(struct Cqueue* q,int item){
	if (isFull(q)){
			printf("\nFull!!\n");
			return ;
	}
	else if (q->front == -1)
		q->front = 0;
	q->rear = (q->rear+1) % q->size;
	q->a[q->rear] = item;
	printf("\n Inserted -> %d\n", item);
}
int Dequeue(struct Cqueue* q){
	if (isEmpty(q)){
		printf("\nEmpty!!\n");
		return INT_MIN;
	}
	int p = q->a[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front = (q->front+1)%q->size;
	printf("\n Deleted element -> %d \n",p);
    return(p);
}
void display(struct Cqueue* q){
	int i=0;
	if (isEmpty(q)){	
		printf("\nEmpty!!\n");
		return ;
	}	
	printf("\n Front -> %d ",q->front);
    printf("\n Items -> ");
    if (q->rear > q->front){
    	for(i=q->front;i<=q->rear;i++)
			printf("%d ",q->a[i]);
	}
	else{
		for (i = q->front; i < q->size; i++) 
            printf("%d ", q->a[i]); 
  
        for (i = 0; i <= q->rear; i++) 
            printf("%d ", q->a[i]); 
	}
	printf("\n Rear -> %d \n",q->rear);
}





int main(){
	struct Cqueue*q = Create(10);
	Enqueue(q,1);
	Enqueue(q,2);
	Enqueue(q,3);
	Enqueue(q,4);
	Enqueue(q,5);
	display(q);
	Dequeue(q);
	display(q);
	Enqueue(q,0);
	Enqueue(q,6);
	Enqueue(q,7);
	Enqueue(q,8);
	Enqueue(q,9);
	display(q);
	Enqueue(q,10);
	display(q);
	Enqueue(q,11);
	display(q);
	Dequeue(q);
	Dequeue(q);
	Dequeue(q);
	Dequeue(q);Dequeue(q);Dequeue(q);Dequeue(q);Dequeue(q);Dequeue(q);Dequeue(q);
	display(q);	
	Enqueue(q,13);
	Enqueue(q,18);
	display(q);	
	
	
	
	return 0;
}
