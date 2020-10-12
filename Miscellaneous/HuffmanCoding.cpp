// Huffman Coding in C using Min Heap
// Encoding and decoding data using Huffman's Algorithm

#include <stdio.h>
#include <stdlib.h>


// Huffman tree node
struct MinHeapNode{
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;
};

/* Minheap implementation where each element of the minheap is a huffman Node */
struct MinHeap{
	unsigned size;
	unsigned capacity;
	struct MinHeapNode **a;
};

// to create a new node
struct MinHeapNode* CreateNode(char data,unsigned freq){
	struct MinHeapNode* n = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	n->data = data;
	n->freq = freq;
	n->left = n->right = NULL;
	return n;	
}
// to create a new minheap of given capacity
struct MinHeap* CreateHeap(unsigned cap){
	struct MinHeap* h = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	h->capacity = cap;
	h->size = 0;
	h->a = (struct MinHeapNode**)malloc(cap*sizeof(struct MinHeapNode*));
	return h;
}
void swap(struct MinHeapNode **a, struct MinHeapNode **b){
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// Minheapify down funtion
void heapifyDown(struct MinHeap* h,int i){
	int smallest = i;
	int left =  2*i + 1;
	int right = 2*i + 2;
	if (left < h->size && h->a[left]->freq < h->a[smallest]->freq)
		smallest = left;
	if (right < h->size && h->a[right]->freq <h->a[smallest]->freq)
		smallest = right;
	if (smallest != i){
		swap(&h->a[smallest],&h->a[i]);
		heapifyDown(h,smallest);
	}
}
int isSizeOne(struct MinHeap* h){
	return (h->size == 1);
}
struct MinHeapNode* extractMin(struct MinHeap* h){
	struct MinHeapNode* n = h->a[0];
	h->a[0] = h->a[h->size-1];
	h->size--;
	heapifyDown(h,0);
	return n;
}
int Parent(int i){
	return ((i-1)/2) ;
}
void insertMinheap(struct MinHeap* h,struct MinHeapNode* node){
	if (h->size == h->capacity){
        printf("\nOverflow Condition!!\n");
        return ;
    }
	h->size++;
	int i = h->size-1;
	//h->a[i] = node;
	
	// heapify Up
	while(i!=0 && node->freq < h->a[Parent(i)]->freq){
		//swap(&h->a[Parent(i)],&h->a[i]);
		h->a[i] = h->a[Parent(i)];
		i = Parent(i);		
	}
	h->a[i] = node;
}
// Building Minheap
void buildMinheap(struct MinHeap *h){
	int n = h->size-1,i;
	for(i = n/2 -1 ; i>=0 ;i--){
		heapifyDown(h,i);
	}	
}

int isLeaf(struct MinHeapNode* root){
	return ( !(root->left) && !(root->right) );	
}

void print(int a[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
// Creating an initial minimum heap of given capacity, containing data and frequency nodes 
struct MinHeap* BuildHeap(char data[],int freq[],int capacity){
	struct MinHeap* h = CreateHeap(capacity);
	int i=0;
	for(i=0;i<capacity;i++){
		h->a[i] = CreateNode(data[i],freq[i]);		
	}
	h->size = capacity;
	buildMinheap(h);
	return h;	
}

struct MinHeapNode* BuildHuffmanTree(char data[],int freq[],int cap){
	
	struct MinHeap* h = BuildHeap(data,freq,cap);
	struct MinHeapNode *left,*right,*internalNode;
	while(!isSizeOne(h)){
		left = extractMin(h);
		right = extractMin(h);
		internalNode = CreateNode('$',left->freq + right->freq);
		internalNode->left = left;
		internalNode->right = right;		
		insertMinheap(h,internalNode); 		
	}	
	return extractMin(h);	
}
// to print Huffman codes
void printCodes(struct MinHeapNode* root,int a[],int top ){
	
	if (root->left){
		a[top] = 0;
		printCodes(root->left,a,top+1);
	}
	if (root->right){
		a[top] = 1;
		printCodes(root->right,a,top+1);
	}
	if (isLeaf(root)){
		printf("%c : ",root->data);
		print(a,top);
	}	
}
void HuffmanCodes(char data[],int freq[],int size){
	struct MinHeapNode* root = BuildHuffmanTree(data,freq,size);
 	int a[100], top = 0; 
 	printCodes(root,a,top);
	
}
int main(){	
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 };   
    int size = sizeof(arr) / sizeof(arr[0]); 
    HuffmanCodes(arr,freq,size);
	return 0;
}
