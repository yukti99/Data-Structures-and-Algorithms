/* Representation of an undirected graph using Adjacency Lists*/

#include <stdio.h>
#include <stdlib.h>
#include "Q.c"


// adjacency node
struct Node{
	
	int dest;   // destination
	struct Node *next;
};

// adjacency list
struct list{
	struct Node *head;
};

// A graph is an array of adjacency lists
struct Graph{	
	int V;
	struct list *array; 
};

// creating a new node
struct Node* newNode(int dest){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->dest = dest;
	n->next = NULL;
	return n;
}

// creating a new graph
struct Graph* createGraph(int V){
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = V;
	g->array = (struct list*)malloc(V*sizeof(struct list*));
	int i;
	for(i=0;i<V;i++){
		g->array[i].head = NULL;
	}
	return g;
}

// adding an edge to the undirected graph
void addEdge(struct Graph* g,int source,int dest){
	
	//from source to destination
	struct Node* n1 = newNode(dest);
	n1->next = g->array[source].head;
	g->array[source].head = n1;
	
	// from destination to source
	struct Node* n2 = newNode(source);
	n2->next = g->array[dest].head;
	g->array[dest].head = n2;
	
}

// Breadth-First Traversal
void BFS(struct Graph* g,int s){
	int visited[g->V];
	int j;
	for(j=0;j<g->V;j++)
		visited[j] = 0;

	struct Queue* q = CreateQ(g->V);
	push(q,g->array[s].head);
	visited[s] = 1;

	while(!isEmpty(q)){
		struct Node* s = pop(q);
		printf("%d ",);
		for(i = g->array[s].head)
	}
	
	
	
}

// to print graph
void printGraph(struct Graph* g){
	int i;
	for(i=0;i<g->V;i++){
		struct Node* n = g->array[i].head;
		printf("\nAdjacency List of vertex %d\n head",i);
		while(n){
			printf("-> %d",n->dest);
			n = n->next;		
		}
		printf("\n");		
	}
}


int main(){
	
	int V = 5;
	struct Graph *graph = createGraph(V);
	addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4);   
    // print the adjacency list representation of the above graph 
	printGraph(graph);	
	return 0;
}
