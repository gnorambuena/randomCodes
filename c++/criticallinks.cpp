#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
typedef pair<int,int> ii;

int dfsNumberCounter,dfsRoot,rootChildren;
vector<int>dfs_num,dfs_low,dfs_parent,articulation_vertex;
vector<vector<int>>graph;
vector<ii>edges;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int j = 0; j < (int)graph[u].size(); j++){
		int v = graph[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			if(u==dfsRoot) rootChildren++;

			articulationPointAndBridge(v);

			if(dfs_low[v] > dfs_num[u])
				edges.push_back({min(u,v),max(u,v)});
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}
}

int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		//if(n==0)break;
		graph.assign(n,vector<int>());
		dfsNumberCounter = 0; dfs_num.assign(graph.size(), UNVISITED);
		dfs_low.assign(graph.size(),0);
		dfs_parent.assign(graph.size(),0);
		edges.clear();
		for(int i = 0; i < n ;i++){
			int a,b;
			char c;
			cin>>a>>c>>b>>c;
			for(int j = 0; j < b ; j++){
				int d;
				cin>>d;
				graph[a].push_back(d);
				//graph[d].push_back(a);
				//cout<<a<<" "<<d<<"\n";
			}
		}
		for(int i = 0; i < graph.size(); i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
			}
		}
		sort(edges.begin(),edges.end());
		cout<<edges.size()<<" critical links\n";
		for(auto el: edges){
			cout<<el.first<<" - "<<el.second<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}