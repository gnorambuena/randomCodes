#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

vector<vector<int>> mem;

bool dp(int L, int sum)
{
	if(sum < 0)
		return false;
	if(mem[L][sum] != -1)
		return mem[L][sum];
	mem[L][sum] = 0;
	for(int k = 0; k < 10 && !mem[L][sum]; ++k)
		mem[L][sum] = DP(L-1,sum-k);
	return mem[L][sum];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m,s; cin >> m >> s;
	mem.assign(m,vector<int>(s,-1));
	mem[0][0] = 1;
	for(int i = 1; i <= s; ++i)
		mem[0][i] = 0;
	
	int _ = -1, __ = -1,_s = s, __s = s;
	
	for(int k = 1; k <= 9; ++k)
		if(dp(m-1,_s-k))
		{
			_ = k;
			_s -= k;
			break;
		}
	
	for(int k = 9; k >= 1; --k)
		if(dp(m-1,__s-k))
		{
			__ = k;
			__s -= k;
			break;
		}
	if(_ == -1 && __ = -1)
	{
		cout << "-1 -1";
		return 0;
	}
	
	int length = 1;
	while(++length < m)
	{
		_ *= 10;
		__ *= 10;
		
		for(int k = 0; k <= 9; ++k)
			if(dp(m-length,_s-k))
			{
				_ += k;
				_s -= k;
				break;
			}
		for(int k = 9; k >= 0; --k)
			if(dp(m-length,__s-k))
			{
				__ += k;
				__s -= k;
				break;
			}
	}
	
	cout << _ << ' ' << __;
	return 0;
}