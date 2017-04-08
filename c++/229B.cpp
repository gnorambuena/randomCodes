#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod = 1e9+7;

vector<vector<int>> tempus;

bool bs(int i, int t)
{
	if(tempus[i].empty())
		return false;
	int left = 0, right = tempus[i].size();
	while(left != right)
	{
		int mid = left + (right - left)/2;
		if(t <= tempus[i][mid])
			right = mid;
		else
			left = mid+1;
	}
	return (right != tempus[i].size() && tempus[i][right] == t);
}

vector<map<int,int>> mem;
int DP(int i, int t)
{
	if(!bs(i,t))
		return 0;
	int &value = mem[i][t];
	if(value != 0)
		return value;
	value = DP(i,t+1)+1;
	return value;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	vector<vector<pii>> graph(n);
	while(m--)
	{
		int a,b,c; cin >> a >> b >> c;
		graph[--a].eb(--b,c);
		graph[b].eb(a,c);
	}
	tempus.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int k; cin >> k;
		while(k--)
		{
			int t; cin >> t;
			tempus[i].pb(t);
		}
	}
	
	mem.resize(n);
	vector<int> dist(n,INT_MAX);
	dist[0] = 0;
	priority_queue<pii,vector<pii>,function<bool(pii,pii)>> pq([](pii p1, pii p2){return (p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first);});
	pq.emplace(0,0);
	while(!pq.empty())
	{
		pii u = pq.top(); pq.pop();
		if(u.first == n-1)
		    break;
		for(pii v : graph[u.first])
		{
			int aux = u.second+v.second+DP(u.first,u.second);
			if(dist[v.first] > aux)
			{
				dist[v.first] = aux;
				pq.emplace(v.first,aux);
			}
		}
	}
	cout << (dist[n-1] != INT_MAX ? dist[n-1] : -1);
	return 0;
}