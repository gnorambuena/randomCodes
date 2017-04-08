#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> right(2*n-1,0);
	vector<ll> left(2*n-1,0);
	vector<vector<ll>> table(n,vector<ll>(n));
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			cin >> table[i][j];
			left[j-i+n-1] += table[i][j];
			right[i+j] += table[i][j];
		}
		
	int x1,y1;
	ll opt1 = -1;
	for(int i = 0; i < 2*n-1; ++i)
	{
		int x = 
		if(left[i]+right)
		
	int x2,y2;
	ll opt2 = -1;
	for(int i = 0; i < n; ++i)
		for(int j = (i+1)%2; j < n; j+=2)
		{
			ll value = left[j-i+n-1]+right[i+j]-table[i][j];
			if(value > opt2)
			{
				opt2 = value;
				x2 = i; y2 = j;
			}
		}
	
	cout << opt1+opt2 << '\n' << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1;
	return 0;
}