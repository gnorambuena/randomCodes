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
	int n,l,r,Ql,Qr; cin >> n >> l >> r >> Ql >> Qr;
	vector<int> W(n); for(int &w : W) cin >> w;
	int leftsum = 0, rightsum = 0;
	for(int w : W) rightsum += w;
	int ans = INT_MAX;
	for(int L = 0, R = n; L <= n; ++L,--R)
	{
		int opt = l*leftsum+r*rightsum;
		if(L > R)
		{
			L -= R+1;
			opt += Ql*L;
		}
		else if(L < R)
		{
			R -= L+1;
			opt += Qr*R;
		}
		ans = min(opt,ans);
		if(L != n)
		{
			leftsum += W[L];
			rightsum -= W[L];
		}
	}
	cout << ans;
	return 0;
}