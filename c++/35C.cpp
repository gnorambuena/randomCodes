#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;


int main()
{ 
	ifstream in; in.open("input.txt",ios::in);
	ofstream out; out.open("output.txt",ios::out);

	int n,m; in >> n >> m;
	vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
	queue<pii> q;
	int k; in >> k;
	while(k--)
	{
		int x,y; in >> x >> y;
		dist[--x][--y] = 0;
		q.emplace(x,y);
	}
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		if(x > 0 && dist[x-1][y] > dist[x][y]+1)
		{
			dist[x-1][y] = dist[x][y]+1;
			q.emplace(x-1,y);
		}
		if(x < n-1 && dist[x+1][y] > dist[x][y]+1)
		{
			dist[x+1][y] = dist[x][y]+1;
			q.emplace(x+1,y);
		}
		if(y > 0 && dist[x][y-1] > dist[x][y]+1)
		{
			dist[x][y-1] = dist[x][y]+1;
			q.emplace(x,y-1);
		}
		if(y < m-1 && dist[x][y+1] > dist[x][y]+1)
		{
			dist[x][y+1] = dist[x][y]+1;
			q.emplace(x,y+1);
		}
	}

	int x = 0, y = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(dist[i][j] > dist[x][y])
			{
				x = i;
				y = j;
			}

	out << x+1 << ' ' << y+1;
	return 0;
}
