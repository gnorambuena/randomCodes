#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> >normalgraph;
vector<int> dist;
vector<bool>visited;
void dfs(int node){
	for(int v : normalgraph[node]){
		if(!visited[v]){
			visited[v]=true;
			dist[v]=dist[node]+1;
			dfs(v);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >graph(n);
	normalgraph.assign(n,vector<int>());
	vector<bool>approved(n,false);
	visited.assign(n,false);
	dist.assign(n,0);
	for(int i = 0 ; i < m ; i++){
		int a,b;
		cin>>a>>b;
		graph[--b].push_back(--a);
		normalgraph[a].push_back(b);
	}
	for(int i = 0 ; i < n ; i++){
		if(graph[i].size()==0){
			cerr<<i<<endl;
			dist[i]=1;
			visited[i]=true;
			dfs(i);
		}
	}
	for(int i : dist)cerr<<i<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(graph[i].size()==0){
			cerr<<i;
			graph[i].push_back(i);
		}
	}
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		int a;
		cin>>a;
		a--;
		approved[a]=true;
		bool flag = true;
		int aux = 0;
		for(int node : graph[a]){
			//cerr<<"node "<<node<<endl;
			if(!approved[node]){flag = false;}
		}
		if(flag)count+=dist[a];
		cout<<count<<"\n";
	}
}