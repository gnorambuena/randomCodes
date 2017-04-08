#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> graph(n);

	for(int i = 0; i < n-1; ++i)
	{
		int a,b; cin >> a >> b;
		graph[--a].pb(--b);
		graph[b].pb(a);
	}

	vector<int> dist(n,-1);
	queue<int> q; q.push(0); dist[0] = 0;

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : graph[u])
			if(dist[v] == -1)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
	}

	int end1 = 0;
	for(int i = 0; i < n; ++i)
		if(dist[i] > dist[end1])
			end1 = i;

	vector<int> dist1(n,-1);
	q.push(end1); dist1[end1] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : graph[u])
			if(dist1[v] == -1)
			{
				dist1[v] = dist1[u]+1;
				q.push(v);
			}
	}

	int end2 = 0;
	for(int i = 0; i < n; ++i)
		if(dist1[i] > dist1[end1])
			end2 = i;

	vector<int> dist2(n,-1);
	q.push(end2); dist2[end2] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : graph[u])
			if(dist2[v] == -1)
			{
				dist2[v] = dist2[u]+1;
				q.push(v);
			}
	}

	int m; cin >> m;
	while(m--)
	{
		int a,b; cin >> a >> b;
		a--; b--;
		cout << max(min(dist1[a],dist2[a]),min(dist1[b],dist2[b])) << '\n';
	}

	return 0;
}