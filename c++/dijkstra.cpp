#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii >, greater<pii > > pq;
vector<int>dist,parent;
vector<vector<pii > > edges;
vector<bool>visited;
void Dijkstra(int s){
	for(int i=0;i<edges.size();i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
		visited[i]=false;
	}
	dist[s]=0;
	pq.push(make_pair(dist[s],s));
	while(!pq.empty()){

		int u=pq.top().second;
		pq.pop();
		visited[u]=true;

		for(int i=0;i<edges[u].size();i++){

			int v=edges[u][i].first;//nodo
			if(!visited[v] && dist[v]>dist[u]+edges[u][i].second){
				dist[v]=dist[u]+edges[u][i].second;
				parent[v]=u;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
}
int main(){
	vector<int>path;
	set<pii > insertedEdges;
	int n,m;
	cin>>n>>m;
	dist.resize(n+1);
	parent.resize(n+1);
	edges.resize(n+1);
	visited.resize(n+1);

	for(int i=0;i<m;i++){
		pii par;
		int node;
		cin>>node>>par.first>>par.second;
		//chequear si hay varios edges para los mismos nodosº
		if(insertedEdges.find(make_pair(node,par.first))==insertedEdges.end() || insertedEdges.find(make_pair(par.first,node))==insertedEdges.end()){
		edges[node].push_back(par);
		edges[par.first].push_back(make_pair(node,par.second));
		insertedEdges.insert(make_pair(node,par.first));insertedEdges.insert(make_pair(par.first,node));
		}
		else{
			int i=0;
			while(edges[node][i].first!=par.first){
				i++;
			}
			int j=0;
                        while(edges[par.first][j].first!=node){
                                j++;
                        }
			//cout<<i<<" "<<j<<endl;
			if(edges[node][i].second>par.second){
				edges[node][i].second=par.second;
				edges[par.first][j].second=par.second;
				//cout<<par.second<<endl;
			}
		}
	}
	Dijkstra(1);
	int cur=n;
	if(visited[n]){
		while(cur!=1){
			path.push_back(cur);
			cur=parent[cur];
		}
		path.push_back(1);
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]<<" ";
		}
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}
