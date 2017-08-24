#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

vector<int>dist;
vector<vector<int>>graph;
vector<bool>isStore;
vector<pair<int,int>>storeDist;

void bfs(int node){
	storeDist.clear();
	dist[node] = 0;
	if(isStore[node]){
		storeDist.push_back({0,node});
	}
	queue<int> q ;
	q.push(node);
	while(!q.empty()){
		int n = q.front();q.pop();
		for(int i = 0 ; i < graph[n].size() ; i++){
			if(dist[graph[n][i]]==INT_MAX){
				dist[graph[n][i]] = dist[n] + 1;
				q.push(graph[n][i]);
				//cout<<"bfs\n";
				//cout<<graph[n][i]<<"\n";
				if(isStore[graph[n][i]]){
					//cout<<"store!\n";
					//cout<<"distance "<<dist[graph[n][i]]<<"\n";
					storeDist.push_back({dist[graph[n][i]],graph[n][i]});
				}
			}
		}
	}
	sort(storeDist.begin(),storeDist.end());
}

int main(){
	int n,m;
	cin>>n>>m;
	n++;
	graph.assign(n,vector<int>());
	dist.assign(n,INT_MAX);
	isStore.assign(n,false);
	for(int i = 0 ; i < m ; i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int w;
	cin>>w;
	vector<vector<pii>>stores(n);
	for(int i = 0; i < w ; i++){
		int a,b,c;
		cin>>a>>b>>c;
		stores[a].push_back({c,b});
		isStore[a] = true;
	}
	int q;
	cin>>q;
	while(q--){
		int g,r,a;
		cin>>g>>r>>a;
		dist.assign(n,INT_MAX);
		bfs(g);
		//cout<<"hola\n";
		int izq = 0, der = storeDist.back().first;
		//cout<<"der "<<der<<" \n";
		int m = (izq+der)/2;
		bool flag = false;
		bool res = false;
		int ans = -1 ;
		for(int i = 0 ; i < 64 ; i++){
			flag = false;
			//cout<<"for "<<i<<" \n";
			//cout<<m<<"\n";
			vector<pair<int,int>>reachable;
			for(int j = 0 ; j < storeDist.size(); j++){
				int store = storeDist[j].second;
				int dist = storeDist[j].first;
				if(dist<=m){
					//cout<<"store = "<<store<<"\n";
					for(auto t: stores[store]){
						reachable.push_back(t);
					}
				}
				else
					break;
			}
			sort(reachable.begin(),reachable.end());
			long long tot = r;
			long long cost = 0;
			for(int j = 0; j < reachable.size() ; j++){
				cost += (long long)reachable[j].first*(long long)min((int)tot,reachable[j].second);
				tot -= reachable[j].second;
				//cout<<"m = "<<m<<" "<<tot<<"\n";
				//cout<<"cost "<<cost<<"\n";
				if(cost > a) break;
				if(tot <= 0){
					//cout<<"asdasd\n";
					flag = true;
					res = true;
					break;
				}
			}
			//cout<<"after for\n";
			if(!flag){
				izq = m + 1;
			} else {
				der = m;
			}
			m = (izq+der)/2;
		}

		cout<<(res?m:-1)<<"\n";
	}
	return 0;
}