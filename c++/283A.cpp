#include<bits/stdc++.h>
#define pb push_back
#define ep emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;

int main()
{
	int n; scanf("%d",&n);
	vector<ll> delta;
	ll end = 0;
	ll sum = 0;
	ll size = 1;
	while(n--)
	{
		int t; scanf("%d",&t);
		if(t == 1)
		{
			ll a,x; scanf("%lld%lld",&a,&x);
			sum += a*x;
			if(a == size)
				end += x;
			else
				delta[a-1] -= x;
		}
		if(t == 2)
		{
			ll k; scanf("%lld",&k);
			delta.pb(k-end);
			sum += k;
			end = k;
			size++;
		}
		if(t == 3)
		{
		    sum -= end;
			end -= delta.back();
			delta.pop_back();
			size--;
		}
		printf("%.6f%c",(float)sum/size,'\n');
	}
	return 0;
}