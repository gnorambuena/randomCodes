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
	int x0,y0,x1,y1; cin >> x0 >> y0 >> x1 >> y1;
	unordered_map<int,unordered_map<int,int>> dist;
	int n; cin >> n;
	while(n--)
	{
		int r,a,b; cin >> r >> a >> b;
		for(int i = a; i <= b; ++i)
			dist[r][i] = INT_MAX;
	}
	dist[x0][y0] = 0;
	queue<pii> q; q.emplace(x0,y0);
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		if(x == x1 && y == y1) break;
		int d = dist[x][y];
		for(int i = -1; i <= 1; ++i)
		{
			auto X = dist.find(x+i);
			if(X != dist.end())
			{
				for(int j = -1; j <= 1; ++j)
				{
					if(i == 0 && j == 0) continue;
					auto Y = X->second.find(y+j);
					if(Y != X->second.end() && Y->second > d+1)
					{
						Y->second = d+1;
						q.emplace(x+i,y+j);
					}
				}
			}
		}
	}
	cout << (dist[x1][y1] != INT_MAX ? dist[x1][y1] : -1);
	return 0;
}