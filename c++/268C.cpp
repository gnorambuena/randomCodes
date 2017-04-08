#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	int k = min(n,m);
	cout << k+1 << '\n';
	for(int i = 0; i <= k; ++i)
		cout << i << ' ' << k-i << '\n';
	return 0;
}