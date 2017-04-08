#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	regex three("\(.\)\1\{9,\}");
	cout << cout << regex_replace(s,three,"BIEN");
	return 0;
}