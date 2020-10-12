// To check if a given graph is tree or not
#include <stdio.h>
#include <stdlib.h>

// Graph Implementation using Adjacency Lists
struct Node{
	int vertex;
	struct Node* next;
};

struct Graph{
	int V ;
	int *visited;
	struct Node **a;	
};

struct Node* newNode(int v){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->next = NULL;
	n->vertex = v;
	return n;
}
struct Graph* CreateGraph(int v){
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->a = (struct Node**)malloc(v*sizeof(struct Node*));
	g->V = v ;
	g->visited = (int*)malloc(v*sizeof(int));
	int i=0;
	for(i=0;i<v ;i++){
		g->a[i] = NULL;
		g->visited[i] = 0; 		
	}	
	return g;
	
}
void addEdge(struct Graph* g,int src,int dest){
	struct Node* n1 = newNode(dest);
	n1->next = g->a[src];
	g->a[src] = n1;
	
	struct Node* n2 = newNode(src);
	n2->next = g->a[dest];
	g->a[dest] = n2;	
}
void printGraph(struct Graph* g){
	printf("\nGRAPH : \n");
	int i;
	for(i=0;i<g->V ;i++){
		struct Node* n = g->a[i];
		printf("\nAdjacency List of vertex %d -> ",i);
		while(n){
			printf("%d -> ",n->vertex);
			n = n->next;
		}
		printf("NULL\n"); 	
	}
}
// To check if there is any cycle in the graph
int isCyclic(struct Graph *g,int v,int parent){
	g->visited[v] = 1;
	struct Node* temp = g->a[v];
	while(temp){
		int adj = temp->vertex;
		if (!g->visited[adj]){
			g->visited[adj] = 1;
			if (isCyclic(g,adj,v))
				return 1;
		}
		else if (adj!=parent){
			return 1;
		}
		
		temp = temp->next;
	}
	return 0;
}
// The graph is a tree if its not cyclic and connected ( i.e all vertices reachable )
int isTree(struct Graph* g){
	if (isCyclic(g,0,-1))
		return 0;
	int i=0;
	for(i=0;i<g->V ;i++){
		if (!g->visited[i])
			return 0;		
	}
	return 1;
}

int main(){
	int V = 5;
	// Sample Graph
	struct Graph* g = CreateGraph(V);
	addEdge(g,1,0);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,3,4);
	printGraph(g);
	if (isTree(g))
		printf("\nThe Graph is a Tree!!\n");
	else
		printf("\nThe Graph is NOT a Tree!!\n");	
	return 0;
}
