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

int n,m;
vector<vector<char>> table;
vector<vector<int>> mem;
map<char,char> NEXT = {{'D','I'},{'I','M'},{'M','A'},{'A','D'}};
vector<vector<bool>> process;
bool cycle = false;

int DP(int i, int j)
{
	if(process[i][j])
		cycle = true;
	if(cycle)
		return 0;
	if(mem[i][j] != -1)
		return mem[i][j];
	mem[i][j] = 1;
	process[i][j] = true;
	if(i > 0 && table[i-1][j] == NEXT[table[i][j]])
		mem[i][j] = max(mem[i][j],1+DP(i-1,j));
	if(i < n-1 && table[i+1][j] == NEXT[table[i][j]])
		mem[i][j] = max(mem[i][j],1+DP(i+1,j));
	if(j > 0 && table[i][j-1] == NEXT[table[i][j]])
		mem[i][j] = max(mem[i][j],1+DP(i,j-1));
	if(j < m-1 && table[i][j+1] == NEXT[table[i][j]])
		mem[i][j] = max(mem[i][j],1+DP(i,j+1));
	process[i][j] = false;
	return mem[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	table.assign(n,vector<char>(m));
	mem.assign(n,vector<int>(m,-1));
	process.assign(n,vector<bool>(m,false));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> table[i][j];

	int ans = 0;
	//cout << DP(0,0);
	for(int i = 0; i < n && !cycle; ++i)
		for(int j = 0; j < m && !cycle; ++j)
			if(table[i][j] == 'D')
				ans = max(ans,DP(i,j)/4);

	if(cycle)
		cout << "Poor Inna!";
	else
	{
		if(ans == 0)
			cout << "Poor Dima!";
		else
			cout << ans;
	}
	return 0;
}
