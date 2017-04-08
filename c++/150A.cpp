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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int lim = 1e7;
	vector<bool> prime(lim+1,true); prime[0] = false; prime[1] = false;
	for(int i = 2; i*i <= lim; ++i)
		if(prime[i])
			for(int j = i*i; j <= lim; j+=i)
				prime[j] = false;
	vector<ll> primes;
	for(ll p = 0; p <= lim; ++p)
		if(prime[p])
			primes.pb(p);
	ll q; cin >> q;
	ll ans = q; int count = 0;
	for(ll p : primes)
		while(ans%p == 0 && count < 2)
		{
			ans /= p;
			count++;
		}
	if(count == 0 || (count == 1 && ans == 1)) cout << "1\n0";
	else if(count == 1 || ans == 1) cout << '2';
	else if(count == 2) cout << "1\n" << q/ans;
	return 0;
}