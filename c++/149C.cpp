#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pii> kids(n);
	for(int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		kids[i] = pii(i+1,a);
	}
	sort(kids.begin(),kids.end(),[](pii p1,pii p2)->bool{return (p1.second != p2.second ? p1.second < p2.second : p1.first < p2.first);});
	
	vector<int> team1,team2; 
	int diff = 0;
	for(int i = 0; i < n; i += 2)
	{
		if(diff >= 0)
		{
			team1.pb(kids[i+1].first);
			team2.pb(kids[i].first);
			diff += kids[i].second - kids[i+1].second;
		}
		else
		{
			team1.pb(kids[i].first);
			team2.pb(kids[i+1].first);
			diff += kids[i+1].second - kids[i].second;
		}
	}
	if(n%2 == 1)
	{
		if(diff >= 0)
			team1.pb(kids.back().first);
		else
			team2.pb(kids.back().first);
	}
	cout << team1.size() << '\n';
	for(int kid : team1)
		cout << kid << ' ';
	cout << '\n' << team2.size() << '\n';
	for(int kid : team2)
		cout << kid << '\n';
	return 0;
}
