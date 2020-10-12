#include <stdio.h>
#include <stdlib.h>


struct Cqueue{
	
	int size;
	int front,rear;
	int *a;
};

struct Cqueue* Create(int size){
	struct Cqueue *q = (struct Cqueue*)malloc(sizeof(struct Cqueue));
	q->a = (int*)malloc(sizeof(int)*size);
	q->size = size;
	q->front = q->rear = -1;
	return q;	
}

void enqueue(struct  Cqueue*q,int val){
	if ((q->rear == q->size-1  && q->front == 0)|| (q->rear = (q->front- 1)%q->size)){
		printf("\nFULL QUEUE\n");
		return ;
	}
	// for first element
	else if(q->front ==-1){
		q->front = q->rear = 0;
		q->a[q->rear] = val;
		
	}
	
	else if (q->rear == q->size-1 && q->front != 0){
		q->rear = 0;
		q->a[q->rear] = val;
	}
	else{
		q->a[++q->rear] = val;
	}	
}

int dequeue(struct Cqueue*q){
	// check empty condition
	if (q->front == -1){
		printf("\nEMPTY QUEUE\n");
		return INT_MIN ;	
	}
	int data = q->a[q->front];
	if (q->front == q->rear){
		q->front = q->rear = -1;		
	}
	else if (q->front == q->size-1){
		q->front = 0;
	}
	else
		q->front++;
	return data;
}
void  display(struct Cqueue*q){
	if (q->front == -1){
	    printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (q->rear >= q->front){
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ",q->a[i]);
    }
    else{
        for (int i = q->front; i < q->size; i++)
            printf("%d ", q->a[i]);
 
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->a[i]);
    }
}

int main(){
	struct Cqueue*q = Create(15);
	// Inserting elements in Circular Queue
    enqueue(q,14);
    enqueue(q,22);
    enqueue(q,13);
    enqueue(q,-6);
 
    // Display elements present in Circular Queue
    display(q);
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", dequeue(q));
    printf("\nDeleted value = %d", dequeue(q));
 
    display(q);
 
    enqueue(q,9);
    enqueue(q,20);
    enqueue(q,5);
 
    display(q);
 
    enqueue(q,20);
    return 0;
	
	return 0;
}
