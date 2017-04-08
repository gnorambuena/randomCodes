#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout << (i == j ? k : 0) << ' ';
		cout << '\n';
	}
	return 0;
}