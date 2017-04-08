#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

vector<vector<int> > edge,edget;
vector<int> dist1,dist2,dist3;
void dijkstra(int start,vector<vector<int> >&g,vector<int> &dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});
    dist[start] = 0;
    while (!q.empty()) {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        for (int i = 0 ; i < g.size() ; i++) {
        	if(g[u][i]!=INT_MAX){
	            int v = i, w = g[u][i];
	            if (dist[u] + w < dist[v]) {
	                dist[v] = dist[u] + w;
	                q.push({dist[v], v});
	            }
	        }
        }
    }
}

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m && n!=0 && m!=0){
		edge.assign(n,vector<int>(n,INT_MAX));
		edget.assign(n,vector<int>(n,INT_MAX));
		dist1.assign(n,INT_MAX);
		dist2.assign(n,INT_MAX);
		dist3.assign(n,INT_MAX);
		int s,d;
		cin>>s>>d;
		for(int i = 0 ; i < m ; i++){
			int u,v,p;
			cin>>u>>v>>p;
			edge[u][v]=p;
			edget[v][u]=p;
		}
		dijkstra(s,edge,dist1);
		dijkstra(d,edget,dist2);
		int dsd = dist1[d];
		for(int u = 0 ; u < edge.size() ; u++){
			for(int v = 0 ; v < edge.size() ; v++){
				if(dist1[u]+edge[u][v]+dist2[v] == dsd){
					edge[u][v]=INT_MAX;
					//cout<<u<<" "<<v<<endl;
				}
			}
		}
		dijkstra(s,edge,dist3);
		if(dist3[d]==INT_MAX)cout<<"-1\n";
		else
			cout<<dist3[d]<<"\n";
	}
}