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
const long double pi = 3.141592653589793238462643383279502884;

int cuadrant(pii p)
{
	int x = p.first, y = p.second;
	if(x > 0 && y >= 0)
		return 1;
	if(x <= 0 && y > 0)
		return 2;
	if(x < 0 && y <= 0)
		return 3;
	if(x >= 0 && y < 0)
		return 4;
}

bool anglecomp(pii a, pii b)
{
	return (cuadrant(a) != cuadrant(b) ? cuadrant(a) < cuadrant(b) : a.first*b.second-b.first*a.second > 0);
}

double angle(pii p)
{
	double aux = atan2(p.second,p.first);
	return (aux >= 0.0 ? aux : 2*pi+aux);
}

istream &operator>>(istream &in, pii &p)
{
	in >> p.first >> p.second;
	return in;
}

ostream &operator<<(ostream &out, pii p)
{
	out << p.first << ' ' << p.second;
	return out;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	int n; cin >> n;
	vector<pii> mannequins(n);
	for(int i = 0; i < n; ++i) cin >> mannequins[i];
	sort(mannequins.begin(),mannequins.end(),anglecomp);
	double attack = 2.0*pi + angle(mannequins[0]) - angle(mannequins[n-1]);
	for(int i = 0; i < n-1; ++i)
		attack = max(attack,angle(mannequins[i+1])-angle(mannequins[i]));
	cout << (2.0*pi - attack)*180.0/pi;
	return 0;
}