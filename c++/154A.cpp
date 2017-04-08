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
const long double pi = 3.141592653589793238462643383279502884;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n; cin >> n;
	map<char,char> F;
	while(n--)
	{
		char a,b; cin >> a >> b;
		F[a] = b;
		F[b] = a;
	}
	int ans = 0;
	int pos = 0;
	while(pos != s.length())
	{
		char a = s[pos], b = F[a];
		int countA, countB; countA = countB = 0;
		while(pos < s.length() && (s[pos] == a || s[pos] == b))
			(s[pos++] == a ? countA++ : countB++);
		ans += min(countA,countB);
	}
	cout << ans;
	return 0;
}