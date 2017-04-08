#include<bits/stdc++.h>
#define pb push_back
#define ep emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--)
	{
		ll n,l,r; cin >> n >> l >> r;
		ll factor = n/l;
		if(l*factor <= n && n <= r*factor)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}