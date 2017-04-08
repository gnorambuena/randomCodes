#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

string construct(int n, int m)
{
	if(abs(n-m) > 1)
		return "110" + construct(n-1,m-2);
	string ans(n+m,'0')
	if(n+1 == m)
		for(int i = 1; i < n+m; i += 2)
			ans[i] = '1';
	if(n == m)
		for(int i = 0; i < n+m; i += 2)
			ans[i] = '1';
	if(n-1 == m)
	{
		for(int i = 0; i < n+m; i += 2)
			ans[i] = '1';
		ans[n+m-1] = '1';
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	if(2*n+2 < m || m+1 < n)
	{
		cout << -1;
		return 0;
	}
	
	return 0;
}