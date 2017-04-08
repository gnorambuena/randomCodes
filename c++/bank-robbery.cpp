#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> dist;
vector<vector<pii> > graph;
priority_queue<pii, vector<pii>, greater<pii> > Q;

void dijkstra(){
	while(!Q.empty()){
		pii u = Q.top(); Q.pop();
		int node = u.second;
		if(dist[node] != u.first)
			continue;

		for(int i = 0; i < graph[node].size(); ++i){
			pii v = graph[node][i];
			int vec = v.first, weight = v.second;
			if(dist[node] + weight < dist[vec]){
				dist[vec] = dist[node] + weight;
				Q.push(pii(dist[vec],vec));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n, m, b, p;
	while(cin >> n){
		cin >> m >> b >> p;
		
		vector<int> Bank(b);
		graph.assign(n,vector<pii>());

		while(m--){
			int u, v, d; cin >> u >> v >> d;
			graph[u].push_back(pii(v,d));
			graph[v].push_back(pii(u,d));
		}

		dist.assign(n + 1, INT_MAX);

		for(int i = 0; i < b; ++i)
			cin >> Bank[i];

		for(int i = 0; i < p; ++i){
			int police; cin >> police;
			Q.push(pii(0,police));
			dist[police] = 0;
		}
		dijkstra();
		
		int max_dist = INT_MIN, count = 0;
		for(int i = 0; i < b; ++i){
			int u = Bank[i];
			if(dist[u] == max_dist)
				count++;
			if(dist[u] > max_dist){
				max_dist = dist[u];
				count = 1;
			}
		}

		cout << count << ' ';
		vector<int>sol;
		if(max_dist == INT_MAX)
			cout << '*' <<'\n';
		else
			cout << max_dist << '\n';

		for(int i = 0; i < b; ++i){
			int u = Bank[i];
			if(dist[u] == max_dist){
				sol.push_back(Bank[i]);
			}

		}
		sort(sol.begin(),sol.end());
		for(int i = 0 ; i < sol.size() ; i++){
			cout<<sol[i];
			if(i+1!=sol.size())cout<<" ";
		}
		cout << '\n';
	}
	return 0;
}