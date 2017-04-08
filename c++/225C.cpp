#include<bits/stdc++.h>
#define pb push_back
#define ep emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int n,m,x,y;

vector<ll> sum;
ll blackcost(int l, int r)
{
	return (l > 0 ? sum[r] - sum[l-1] : sum[r]);
}

ll whitecost(int l, int r)
{
	return n*(r-l+1)-blackcost(l,r);
}

vector<vector<vector<ll>>> mem;
ll DP(bool black, int l, int r)
{
	if(r-l+1 < x)
		return INF;
	if(mem[black][l][r] != -1)
		return mem[black][l][r];
	mem[black][l][r] = INF;
	if(black)
		for(int s = l+x-1; s <= r && s-l+1 <= y; ++s)
			mem[black][l][r] = min(mem[black][l][r],blackcost(l,s)+(s != r ? DP(false,s+1,r) : 0));
	else
		for(int s = l+x-1; s <= r && s-l+1 <= y; ++s)
			mem[black][l][r] = min(mem[black][l][r],whitecost(l,s)+(s != r ? DP(true,s+1,r) : 0));
	return mem[black][l][r];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x >> y;
	vector<int> white(m,0);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			char c; cin >> c;
			if(c == '.') white[j]++;
		}
	sum.resize(m); sum[0] = white[0];
	for(int i = 1; i < m; ++i)
	    sum[i] = sum[i-1] + white[i];
	    
	mem.assign(2,vector<vector<ll>>(m,vector<ll>(m,-1)));
	for(int i = 0; i < m; ++i)
	{
		mem[false][i][i] = n-white[i];
		mem[true][i][i] = white[i];
	}
	cout << min(DP(true,0,m-1),DP(false,0,m-1));
	return 0;
}