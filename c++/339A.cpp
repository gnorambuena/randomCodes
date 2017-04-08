#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;

int dfs_count = 0;
vector<int> dfs_low,dfs_num;
vector<bool> visited;
stack<int> S;
vector<vector<int>> graph,SCC;
void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_count++;
	S.push(u); visited[u] = true;
	for(int v : graph[u])
	{
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u])
	{
		SCC.pb(vector<int>());
		while(true)
		{
			int v = S.top(); S.pop(); visited[v] = false;
			SCC.back().pb(v);
			if(u == v)
				break;
		}
	}
}

vector<ll> cost;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	graph.resize(n);
	dfs_low.assign(n,-1);
	dfs_num.assign(n,-1);
	visited.assign(n,false);
	cost.resize(n); for(int i = 0; i < n; ++i) cin >> cost[i];
	int m; cin >> m;
	while(m--)
	{
		int u,v; cin >> u >> v;
		graph[--u].pb(--v);
	}
	
	for(int u = 0; u < n; ++u)
		if(dfs_num[u] == -1)
			tarjanSCC(u);
	
	vector<ll> min_cost(SCC.size());
	ll min_total = 0;
	for(int i = 0; i < SCC.size(); ++i)
	{
	    min_cost[i] = LLONG_MAX;
		for(int v : SCC[i])
			min_cost[i] = min(min_cost[i],cost[v]);
		min_total += min_cost[i];
	}
	ll number = 1;
	for(int i = 0; i < SCC.size(); ++i)
	{
		ll repeat = 0;
		for(int v : SCC[i])
			if(cost[v] == min_cost[i])
				repeat++;
		number = (number*repeat)%mod;
	}
	cout << min_cost << ' ' << number;
	return 0;
}