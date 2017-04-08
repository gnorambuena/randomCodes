#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	vector<vector<pll>> graph(n);
	while(m--)
	{
		ll a,b,w; cin >> a >> b >> w;
		graph[--a].emplace_back(--b,w);
		graph[b].emplace_back(a,w);
	}
	function<bool(pll, pll)> comp([](pll p1, pll p2){return (p1.second != p2.second ? p1.second > p2.second : p1.first > p2.first)});
	priority_queue<pll,vector<pll>,comp> pq;
	vector<ll> dist(n,LLONG_MAX); dist[0] = 0;
	vector<int> parent(n,-1);
	pq.emplace(0,0); 
	while(!pq.empty())
	{
		pll u = pq.top();
		pq.pop();
		for(pll v : graph[u.first])
			if(dist[v.first] > u.second + v.second)
			{
				parent[v.first] = u.first;
				dist[v.first] = u.second + v.second;
				pq.emplace(v.first,dist[v.first]);
			}
	}
	if(dist[n-1] == LLONG_MAX)
	{
		cout << -1;
		return 0;
	}
	stack<int> output;
	int node = n-1;
	while(node != -1)
	{
		output.push(node+1);
		node = parent[node];
	}
	while(!output.empty())
	{
		cout << output.top() << ' ';
		output.pop();
	}
	return 0;
}