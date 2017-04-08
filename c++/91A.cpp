#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s1,s2; cin >> s1 >> s2;
	vector<vector<int>> prox(s1.length()+1,vector<int>(26,s1.length()));
	vector<int> aux(26,s1.length());
	for(int i = 0; i < s1.length(); ++i)
		aux[s1[i]-'a'] = min(aux[s1[i]-'a'],i);
	prox[0] = aux;
	for(int i = 0; i < s1.length(); ++i)
	{
		for(int j = i+1; j < s1.length(); ++j)
			if(s1[j] == s1[i])
			{
				aux[s1[i]-'a'] = j;
				break;
			}
		if(aux[s1[i]-'a'] == prox[i][s1[i]-'a'])
			aux[s1[i]-'a'] = s1.length();
		prox[i+1] = aux;
	}
	int ans = 0;
	int pos = 0;
	while(pos != s2.length())
	{
		ans++;
		int i = prox[0][s2[pos]-'a'];
		if(i == s1.length())
		{
			cout << -1;
			return 0;
		}
		while(pos != s2.length() && i != s1.length())
			i = prox[i][s2[pos++]-'a'];
		
	}
	cout << ans;
	return 0;
}
