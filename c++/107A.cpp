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
	int n,p; cin >> n >> p;
	vector<int> pipe(n,-1);
	vector<int> capacity(n,0);
	vector<bool> start(n,true);
	while(p--)
	{
		int a,b,d; cin >> a >> b >> d; 
		pipe[--a] = --b;
		start[b] = false;
		capacity[a] = d;
	}
	
	int t = 0; for(int i = 0; i < n; ++i) if(start[i] && capacity[i] != 0) t++;
	cout << t << '\n';
	for(int i = 0; i < n; ++i)
		if(start[i] && capacity[i] != 0)
		{
			int cap = capacity[i];
			int k = i;
			while(pipe[k] != -1)
			{
				cap = min(capacity[k],cap);
				k = pipe[k];
			}
			cout << i+1 << ' ' << k+1 << ' ' << cap << '\n';
		}
		
	return 0;
}