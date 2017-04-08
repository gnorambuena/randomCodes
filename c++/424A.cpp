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
	int n; cin >> n;
	string hamster; cin >> hamsters;
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += 2*(hamsters[i] == 'X')-1;
	cout << abs(ans) << '\n';
	for(int i = 0; i < n && ans > 0; ++i)
		if(hamsters[i] == 'X')
		{
			hamsters[i] = 'x';
			ans--;
		}
	for(int i = 0; i < n && ans < 0; ++i)
		if(hamsters[i] == 'x')
		{
			hamsters[i] = 'X';
			ans++;
		}
	cout << hamsters;
	return 0;
}