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

pii operator+(pii a, pii b)
{
	return pii(a.first+b.first,a.second+b.second);
}

pii operator-(pii a, pii b)
{
	return pii(a.first-b.first,a.second-b.second);
}

pii operator*(int k, pii p)
{
	return pii(k*p.first,k*p.second);
}

ostream &operator<<(ostream &out, pii p)
{
	out << p.first << ' ' << p.second;
	return out;
}

vector<int> squares(1001);
int sqrt(int x)
{
	int left = 0, right = 1000;
	while(left != right)
	{
		int mid = (left+right)/2;
		if(squares[mid] >= x)
			right = mid;
		else
			left = mid+1;
	}
	if(squares[left] == x)
		return left;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 0; i < 1001; ++i)
		squares[i] = i*i;
	int a,b; cin >> a >> b;
	bool found = false;
	for(int ax = 1; ax < a; ++ax)
	{
		int ay = sqrt(a*a-ax*ax);
		if(ay == -1) continue;
		pii A(ax,ay);
		int k = gcd(ax,ay);
		pii director = pii(-ay/k,ax/k);
		int norm = a/k;
		if(b%norm != 0) continue;
		pii B = b/norm*director;
		if((A+B).first != 0)
		{
			found = true;
			cout << "YES\n" << pii(0,0) << '\n' << A << '\n' << A+B;
			break;
		}
		if((A-B).second != 0)
		{
			found = true;
			cout << "YES\n" << pii(0,0) << '\n' << A << '\n' << A-B;
			break;
		}
	}
	if(!found) cout << "NO";
	return 0;
}