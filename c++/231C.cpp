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
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	cout << (n/5)*(m/5)*5 + max(0,n%5+m%5-4);
}
