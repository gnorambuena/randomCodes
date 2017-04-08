#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.length();
	int lim = n/2;

	vector<bool> prime(lim+1,true); prime[0] = prime[1] = false;
	for(int i = 2; i*i <= lim; ++i)
		if(prime[i])
			for(int j = i*i; j <= lim; j+=i)
				prime[j] = false;

	vector<bool> magic(n,false);
	for(int i = 0; i <= lim; ++i)
		if(prime[i])
			for(int j = 1; i*j <= n; ++j)
				magic[i*j-1] = true;

	int card = 0;
	for(bool m : magic)
		if(m)
			card++;

	vector<int> counting(26,0);
	for(char c : s)
		counting[c-'a']++;

	char C = 'a';
	for(char c = 'a'; c <= 'z'; ++c)
		if(counting[c-'a'] > counting[C-'a'])
			C = c;

	if(counting[C-'a'] < card)
	{
		cout << "NO";
		return 0;
	}
	else
		cout << "YES\n";

	string ans(n,'\0');
	for(int i = 0; i < n; ++i)
		if(magic[i])
			ans[i] = C;

	counting[C-'a'] -= card;
	char c = 'a';
	for(int i = 0; i < n; ++i)
	{
		if(ans[i] != '\0')
			continue;
		while(counting[c-'a'] == 0)
			c++;
		ans[i] = c;
		counting[c-'a']--;
	}

	cout << ans;
	return 0;
}