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

ostream &operator<<(ostream &out, pii p)
{
	out << p.first << ' ' << p.second;
	return out;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<bool>> evil(n,vector<bool>(n));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			evil[i][j] = (c == 'E');
		}
		
	queue<pii> out;
	bool godoflight = true;
	for(int i = 0; i < n && godoflight; ++i)
	{
		bool purified = false;
		for(int j = 0; j < n && !purified; ++j)
			if(!evil[i][j])
			{
				out.emplace(i+1,j+1);
				purified = true;
			}
		if(!purified)
			godoflight = false;
	}
	if(!godoflight)
	{
		out = queue<pii>();
		godoflight = true;
		for(int j = 0; j < n && godoflight; ++j)
		{
			bool purified = false;
			for(int i = 0; i < n && !purified; ++i)
				if(!evil[i][j])
				{
					out.emplace(i+1,j+1);
					purified = true;
				}
			if(!purified)
				godoflight = false;
		}
	}
	if(!godoflight)
	{
		cout << -1;
		return 0;
	}
	while(!out.empty())
	{
		cout << out.front() << '\n';
		out.pop();
	}
	return 0;
}