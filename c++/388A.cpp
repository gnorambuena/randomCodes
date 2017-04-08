#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int mod = 1e9+7;

bool empty(int count[])
{
	for(int i = 0; i <= 100; ++i)
		if(count[i] != 0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int count[101];
	memset(count,0,sizeof(int)*101);
	
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		count[x]++;
	}
	
	int piles = 0;
	while(!empty(count))
	{
		piles++;
		int length = 0;
		for(int i = 0; i <= 100; ++i)
		{
			int c = min(count[i],i+1-length);
			count[i] -= c;
			length += c;
		}
	}
	cout << piles;
	return 0;
}