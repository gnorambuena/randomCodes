#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(cin >> n)
	{
		vector<int> A(n); 
		for(int &a : A) cin >> a;
		
		vector<int> izq(n), der(n);
		izq[0] = der[n-1] = 1;
		
		for(int i = 1; i < n; ++i)
			izq[i] = min(izq[i-1]+1,A[i]);
		for(int i = n-2; i >= 0; --i)
			der[i] = min(der[i+1]+1,A[i]);
		
		int ans = 1;
		for(int i = 0; i < n; ++i)
			ans = max(ans,min(izq[i],der[i]));
		
		cout << ans << '\n';
	}
	return 0;
}
