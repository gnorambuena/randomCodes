#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
#define UNVISITED -1
typedef vector<int> vi;

vi dfs_num,dfs_low,S,visited;
int dfsNumberCounter;
vector<vi>graph;
vector<set<int>>vSCC;

void tarjan(int u){
	//cout<<u<<"\n";
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0 ; j < (int) graph[u].size() ; j++){
		int v = graph[u][j];
		if(dfs_num[v] == UNVISITED)
			tarjan(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	set<int>SCC;
	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			SCC.insert(v);
			if(u==v)break;
		}
		vSCC.push_back(SCC);
	}
}

int main(){
	int n;
	cin>>n;
	dfs_num.assign(n+1,UNVISITED);
	dfs_low.assign(n+1,0);
	visited.assign(n+1,UNVISITED);
	graph.assign(n+1,vector<int>());
	dfsNumberCounter = 0;
	vector<long long> cost(n+1);
	for(int i = 1 ; i <= n ; i++){
		cin>>cost[i];
	}
	int m;
	cin>>m;
	for(int i = 0; i < m ; i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	long long ways = 1;
	long long num = 0;
	for(int i = 1 ; i <= n ; i++){
		//cout<<i<<"\n";
		if(dfs_num[i] == UNVISITED){
			//cout<<i<<"\n";
			tarjan(i);
		}
	}
	for(auto SCC: vSCC){
		long long w = 0;
		long long mincost = 1e12L;
		for(auto el: SCC){
			mincost = min(mincost,cost[el]);
		}
		num+=mincost;
		//num%=1000000007;
		for(auto el: SCC){
			if(cost[el] == mincost)
				w++;
		}
		ways*=w;
		ways%=1000000007;
	}
	cout<<num<<" "<<ways<<"\n";
	return 0;
}