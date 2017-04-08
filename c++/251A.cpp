#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
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
	int n,d; cin >> n >> d;
	vector<int> points(n); for(int &p : points) cin >> p;
	ll ans = 0;
	
	for(ll i = 0; i < n; ++i)
	{
		ll left = i, right = n;
		while(left != right)
		{
			ll mid = (left + right)/2;
			if(points[mid] > points[i]+d)
				right = mid;
			else
				left = mid+1;
		}
		ll length = i-left;
		ans += (length-2)*(length-1)/2;
	}
	cout << ans;
	return 0;
}