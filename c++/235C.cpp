#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;
	ll ans = n;
	for(int u = 1; u <= n; ++u)
		ans = max(ans,lcm(n*(n-1),u));
	for(int u = 1; u <= n; ++u)
		ans = max(ans,lcm((n-1)*(n-2),u));
	cout << ans;
	return 0;
}