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
	int n; cin >> n;
	map<int,vector<int>> B;
	for(int i = 0; i < n; ++i)
	{
		int b; cin >> b;
		B[b].pb(i);
	}

	int ans = 1;
	for(auto iter = B.begin(); iter != B.end(); ++iter)
	{
		auto jter = iter; jter++;
		for(; jter != B.end(); ++jter)
		{
			int dagh = 1;
			int i = iter->second[0], j = jter->second[0];
			while(i != -1 && j != -1)
			{
				dagh++;
				if(i < j)
				{
					int left = 0, right = iter->second.size();
					while(left != right)
					{
						int mid = (left+right)/2;
						if(iter->second[mid] > j)
							right = mid;
						else
							left = mid+1;
					}
					i = (left != iter->second.size() ? iter->second[left] : -1);
				}
				else
				{
					int left = 0, right = jter->second.size();
					while(left != right)
					{
						int mid = (left+right)/2;
						if(jter->second[mid] > i)
							right = mid;
						else
							left = mid+1;
					}
					j = (left != jter->second.size() ? jter->second[left] : -1);
				}
			}
			ans = max(dagh,ans);
		}
	}
	for(auto iter = B.begin(); iter != B.end(); ++iter)
		ans = max(ans,(int)iter->second.size());
	cout << ans;
	return 0;
}
