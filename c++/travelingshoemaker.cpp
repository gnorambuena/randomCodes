#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

void bfs(int node){
	queue<int> Q; Q.push(node);
	visited[node] = true;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		visited[u] = true;
		for(int i = 0; i < graph[u].size(); ++i){
			if(!visited[graph[u][i]]){
				Q.push(graph[u][i]);
			}
		}
	}
}

bool all_visited(){
	for(int i = 0; i < visited.size(); ++i)
		if(visited[i] == false)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n, c; cin >> n >> c;
	graph.assign(n, vector<int> ());

	for(int r = 0; r < c; ++ r){
		int k; cin >> k;
		vector<int> memo(k);
		for(int i = 0; i < k; ++i)
			cin >> memo[i];

		for(auto &u : memo)
			for(auto &v : memo)
				if(u != v){
					graph[u].push_back(v);
					graph[v].push_back(u);
				}
	}
	int ans = -1;
	for(int i = 0; i < n; ++i){
		visited.assign(n, false);
		bfs(i);
		if(all_visited()){
			ans = i;
			break;
		}
	}

	cout << ans << '\n';
}