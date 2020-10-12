#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 9

int minDistance(int dist[],int SPV[]){
	int m = INT_MAX, min_index,i;
	for(i=0;i<V;i++){
		if (dist[i] <= m && SPV[i] == 0){
			m = dist[i];
			min_index = i;
		}
	}
	return min_index;	
}
void ShortestPath(int pi[],int x){
	if (pi[x] == -1)
		return ;
	ShortestPath(pi,pi[x]);
	printf("%d ",x);

}
void display(int dist[],int pi[],int src){
	int i; 
    printf("Vertex\t\tDistance\t\tPath\n"); 
    for (i = 0; i < V ; i++){
		if (i == src)
			continue; 
        printf("\n%d -> %d\t\t%d\t\t%d ",src,i,dist[i],src); 
        ShortestPath(pi, i); 
    } 
}
void dijkstra(int graph[V][V],int src){
	int dist[V],SPV[V], pi[V],i,u,v;
	pi[src] = -1;
	for(i=0;i<V;i++){
		dist[i] = INT_MAX;
		SPV[i] = 0;		
	}	
	dist[src] = 0;
	for(u=0 ;u<V ;u++){
		int u = minDistance(dist,SPV);
		SPV[u] = 1;
		for(v=0;v<V;v++){
			if (!SPV[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v]){
				
				pi[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
			}
		}		
	}
	display(dist,pi,src);
	
}


int main(){
	// undirected Graph
	int graph[V][V] =   {   {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                        {4, 0, 8, 0, 0, 0, 0, 11,0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 0, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 14, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0,7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                    };   
    dijkstra(graph,3); 	
	return 0;
}
