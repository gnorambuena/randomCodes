#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> binary(1,0);
	for(int num = 1; num <= 1e9; num *= 10)
	{
		int lim = binary.size();
		for(int i = 0; i < lim; ++i)
			binary.pb(num+binary[i]);
	}
	
	int n; cin >> n;
	int left = 
	return 0;
}