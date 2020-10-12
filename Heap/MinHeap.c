#include<stdio.h>
#include<stdlib.h>

/* Minimum and Maximum binary heap */

void swap(int *a, int *b){
	int t  = *a;
	*a = *b;
	*b = t;
}

// Array implemenatation of a Binary Heap
struct Minheap{
    int *a;
    int capacity;
    int size ;
};

struct Minheap* Createheap(int capacity){
    struct Minheap* h = (struct Minheap*)malloc(sizeof(struct Minheap));
    h->size = 0;
    h->capacity = capacity;
    h->a = (int *)malloc(sizeof(int)*capacity);
    return h;
}
int parent(int i){
    return ((i-1)/2);
}
int left(int i){
	return (2*i + 1);
}
int right(int i){
	return (2*i + 2);
}
void heapifyUp(struct Minheap *h,int i){	
	while(i!= 0 && h->a[parent(i)] > h->a[i]){
        swap(&h->a[parent(i)],&h->a[i]);
        i = parent(i);
    }   
}

void insert(struct Minheap *h,int data){
    if (h->size == h->capacity){
        printf("\nOverflow Condition!!\n");
        return ;
    }
    h->size++;
    // Enter element at the end then heapify the tree
    int i = h->size - 1;
    h->a[i]  = data;
    // Heapify the tree if the heap condition is violated
    heapifyUp(h,i);
     
}
void heapifyDown(struct Minheap *h,int i){
	
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l< h->size && h->a[l] < h->a[i])
		smallest = l;
	if (r<h->size && h->a[r] < h->a[smallest])
		smallest = r;
	if (smallest != i){
		swap(&h->a[i],&h->a[smallest]);
		heapifyDown(h,smallest);
	}	
}
void decreaseKey(struct Minheap *h,int i,int new_val){
	h->a[i] = new_val;
	// restoring the heap property if violated
	heapifyUp(h,i);
}

int extractMin(struct Minheap* h){
	if (h->size <= 0)
		return INT_MAX;
	if (h->size == 1){
		h->size--;
		return h->a[0];
	}
	int root = h->a[0];
	h->a[0] = h->a[h->size-1];
	h->size--;
	heapifyDown(h,0);
	return root ; 
}
void Delete(struct Minheap *h,int i){
	decreaseKey(h,i,INT_MIN);
	extractMin(h);	
}
int valueAt(struct Minheap *h,int i){
	return (h->a[i]);
}

void levelOrder(struct Minheap *h){
    if (h == NULL)
        return ;
    int i ;
    for(i =0; i< h->size; i++){
        printf("%d ",h->a[i]);
    }
    printf("\n");
    
}


int main(){
	
    int n,x,i;
    printf("\nEnter the no of elements you want to enter in the Minimum heap = ");
    scanf("%d",&n);
    struct Minheap* root = Createheap(n);
    printf("\nEnter the node values of the Min heap = ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(root,x);
    }
    printf("\nThe level order traversal of the Minheap: \n");
    levelOrder(root);
    printf("Enter the index of the element you want to Delete ? : ");
    scanf("%d",&x);
    int d = valueAt(root,x);
    printf("\nThe value at %d = %d\n",x,d);
    Delete(root,x);
    printf("\nAfter Deletion : \n");
    levelOrder(root);    
    return 0;    
}



























