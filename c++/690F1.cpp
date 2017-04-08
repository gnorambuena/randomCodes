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
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1; ++i)
	{
		int a,b; cin >> a >> b;
		graph[--a].pb(--b);
		graph[b].pb(a);
	}
	
	int ans = 0;
	for(int u = 0; u < n; ++u)
		for(int v : graph[u])
			ans += graph[v].size();

	cout << ans/2;
	return 0;
}
