/*BFS traversal in a graph*/

#include <bits/stdc++.h>
using namespace std;

vector <bool> v;
vector <vector<int>> g;

void addEdge(int src,int dest){
	g[src].push_back(dest);
	g[dest].push_back(src);
}


void bfs(int s){
	queue<int>q
	q.push(s)
	v[s] = true; //visited node
	while(!q.isEmpty()){
		int f = q.front();
		q.pop();
		cout<<f<<" ";
		// Enqueue all adjacent of f and mark them visited 
		for(auto i = g[f].begin(); i != g[f].end();i++){
			if (!v[*i]){
				q.push(*i);
				v[*i] = true;				
			}			
		}		
	}
	
}


