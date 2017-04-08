#include<bits/stdc++.h>
#define pb push_back
#define ep emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> stripe(n); 
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		int s; cin >> s;
		sum += s;
		stripe[i] = s;
	}
	
	if(s%2 == 1)
	{
		cout << 0;
		return 0;
	}
	
	int parsum = 0;
	int ans = 0;
	for(int i = 0; i < n-1; ++i)
	{
		parsum += stripe[i];
		if(parsum == sum/2)
			ans++;
	}
	
	cout << ans;
	return 0;
}