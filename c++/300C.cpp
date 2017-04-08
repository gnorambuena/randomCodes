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

int a,b; 
bool good(int n)
{
	while(n)
	{
		if(n%10 != a && n%10 != b)
			return false;
		n /= 10;
	}
	return true;
}

ll pow(ll x, ll n)
{
	if(n == 1)
		return x;
	ll aux = pow(x,n/2);
	return aux*aux%mod*(n%2 == 1 ? x : 1)%mod;
}


vector<ll> factorial;
vector<ll> inv;
ll inverse(int k)
{
	if(inv[k] != -1)
		return inv[k];
	inv[k] = pow(factorial[k],mod-2);
	return inv[k];
}
ll C(int n,int k)
{
	return factorial[n]*inverse(k)%mod*inverse(n-k)%mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> a >> b;
	factorial.resize(n+1);
	factorial[0] = 1;
	for(int k = 1; k <= n; ++k)
		factorial[k] = factorial[k-1]*k%mod;
	inv.assign(n+1,-1); 
	ll ans = 0;
	for(int k = 0; k <= n; ++k)
		if(good(a*k+b*(n-k)))
			ans = (ans + C(n,k))%mod;
	cout << ans;
	return 0;
}