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

ll log10(ll x)
{
	ll ans = 0;
	while(x /= 10)
		ans++;
	return ans;
}

ll lastdigit(ll x)
{
	while(x > 10)
		x /= 10;
	return x;
}

ll pow(ll x, ll n)
{
	if(n == 0)
		return 1LL;
	ll aux = pow(x,n/2);
	return aux*aux*(n%2==1?x:1LL);
}

vector<ll> total {0,9,18};

ll numbers(ll k)
{
	if(k < 10)
		return k;
	if(k%10 == 0)
		k--;
	ll ans = 1;
	ll digit = min(lastdigit(k),k%10);
	ll n = log10(k);
	k /= 10;
	for(int i = 0; i < n-1; ++i)
	{
		ans *= (k%10)+1;
		k /= 10;
	}
	ans += (digit-1)*pow(10LL,n-1);
	ans += total[n];
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(ll i = 2LL; i <= 17LL; ++i)
	{
		total.pb(9*pow(10LL,i-1));
		total[i] += total[i-1];
	}
	
	ll hak = 1;
	for(int k = 0; k <= 18; ++k)
	{
	    powers.insert(hak);
	    hak *= 10LL;
	}
	
	ll l,r; cin >> l >> r;
	return 0;
}