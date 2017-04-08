#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/gcd(x,y)*(y)
#define SORT(A) sort(A.begin(),A.end())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;
const long double pi = 3.141592653589793238462643383279502884;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m; cin >> m; 
	int discount = INT_MAX;
	while(m--)
	{
		int q; cin >> q;
		discount = min(discount,q);
	}
	
	int n; cin >> n;
	vector<int> A(n); for(int &a : A) cin >> a;
	SORT(A);
	
	int cost = 0;
	int count = 0;
	for(int pos = n-1; pos >= 0; --pos)
	{
		if(count == discount)
		{
			pos--;
			count = 0;
			continue;
		}
		count++;
		cost += A[pos];
	}
	cout << cost;
	return 0;
}