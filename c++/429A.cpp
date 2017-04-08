#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;

vector<vector<int>> graph;
vector<int> dist;
vector<bool> state, goal, marked;
void mark(int u)
{
	for(int v : graph[u])
		if(dist[v] == dist[u]+1)
			for(int w : graph[v])
				if(dist[w] == dist[v]+1)
					marked[w] = !marked[w];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	graph.resize(n);
	
	for(int i = 0; i < n-1; ++i)
	{
		int u,v; cin >> u >> v;
		graph[--v].pb(--u);
		graph[u].pb(v);
	}
	
	state.resize(n); goal.resize(n); 
	for(int i = 0; i < n; ++i){int aux; cin >> aux; state[i] = (aux == 1);}
	for(int i = 0; i < n; ++i){int aux; cin >> aux; goal[i] = (aux == 1);}
	
	dist.assign(n,INT_MAX); dist[0] = 0;
	queue<int> q; q.push(0);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : graph[u])
			if(dist[v] > dist[u]+1)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
	}
	vector<int> nodes(n); for(int i = 0; i < n; ++i) nodes[i] = i;
	sort(nodes.begin(),nodes.end(),[&](int u, int v){return dist[u] < dist[v];});
	
	marked.assign(n,false);
	vector<int> out;
	for(int u = 0 : nodes)
	{
		if(marked[u])
		{
			if(state[u] == goal[u])
			{
				out.pb(u);
				continue;
			}
			mark(u);
		}
		else if(state[u] != goal[u])
		{
			out.pb(u);
			mark(u);
		}
	}
		
	cout << out.size() << '\n';
	for(int o : out) cout << o+1 << '\n';
	return 0;
}