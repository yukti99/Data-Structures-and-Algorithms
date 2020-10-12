#include <stdio.h>
#include <stdlib.h>


struct Qnode{
	int data;
	struct Qnode *next;
};

struct Queue{
	
	struct Qnode* front,*rear;
};


struct Queue* Create(){
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue*q,int data){
	struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));
	temp->data = data;
	// for  1st element 
	if (q->rear == NULL){
		q->rear=q->front = temp;		
	}
	q->rear->next = temp;
	q->rear = temp;   //now update the rear of the queue
}

struct Qnode* dequeue(struct Queue* q){
	// queue is empty
	if (q->front == NULL){
		return NULL;
	}
	struct Qnode* temp = q->front;    // store the front of the queue
	q->front = q->front->next;
	
	// if front is NULL make rear null too
	if (q->front == NULL)
		q->rear = NULL; // queue has become empty
	return temp;
}
void display(struct Queue*q){
	struct Qnode* temp = q->front;
	printf("\nQUEUE \n");
	while(temp != q->rear && temp!=NULL){
		printf("\t%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main(){
	struct Queue*  q = Create();
	enqueue(q,1);enqueue(q,2);enqueue(q,3);enqueue(q,4);enqueue(q,5);enqueue(q,6);
	display(q);
	printf("\nDequeued Element = %d\n",dequeue(q)->data);
	printf("\nDequeued Element = %d\n",dequeue(q)->data);
	display(q);
	enqueue(q,7);enqueue(q,8);
	display(q);
	printf("\nDequeued Element = %d\n",dequeue(q)->data);
	display(q);
	
	return 0;
}
