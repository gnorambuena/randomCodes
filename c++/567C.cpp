#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,vector<int>> C;
ll n,k;
int query(int i, ll x)
{
	auto iter = C.find(x);
	if(iter == C.end())
		return -1;
	vector<ll> &v = iter->second;
	int left = 0, right = v.size();
	while(left != right)
	{
		int mid = (left+right)/2;
		if(v[mid] >= i)
			right = mid;
		else
			left = mid+1;
	}
	return left;
}

int many(int i, ll x)
{
	auto iter = C.find(x);
	if(iter == C.end())
		return 0;
	vector<ll> &v = iter->second;
	int left = 0, right = v.size();
	while(left != right)
	{
		int mid = (left+right)/2;
		if(v[mid] >= i)
			right = mid;
		else
			left = mid+1;
	}
	return v.size()-left;
}
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	vector<ll> A(n);
	for(ll i = 0; i < n; ++i)
	{
		cin >> A[i];
		C[A[i]].pb(i);
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		int j = query(i,k*A[i]);
		if(j == -1) continue;
		vector<int> &v = C[k*A[i]];
		for(j; j < v.size(); ++j)
			ans += many(v[j],k*k*A[i]);
	}
	cout << ans;
	return 0;
}
