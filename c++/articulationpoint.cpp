#include <iostream>
#include <vector>
#define UNVISITED -10
using namespace std;

int dfsNumberCounter,dfsRoot,rootChildren;
vector<int>dfs_num,dfs_low,dfs_parent,articulation_vertex;
vector<vector<int> > AdjList;
void articulationPointAndBridge(int u){
	dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
	for(int j = 0; j<(int)AdjList[u].size();j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v]=u;
			if(u==dfsRoot)rootChildren++;

			articulationPointAndBridge(v);
			if(dfs_low[v]>=dfs_num[u])
				articulation_vertex[u]=true;
			if(dfs_low[v]>dfs_num[u])
				cout<<"Edge "<<u<<" "<<v<<" is a Bridge"<<endl;
			dfs_low[u]=min(dfs_low[u],dfs_low[v]);
		}
		else if(v!=dfs_parent[u])
			dfs_low[u]=min(dfs_low[u],dfs_num[v]);
	}
}
int main(){
	int V;
	dfsNumberCounter=0; dfs_num.assign(V,UNVISITED);dfs_low.assign(V,0);
	dfs_parent.assign(V,0);articulation_vertex.assign(V,0);
	cout<<"Bridges:"<<endl;
	for(int i=0;i < V;i++)
		if(dfs_num[i]==UNVISITED){
			dfsRoot = i;rootChildren=0;articulationPointAndBridge(i);
			articulation_vertex[dfsRoot]=(rootChildren>1);
		}
	cout<<"Articulation Points"<<endl;
	for(int i=0;i<V;i++)
		if(articulation_vertex[i]){
			cout<<"Vertex"<<i<<endl;
		}
	return 0;
}