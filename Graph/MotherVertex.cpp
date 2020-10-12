#include <stdio.h>
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

// Recursive DFS

int dfs(struct Graph* g,int s){
	g->visited[s] = 1;
	//printf("%d ",s);
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
int findMother(struct Graph* g){
	int i,v;
	for(i=0;i<g->V;i++){
		if (g->visited[i]==0){
			dfs(g,i);
			v = i;
		}	
	}
	for(i=0;i<g->V;i++)
		g->visited[i] = 0;
	dfs(g,v);
	for(i=0;i<g->V;i++){
		if (g->visited[i] == 0)
			return -1;
	}
	return v;
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
	int V = 7;
	struct Graph* g = CreateGraph(V);
	AddEdge(g,0,1);
	AddEdge(g,0,2);
	AddEdge(g,1,3);
	AddEdge(g,4,1);
	AddEdge(g,6,4);
	AddEdge(g,5,6);
	AddEdge(g,5,2);
	AddEdge(g,6,0);
	
	printf("\nThe Graph using Adjacency Lists : \n");
	printGraph(g);
	int mv = findMother(g);
	printf("\nThe Mother Vertex in the given graph = %d\n",mv);
	
	return 0;
}
