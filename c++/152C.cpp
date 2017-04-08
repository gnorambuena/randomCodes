#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	vector<set<char>> magic;
	while(n--)
	{
		string name; cin >> name;
		for(int i = 0; i < m; ++i)
			magic[i].insert(name[i]);
	}
	ll ans = 1;
	for(set<int> uhh : magic)
		ans = (ans*uhh.size())%mod;
	cout << ans;
	return 0;
}