/* Topological Sorting */

#include <stdio.h>
#include <stdlib.h>
#include "St.c"
#define SIZE 40

// List Node
struct Node{
	
	int vertex;
	struct Node* next;
};

// Creating a Node
struct Node* CreateNode(int v){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->vertex = v;
	n->next = NULL;
	return n;
}
struct Graph{
	
	int V;
	struct Node** adjlists;
	int *visited ;
	
};
struct Graph* CreateGraph(int vertices){
	struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
	G->V = vertices;
	G->adjlists = (struct Node**)malloc(vertices*sizeof(struct Node*));
	G->visited = (int*)malloc(sizeof(int)*vertices);
	int i;
	for(i=0;i<vertices;i++){
		G->adjlists[i] = NULL;	
		G->visited[i] =  0;
	}
			
	return G;	
}
// directed Graph
void AddEdge(struct Graph* g,int src,int dest){
	
	struct Node* n = CreateNode(dest);
	n->next = g->adjlists[src];
	g->adjlists[src] = n;	
}
void unvisit(struct Graph* g){
	int i;
	for(i=0;i<g->V;i++)
		g->visited[i] = 0;
}




// same as recursice DFS
void TS(struct Graph* g,int v, struct Stack *s){
	
	g->visited[v] = 1;
	struct Node* temp = g->adjlists[v];
	while(temp){
		int adjV = temp->vertex;
		if (!g->visited[adjV]){
			g->visited[adjV] = 1;
			TS(g,adjV,s);
		}
		temp = temp->next;
	}
	push(s,v);
}

void TopologicalSort(struct Graph* g){
	unvisit(g);
	struct Stack* st = CreateS(SIZE);
	int i;
	for(i=0;i<g->V;i++){
		if (g->visited[i] == 0)
			TS(g,i,st);
	}
	while(!isEmptyS(st)){
		printf("%d ",pop(st));
	}
	
}



void printGraph(struct Graph* g){
	int i;
	for(i=0; i<g->V; i++){		
		struct Node* n = g->adjlists[i];
		printf("\nThe Adjacency List of vertex = %d\n",i);
		while(n){
			printf("%d -> ",n->vertex);
			n = n->next;
		}
		printf("\n");		
	}	
}
int main(){	
	int V = 6,i;
	struct Graph* g = CreateGraph(V);	
	AddEdge(g,5,2); 
    AddEdge(g,5,0); 
    AddEdge(g,4,0); 
    AddEdge(g,4,1); 
    AddEdge(g,2,3); 
    AddEdge(g,3,1); 
	
	printf("\nThe Graph using Adjacency Lists : \n");
	printGraph(g);
	printf("\nThe Topological Sort of the Graph : \n");
	TopologicalSort(g);
	return 0;
}
