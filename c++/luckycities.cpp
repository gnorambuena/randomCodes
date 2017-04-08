#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int> > graph;
vector<int> parent;
vector<bool>visited;
set<vector<int> > myset;
void dfs(int node){
	for(int &v:graph[node]){
		if(!visited[v]){
			visited[v]=true;
			dfs(v);
		}
		else if(visited[v] && parent[v] != node){
			vector<int>cycle;
			cycle.push_back(v);
			cycle.push_back(node);
			cerr<<v<<endl;
			cerr<<node<<endl;
			parent[v]=node;
			int aux = parent[aux];
			cerr<<aux<<endl;
			cycle.push_back(aux);
			while(node!=parent[aux]){
				aux = parent[aux];
				cycle.push_back(aux);
				cerr<<aux<<endl;
			}
			myset.insert(cycle);
			return ;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		graph.assign(n,vector<int>());
		parent.assign(n,-1);
		visited.assign(n,false);
		for(int i = 0 ; i < m ; i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i = 0 ; i < graph.size() ; i++){
			if(!visited[i]){
				visited[i]=true;
				dfs(i);
			}
		}
	}
	return 0;
}