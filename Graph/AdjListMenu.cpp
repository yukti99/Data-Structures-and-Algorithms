/* Graph  Traversals - DFS and BFS */


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

struct Node* CreateNode(int v){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->vertex = v;
	n->next = NULL;
	return n;
}

struct Graph{
	
	int V ;
	struct Node** adjlists ;	
	int* visited;
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

// DFS using Stack
void DFS(struct Graph* g,int i){
	struct Stack* st = CreateS(SIZE);
	g->visited[i] = 1;
	push(st,i);
	while(!isEmptyS(st)){
		int v = pop(st);
		printf("%d ",v);
		struct Node* temp = g->adjlists[v];
		while(temp){
			int adjV = temp->vertex;
			if (g->visited[adjV] == 0){
				g->visited[adjV] = 1;
				push(st,adjV);
			}
			temp = temp->next; 
		}		
	}

}
void BFS(struct Graph* g,int s){
	
	struct Queue* q = CreateQ(SIZE);
	g->visited[s] = 1;
	Enqueue(q,s);
	while(!isEmpty(q)){
		
		// current node
		int v = Dequeue(q);
		printf("%d ",v);
		
		// finding its adjacent nodes
		struct Node* temp = g->adjlists[v];
		while(temp){
			int adjV = temp->vertex;
			
			if (g->visited[adjV] == 0){
				g->visited[adjV] = 1;
				Enqueue(q,adjV);
			}
			temp = temp->next;
		}
		
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
	
	int V = 0,x,y,choice,s,i;
	printf("Enter the number of Vertices you want in the graph = ");
	scanf("%d",&V);
	struct Graph* g = CreateGraph(V);
	while (1){
    printf("\n\n******************** GRAPH - ADJACENCY LIST IMPLEMENTATION IN C  *****************\n\n");
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
        	AddEdge(g,x,y);
        	printf("\n");
			printGraph(g);       	
        	break;
        case 2:
        	printf("\n");
			printGraph(g); 
        	break;
        case 3:
        	printf("\nThe BFS Traversal of the Graph : \n");
        	for(i=0;i<g->V;i++){
				if (g->visited[i] == 0)
					BFS(g,i);
			}
			unvisit(g);
        	break;
        case 4:
        	printf("\nThe DFS Traversal of the Graph : \n");
			for(i=0;i<g->V;i++){
				if (g->visited[i] == 0)
					DFS(g,i);
			}
        	unvisit(g);
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
