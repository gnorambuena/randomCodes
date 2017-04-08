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

vector<bool> mood;
int n; 
bool check(int num)
{
	for(int k = 0; k < num; ++k)
	{
		bool finish = true;
		for(int i = k; i < n; i += num)
			if(!mood[k])
			{
				finish = false;
				break;
			}
		if(finish)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	mood.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int k; cin >> k;
		mood[i] = (k == 1);
	}
	bool found = false;
	for(int num = 1; num < n/2; ++num)
		if(check(num))
		{
			found = true;
			break;
		}
	cout << (found ? "YES" : "NO");
	return 0;
}