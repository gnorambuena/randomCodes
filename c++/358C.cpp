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
	int n; cin >> n;
	vector<int> A;
	int first,second,third; first = second = third = 0;
	while(n--)
	{
		int a; cin >> a;

		if(a == 0)
		{
			if(A.size() == 0)
				cout << "0\n";
			else if(A.size() == 1)
				cout << "pushStack\n1 popStack\n";
			else if(A.size() == 2)
				cout << "pushStack\npushQueue\n2 popStack popQueue\n";
			else
			{
				int i = 0;
				while(A[i] != first && A[i] != second && A[i] != third)
				{
					cout << "pushStack\n";
					++i;
				}
				cout << "pushStack\n";
				++i;
				while(A[i] != first && A[i] != second && A[i] != third)
				{
					cout << "pushBack\n";
					++i;
				}
				cout << "pushBack\n";
				++i;
				while(A[i] != first && A[i] != second && A[i] != third)
				{
					cout << "pushFront\n";
					++i;
				}
				while(i < A.size())
				{
					cout << "pushQueue\n";
					++i;
				}
				cout << "3 popStack popBack popQueue\n";
			}
			A.clear();
			first = second = third = 0;
		}

		else
		{
			A.pb(a);
			if(a > first)
			{
				third = second;
				second = first;
				first = a;
			}
			else if(a > second)
			{
				third = second;
				second = a;
			}
			else if(a > third)
				third = a;
		}
	}
	for(int i = 0; i < A.size(); ++i)
		cout << "pushStack\n";
	return 0;
}