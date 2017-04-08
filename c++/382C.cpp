#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	if(n == 1)
		{cout << -1; return 0;}
	
	int cards[n];
	for(int i = 0; i < n; ++i) cin >> cards[i];
	sort(cards,cards+n);
	
	if(n == 2)
	{
		if((cards[1]-cards[0])%2 == 0)
			cout << "3\n" << 2*cards[1]-cards[0] << ' ' << (cards[1]+cards[2])/2 << ' ' << 2*cards[0]-cards[1];
		else
			cout << "2\n" << 2*cards[1]-cards[0] << ' ' << 2*cards[0]-cards[1];
		return 0;
	}
	
	int k = cards[1]-cards[0];
	int crap = -1;
	for(int i = 2; i < n; ++i)
	{
		int dist = cards[i]-cards[i-1];
		if(dist != k)
		{
			if(crap == -1)
				crap = i;
			else
			{
				cout << 0;
				return 0;
			}
		}
	}
	if(crap != -1)
	{
		if(2*k == cards[crap]-cards[crap-1])
			cout << "1\n" << (cards[crap]+cards[crap-1])/2;
		else
			cout << 0;
	}
	else
		cout << "2\n" << cards[0]-k << ' ' << cards[n-1]+k;
	return 0;
}