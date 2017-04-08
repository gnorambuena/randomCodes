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
ll mod = 1e9+9;
ll inf = 1e18;

ll pow(ll n, ll k)
{
	if(k == 1)
		return n;
	ll aux = pow(n,k/2);
	return aux*aux%mod*(k%2 == 1 ? n : 1)%mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m,k; 
	cin >> n >> m >> k;
	ll ans = m;
	m -= n/k*(k-1) + n%k;
	if(m > 0)
		ans = (ans + k*(pow(2LL,m+1)-m-2)%mod)%mod;
	cout << ans;
	return 0;
}