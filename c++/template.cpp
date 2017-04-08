#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct fenwickTree
{
	vector<int> ft;

	fenwickTree(int n)
	{
		ft.assign(n+1,0);
	}

	void update(int i, int k)
	{
		for(;i<(int)ft.size();i+=i&(-i))
			ft[i] += k;
	}

	int query(int i)
	{
		int ans = 0;
		for(;i;i-=i&(-i))
			ans += ft[i];
		return ans;
	}

	int query(int i, int j)
	{
		return (i != 0 ? query(j) - query(i-1) : query(j));
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> C(n); for(int &c : C) cin >> c;
	vector<vector<int>> mem(n,vector<int>(n));

	for(int i = 0; i < n; ++i)
		mem[i][i] = 1;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < i; ++j)
			mem[i][j] = 0;


	for(int j = 0; j < n; ++j)
		for(int i = 0; i < j; ++i)
		{
			mem[i][j] = j-i+1;
			for(int k = i; k <= j; ++k)
				if(C[k] == C[j])
					mem[i][j] = min(mem[i][j],mem[i][k-1]+mem[k+1][j-1]);
		}

	cout << mem[0][n-1];
	return 0;
}