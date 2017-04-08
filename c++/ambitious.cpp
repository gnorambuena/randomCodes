#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwickTree
{
	vector<ll> ft;

	fenwickTree()
	{

	}

	fenwickTree(int n)
	{
		ft.assign(n+1,0);
	}

	void update(int i, ll k)
	{
		for(;i<(int)ft.size();i+=i&(-i))
			ft[i] += k;
	}

	ll query(int i)
	{
		ll ans = 0;
		for(;i;i-=i&(-i))
			ans += ft[i];
		return ans;
	}

	ll query(int i, int j)
	{
		return (i != 0 ? query(j) - query(i-1) : query(j));
	}
};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> A(n); for(ll &a : A) cin >> a;

	vector<fenwickTree> F(n);
	for(int i = 1; i <= n; ++i)
		F[i-1] = fenwickTree(n/i);

	int q; cin >> q;
	while(q--)
	{
		int c; cin >> c;
		if(c == 1)
		{
			int I; cin >> I;
			ll ans = A[I-1];
			for(int i = 1; i <= n; ++i)
				if(I%i == 0)
					ans += F[i-1].query(I/i);
			cout << ans << '\n';
		}
		else
		{
			int l,r,d; cin >> l >> r >> d;
			for(int i = 1; i <= n && l <= n/i; ++i)
			{
				F[i-1].update(l,d);
				F[i-1].update(r+1,-d);
			}
		}
	}
	return 0;
}