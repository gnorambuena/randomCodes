#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;

typedef pair<pii,pii> segment;

istream &operator>>(istream &in, pii &p)
{
	in >> p.first >> p.second;
	return in;
}

istream &operator>>(istream &in, segment &s)
{
	in >> s.first >> s.second;
	return in;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
	set<pii> P; set<segment> S;

	for(int i = 0; i < 4; ++i)
	{
		segment s; cin >> s;
		if(s.first > s.second)
			swap(s.first,s.second);
		S.insert(s);
		P.insert(s.first); P.insert(s.second);
	}  

	if(P.size() != 4)
	{
		cout << "NO";
		return 0;
	}

	for(pii p : P)
	{
		xmin = min(xmin,p.first);
		xmax = max(xmax,p.first);
		ymin = min(ymin,p.second);
		ymax = max(ymax,p.second);
	}

	cout << (S.count(segment(pii(xmin,ymin),pii(xmin,ymax))) && S.count(segment(pii(xmin,ymin),pii(xmax,ymin)))
		&& S.count(segment(pii(xmin,ymax),pii(xmax,ymax))) && S.count(segment(pii(xmax,ymin),pii(xmax,ymax)))
		? : "YES" : "NO");
	return 0;
}
