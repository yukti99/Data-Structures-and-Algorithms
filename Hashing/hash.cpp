/* 
 Hash Table in C
 - Collisions resolved using chaining (Linked list)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


struct Node{
	int key;
	struct Node* next;
};

struct Hash{
	
	struct Node* head;
	int count;
};

struct Hash *hash_table = NULL ;

int hashFunc(int key){
	return (key % SIZE);
}

struct Node* CreateNode(int key){
	struct Node* h = (struct Node*)malloc(sizeof(struct Node));
	h->key = key;
	h->next = NULL;
	return h;
}

void insert(int key){
	struct Node* temp = CreateNode(key);
	int h = hashFunc(key);
	
	// entry of first element at that index
	if (hash_table[h].head == NULL ){
		hash_table[h].head = temp;
		hash_table[h].count = 1;
		return ;		
	}
	temp->next = hash_table[h].head;
	hash_table[h].head = temp;
	/*
	struct Node* p = hash_table[h].head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = temp;*/
	hash_table[h].count++;

	
}


void display(){
	
	printf("\nTHE HASH TABLE OF SIZE %d :\n\n",SIZE);
	struct Node *p = NULL;
	int i=0;
	for(i=0;i<SIZE;i++){
		
		if (hash_table[i].count == 0)
			continue;
			
		p = hash_table[i].head;
		while(p!= NULL){
			printf("%d ",p->key);
			p = p->next;
		}
		printf("\n");		
	}
	printf("\n");
	
	
}

int main(){
	printf("\n\tHASH TABLE\n");
	int i=0,x,choice;
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	while(1){
		printf("\n\tWhat do you want to do?\n\n");
		printf("\t1. Insertion\n");
		printf("\t2. Display\n");
		printf("\t3. Quit\n");
		printf("\tEnter your choice : ");
	    scanf("%d", &choice);
		switch(choice){
			case 1:							
				printf("Enter the Element to be inserted in Hash Table = ");
				scanf("%d",&x);			
				insert(x);
				break;
			case 2: 
				display();
				break; 				
			case 3:
				printf("\nThank you!!\n");
				exit(0);
			default:
				printf("\nWrong choice!\n"); 		
		}
	
	}
	/*
	insert(hash_table,0);
	insert(hash_table,1);
	insert(hash_table,2);
	insert(hash_table,3);
	insert(hash_table,4);
	insert(hash_table,5);
	insert(hash_table,7);	
	insert(hash_table,6);
	insert(hash_table,15);
	insert(hash_table,11);
	insert(hash_table,27);
	display(hash_table);*/	
	return 0;
}
