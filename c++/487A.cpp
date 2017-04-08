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

int ceil(int a, int b)
{
	return (a+b-1)/b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Hy, Ay, Dy, Hm, Am, Dm, h, a, d;
	cin >> Hy >> Ay >> Dy >> Hm >> Am >> Dm >> h >> a >> d;
	int base = 0;
	if(Ay <= Dm)
	{
		base += a*(Dm+1-Ay);
		Ay = Dm+1;
	}
	if(Dy >= Am)
	{
		cout << base;
		return 0;
	}
	int ans = (Am-Dy)*d;
	for(int D = 0; D+Dy < Am; ++D)
		for(int A = 0; Ay+A-Dm <= Hm; ++A)
		{
			int turns = ceil(Hm,Ay+A-Dm);
			int left = 0, right = 10020;
			while(left != right)
			{
				int H = (left+right)/2;
				if(ceil(Hy+H,Am-Dy-D) > turns)
					right = H;
				else
					left = H+1;
			}
			if(D*d + A*a + left*h < ans)
				ans = D*d + A*a + left*h;
		}
	cout << base+ans;
	return 0;
}