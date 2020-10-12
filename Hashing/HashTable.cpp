/* 
 Hash Table in C
 - Collisions resolved using chaining (Linked list)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


struct Hash{
	
	int data;
	struct Hash* next;
};

int hashFunc(int key){
	return (key % SIZE);
}
void insert(struct Hash *hash_table[],int item){

	int h = hashFunc(item);
	
	struct Hash *temp = (struct Hash*)malloc(sizeof(struct Hash));
	temp->data = item; 									
	temp->next = hash_table[h];
	hash_table[h] = temp;
}

void display(struct Hash *hash_table[]){
	
	printf("\nTHE HASH TABLE OF SIZE %d :\n\n",SIZE);
	struct Hash *p = NULL;
	int i=0;
	for(i=0;i<SIZE;i++){
		
		if (hash_table[i] != NULL){			
			p = hash_table[i];
			printf("%d",p->data);
			while(p->next != NULL){				
				p = p->next;
				printf("->%d",p->data);
			}			
		} 
		printf("\n");		
	}
	printf("\n");
	
	
}

int main(){
	printf("\n\tHASH TABLE\n");
	struct Hash *hash_table[SIZE];
	int i=0,x,choice;
	for(i=0;i<SIZE;i++){
		hash_table[i] = NULL;
	}	
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
				insert(hash_table,x);
				break;
			case 2: 
				display(hash_table);
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
