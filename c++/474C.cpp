#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/gcd(x,y)*(y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;

pii operator-(pii a, pii b)
{
	return pii(a.first-b.first,a.second-b.second);
}

pii operator+(pii a, pii b)
{
	return pii(a.first+b.first,a.second+b.second);
}

istream &operator>> (istream &in, pii &p)
{
	in >> p.first >> p.second;
	return in;
}

int dist(pii &a, pii &b)
{
	int x = a.first-b.first, y = a.second-b.second;
	return x*x + y*y;
}

bool check(vector<pii> &v)
{
	sort(v.begin(),v.end());
	int k = dist(v[0],v[1]);
	return k != 0 && v[1] != v[2] && k == dist(v[0],v[2]) && k == dist(v[1],v[3]) && k == dist(v[2],v[3]) && 2*k == dist(v[0],v[3]);
}

pii rotate(int g, pii p)
{
	switch(g)
	{
		case 0:
			return p;
		case 1:
			return pii(-p.second,p.first);
		case 2:
			return pii(-p.first,-p.second);
		case 3:
			return pii(p.second,-p.first);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--)
	{
		vector<pii> H(4),P(4);
		for(int i = 0; i < 4; ++i)
			cin >> P[i] >> H[i];
		int ans = 20;
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				for(int k = 0; k < 4; ++k)
					for(int l = 0; l < 4; ++l)
					{
						vector<pii> v;
						v.pb(H[0]+rotate(i,P[0]-H[0]));
						v.pb(H[1]+rotate(j,P[1]-H[1]));
						v.pb(H[2]+rotate(k,P[2]-H[2]));
						v.pb(H[3]+rotate(l,P[3]-H[3]));
						if(check(v))
							ans = min(ans,i+j+k+l);
					}
		cout << (ans != 20 ? ans : -1) << '\n';
	}
	return 0;
}