#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int mod = 1e9+7;

struct event
{
	int a,b;
};

istream &operator<<(istream &in, event &E)
{
	int a,b; in >> a >> b;
	E.a = a; E.b = b;
	return in;
}

bool operator<(event &E1,event &E2)
{
	return E2.a < E1.a && E1.b < E2.b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<event> history(n); for(int i = 0; i < n; ++i) cin >> history[i];
	return 0;
}