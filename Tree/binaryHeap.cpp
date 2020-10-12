/*  MINIMUM BINARY HEAP */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;	
}


struct MinHeap{
	int *harr;
	int capacity;
	int heap_size;	
};

struct MinHeap* Create(int cap){
	
	struct MinHeap* h = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	h->heap_size = 0;
	h->capacity = cap;
	h->harr = (struct int*)malloc(sizeof(int)*cap);
	return mh;	
}
void insert(int k){
	if (mh->heap_size == mh->capacity){
		printf("\nOverflow!\n");
		return ;
	}
	mh->heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while(i != 0 && harr[] )
}

int main(){	
	return 0;
}
