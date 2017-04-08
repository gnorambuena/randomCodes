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
	ll a; cin >> a;
	string s; cin >> s;
	int n = s.length();
	vector<ll> summa(n); summa[0] = s[0]-'0';
	for(int i = 1; i < n; ++i) summa[i] = s[i]-'0'+summa[i-1];
	auto sum = [&](int i, int j){return summa[j] - (i > 0 ? summa[i-1] : 0);};
	unordered_map<ll,ll> appear;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
			appear[sum(i,j)]++;
	ll ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
		{
			ll k = sum(i,j);
			if(k == 0)
				ans += (a == 0 ? n*(n+1)/2 : 0);
			else if(a%k == 0)
				ans += appear[a/k];
		}
	cout << ans;
	return 0;
}