#include <stdio.h>
/* Topological Sorting */
#include <stdlib.h>
#include "Q.c"
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

// Recursive DFS
void dfs(struct Graph* g,int s){
	g->visited[s] = 1;
	printf("%d ",s);
	struct Node* temp = g->adjlists[s];
	while(temp){
		int adjV = temp->vertex;
		if (g->visited[adjV] == 0){
			g->visited[adjV] = 1;
			dfs(g,adjV);
		}
		temp = temp->next;	
	}
}

void TopologicalSort(struct Graph* g){
	struct Stack* s = CreateS(SIZE);
	
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
	AddEdge(g,0,1);
	AddEdge(g,0,2);
	AddEdge(g,1,2);
	AddEdge(g,1,3);
	AddEdge(g,2,3);
	AddEdge(g,3,4);
	AddEdge(g,4,1);
	AddEdge(g,4,5);
	AddEdge(g,4,0);
	
	printf("\nThe Graph using Adjacency Lists : \n");
	printGraph(g);
	printf("\nBFS traversal of the Graph : \n");	
	for(i=0;i<g->V;i++){
		if (g->visited[i] == 0)
			BFS(g,i);
	}
	printf("\n");
	unvisit(g);
	printf("\nDFS traversal of the Graph : \n");
	for(i=0;i<g->V;i++){
		if (g->visited[i] == 0)
			DFS(g,i);
	}
	printf("\n");
	unvisit(g);	
	return 0;
}
