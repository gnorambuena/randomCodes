#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string nameA = "Dasha", nameB = "Masha";
	ll a,b; cin >> a >> b;
	if(a > b)
		swap(a,b),swap(nameA,nameB);
	ll A = 0, B = 0;
	ll time = a;
	while(time != 0)
	{
		while(time + a < b)
			time += a;
		A += time;
		B += b-time;
		time = (time+a)%b;
	}
	if(A > B)
		cout << nameA;
	else if(A == B)
		cout << "Equal";
	else
		cout << nameB;
	return 0;
}
