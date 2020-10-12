/* Array implementation of Queue */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
	
	int front,rear,size;
	unsigned capacity;
	int *array;
};

struct Queue *CreateQueue(unsigned capacity){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->size = 0;
	q->front = q->rear = -1;       // initialize both rear and front as -1
	q->array = (int*)malloc(sizeof(q->capacity * sizeof(int)));
	return q;
}

int isFull(struct Queue *q){
	return (q->size == q->capacity);   //  or q->rear = q->size-1
}

int isEmpty(struct Queue *q){
	return (q->size == 0);    // q->rear = -1
}
void Enqueue(struct Queue *q){
	
	int item;
	printf("\nEnter the element you want to insert: ");
	scanf("%d",&item);
	
	if (isFull(q)){
		printf("\nQueue Overflow !\n");
		return ;
	}
	if (q->front == -1)
		q->front = 0;      // when first element is added
	q->rear++ ;
	q->array[q->rear] = item ;
	q->size++;
	printf("\nEnqueued to Queue : %d\n",item);	
	
}

int Dequeue(struct Queue *q){
	
	if (isEmpty(q)){
		printf("Queue Underflow !\n");
		return INT_MIN;
	}
	int x = q->array[q->front];
	q->front++ ;	
	q->size-- ;
	if (q->front > q->rear)       // means the queue has become empty
		q->front = q->rear = -1;
	return x;
}

int front(struct Queue *q){
	
	if (isEmpty(q)){
		printf("\nThe Queue is empty!\n");
		return INT_MIN;
	}
	return ( q->array[q->front] );
}

int rear(struct Queue *q){
	
	if (isEmpty(q)){
		printf("\nThe Queue is empty!\n");
		return INT_MIN;
	}
	return (q->array[q->rear]);
}

void display(struct Queue *q){
	
	
	if (isEmpty(q)){
		printf("The queue is Empty!\n");
		return ;
	}
	printf("\nQUEUE : \n");	
	for(int i=q->front; i<= q->rear ;i++){
		
		printf("\t%d\n",q->array[i] ); 
	}
	printf("\n");
}
void Reverse(struct Queue *q){
	
	printf("\nREVERSED QUEUE : \n");	
	for(int i=q->rear; i>= q->front ;i--){
		
		printf("\t%d\n",q->array[i] ); 
	}
	printf("\n");
	
}


int main(){
	struct Queue *q = CreateQueue(1000);
	int choice;
    while (1)
    {
        printf("\n\n**********************  QUEUE IMPLEMENTATION IN C  ********************\n\n");
		printf("\t\t\t1. Insert element to queue \n");
        printf("\t\t\t2. Delete element from queue \n");
        printf("\t\t\t3. Display the front of queue \n");
        printf("\t\t\t4. Display the rear of queue \n");
        printf("\t\t\t5. Display all elements of queue \n");
        printf("\t\t\t6. Reverse the queue \n");
        printf("\t\t\t7. Quit \n");        
        printf("\t\t\tEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
            	Enqueue(q);
            	break;
            case 2:
            	printf("\nRemoved Element : %d\n\n",Dequeue(q));
            	break;
            case 3:
            	printf("\nFront of queue : %d\n\n",front(q));
            	break;
            case 4:
            	printf("\nRear of queue : %d\n\n",rear(q));
            	break;
            case 5:
            	display(q);
            	break;
            case 6:
            	Reverse(q);
            	break;
            case 7:
            	printf("Thank you!\n");
            	exit(0);
            default:
            	printf("\a\nWrong choice! \n\n");
        } 
    } 
	
	
	return 0;
}
