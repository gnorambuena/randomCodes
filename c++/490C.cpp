#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string key; cin >> key;
	int a,b; cin >> a >> b;
	int K = key.length();
	
	int B[K];
	B[K-1] = (key[K-1]-'0')%b;
	for(int i = K-2, pow = 10%b; i >= 0; --i, pow = 10*pow%b)
		B[i] = (B[i+1] + pow*(key[i]-'0'))%b;
	
	int A = (key[0]-'0')%a;
	bool found = false;
	for(int pos = 1; pos < K; ++pos)
	{
		if(key[pos] != '0' && A == 0 && B[pos] == 0)
		{
			cout << "YES\n" << key.substr(0,pos) << '\n' << key.substr(pos,K);
			found = true;
			break;
		}
		A = (10*A + key[pos])%a;
	}
	if(!found) cout << "NO";
	return 0;
}