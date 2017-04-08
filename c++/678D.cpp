#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;

ll fastexp(ll a, ll b)
{
	if(b == 0)
		return 1;
	ll aux = fastexp(a,b/2);
	return aux*aux%mod*(b%2 == 1 ? a : 1)%mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll A,B,n,x; cin >> A >> B >> n >> x;
	if(A == 1)
	    cout << (x + n%mod*B%mod)%mod;
	else
	    cout << (fastexp(A,n)*x%mod + (fastexp(A,n)-1)*fastexp(A-1,mod-2)%mod*B%mod)%mod;
	return 0;
}