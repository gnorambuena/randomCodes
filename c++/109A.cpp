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
	
	int solA = -1,solB = -1;
	for(int b = 0; 7*b <= n; ++b)
		if((n-7*b)%4 == 0)
		{
			solA = (n-7*b)/4;
			solB = b;
		}
	cout << (solA == -1 ? "-1" : string(solA,'4')+string(solB,'7'));
	return 0;
}