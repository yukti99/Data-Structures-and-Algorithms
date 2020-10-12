#include<stdio.h>
#include <stdlib.h>
#include "Q.c" 
#define SIZE 40

// Globle Variables
int G[SIZE][SIZE];
int visited[SIZE];
 

// for DFS traversal
void DFS(int s,int v){
    int i;
    printf("%d ",s);
    visited[s] = 1;    
    for(i = 0;i < v; i++){
    	if ( !visited[i] && G[s][i] == 1)
            DFS(i,v);
	}       
}

// for BFS traversal
void BFS(int s,int v){
	struct Queue* q = CreateQ(SIZE);
	Enqueue(q,s);
	visited[s] = 1;
	int i=0;
	while(!isEmpty(q)){
		int t = Dequeue(q);
		printf("%d ",t);
		for(i=0;i<v;i++){
			if ( !visited[i] && G[t][i] == 1 ){
				visited[i] = 1;
				Enqueue(q,i);
			}			
		}
	}	
}
void insert(int src,int dest,int w){
	G[src][dest] = w; 
}

void printGraph(int v){
	int i,j;
	printf("\n");
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++)
			printf("%d ",G[i][j]);		
		printf("\n");
	}
	printf("\n");
}

void create(int v){
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			G[i][j] = 0;
	printf("Adjacency Matrix Created!!\n");
	printGraph(v); 	
}

int main()
{
    int i=0,j=0,v=0,choice,s=0,x,y,w;
    printf("Enter number of vertices = ");   
    scanf("%d",&v);
    create(v);
    //visited is initialized to zero
    for(i=0;i<v;i++)
        visited[i] = 0;
    while (1){
	    printf("\n\n******************** GRAPH - ADJACENCY MATRIX IMPLEMENTATION IN C  *****************\n\n");
	    printf("\t\t\t1. Add Edge \n");
	    printf("\t\t\t2. Print Graph \n");
	    printf("\t\t\t3. BFS Traversal \n");
	    printf("\t\t\t4. DFS Traversal \n");
	    printf("\t\t\t5. Quit \n");        
	    printf("\t\t\tEnter your choice : ");
	    scanf("%d", &choice);
	    printf("\n");
	    switch (choice)
	    {
		case 1:
			printf("Enter the source = ");
			scanf("%d",&x);
			printf("Enter the destination = ");
			scanf("%d",&y);
			printf("Enter the weight = ");
			scanf("%d",&w);
			insert(x,y,w); 	
			break;
		case 2:			
			printGraph(v); 
			break;
		case 3:
			printf("Enter the starting node for traversal : ");
			scanf("%d",&s);
			printf("The BFS : \n");
			BFS(s,v);
			for(i=0;i<v;i++)
				visited[i] = 0;
			break;
		case 4:
			printf("Enter the starting node for traversal : ");
			scanf("%d",&s);
			printf("The DFS : \n");
			DFS(s,v);
			for(i=0;i<v;i++)
				visited[i] = 0;
			break;
		case 5:
			printf("Thank you!\n");
			exit(0);
		default:
			printf("\a\nWrong choice! \n\n");
	    	} 
	    } 	
		return 0;	 
}
