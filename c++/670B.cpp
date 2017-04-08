#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k; cin >> n >> k;
	vector<int> id(n);
	for(int i = 0; i < n; ++i)
		cin >> id[i];
	ll left = 0, right = min(63245LL,n);
	while(left != right)
	{
		ll mid = (left+right)/2;
		if(mid*(mid+1)/2 >= k)
			right = mid;
		else
			left = mid+1;
	}
	k -= left*(right-1)/2+1;
	cout << id[k];
	return 0;
}
