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

ll pow(ll x, ll n)
{
	if(n == 1)
		return x;
	ll aux = pow(x,n/2);
	return aux*aux*(n%2 == 1 ? x : 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ll> lucky = {4LL,7LL};
	int left = 0, right = 2;
	for(int p = 1; p < 9; ++p)
	{
		for(int i = left; i < right; ++i)
		{
			lucky.pb(10*lucky[i]+4);
			lucky.pb(10*lucky[i]+7);
		}
		left = right;
		right += pow(2LL,p+1);
	}
	lucky.pb(4444444444);
	ll l,r; cin >> l >> r;
	left = 0, right = lucky.size()-1;
	while(left != right)
	{
		int mid = left + (right-left)/2;
		if(lucky[mid] >= l)
			right = mid;
		else
			left = mid+1;
	}
	int pos = left;
	ll ans = lucky[pos]*(lucky[pos]-l+1);
	if(r > lucky[pos]) pos++;
	while(lucky[pos] < r)
	{
		ans += lucky[pos]*(lucky[pos]-lucky[pos-1]);
		pos++;
	}
	ans += lucky[pos]*(r-lucky[pos-1]);
	cout << ans;
	return 0;
}