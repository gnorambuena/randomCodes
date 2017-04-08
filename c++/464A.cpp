#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define bits(x) __builtin_popcount(x)
using namespace std;

int n,p; string s;
bool check(int i, char c)
{
	for(int j = i-1; j >= 0 && j >= i-2; --j)
		if(s[j] == c)
			return false;
	return true;
}

bool fail = false;
void next(int i)
{
	if(fail) return;
	s[i]++;
	while(!check(i,s[i]))
		s[i]++;
	if(s[i] - 'a' == p)
	{
		if(i == 0){fail = true; return}
		s[i] = 'a';
		next(i-1);
		next(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> p >> s;
	next(n-1);
	cout << (fail ? "NO" : s);
	return 0;
}