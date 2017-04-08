#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/gcd(x,y)*(y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;
const long double pi = 3.141592653589793238462643383279502884;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	vector<vector<bool>> graph(n,vector<bool>(n,false));
	while(m--)
	{
		int u,v; cin >> u >> v; u--,v--;
		graph[u][v] = graph[v][u] = true;
	}
	
	vector<int> dist(n,INT_MAX);
	dist[0] = 0; 
	queue<int> q; q.push(0);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == n-1)
			break;
		for(int v = 0; v < n; ++v)
			if(graph[u][v] && dist[v] > dist[u]+1)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
	}
	if(dist[n-1] == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	int train = dist[n-1];
	dist.assign(n,INT_MAX);
	dist[0] = 0;
	q = queue<int>(); q.push(0);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == n-1)
			break;
		for(int v = 0; v < n; ++v)
			if(!graph[u][v] && dist[v] > dist[u]+1)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
	}
	if(dist[n-1] == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	int bus = dist[n-1];
	cout << max(train,bus);
	return 0;
}