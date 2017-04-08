#include <iostream>
#include <vector>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
typedef long long ll;	
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;

struct minsegmentTree
{
	inline int left(int n) {return (n << 1);}
	inline int right(int n) {return ((n << 1) + 1);}

	vector<int> st,lazy,A;
	int size;

	minsegmentTree(vector<int> arr)
	{
		A = arr;
		size = A.size();
		lazy.assign(4*size,0);
		st.resize(4*size);
		build(1,0,size-1);
	}

	void build(int node, int a, int b)
	{
		if(a > b) return;

		if(a == b) 
		{
			st[node] = A[a];
			return;
		}

		build(left(node),a,(a+b)/2);
		build(right(node),(a+b)/2+1,b);

		//Combinacion
		st[node] = min(st[left(node)],st[right(node)]);
	}

	void update(int i, int j, int value)
	{
		update(i,j,value,1,0,size-1);
	}

	void update(int i, int j, int value, int node, int a, int b)
	{
		if(a > b || a > j || b < i)
			return;

		if(lazy[node] != 0)
		{
			st[node] += lazy[node];

			if(a != b)
			{
				lazy[left(node)] += lazy[node];
				lazy[right(node)] += lazy[node];	
			}

			lazy[node] = 0;
		}

		if(a >= i && b <= j)
		{
			lazy[node] += value;

			if(a != b)
			{
				lazy[left(node)] += value;
				lazy[right(node)] += value;
			}

			return;
		}

		update(i,j,value,left(node),a,(a+b)/2);
		update(i,j,value,right(node),(a+b)/2+1,b);

		st[node] = min(st[left(node)],st[right(node)]);
	}

	int query(int i, int j)
	{
		return query(i,j,1,0,size-1);
	}

	int query(int i, int j, int node, int a, int b)
	{
		if(a > b || a > j || b < i)
			return INT_MAX; //NEUTRO!

		if(lazy[node] != 0)
		{
			st[node] += lazy[node];

			if(a != b)
			{
				lazy[left(node)] += lazy[node];
				lazy[right(node)] += lazy[node];
			}

			lazy[node] = 0;
		}

		if(a >= i && b <= j)
			return st[node];
		else
			return min(query(i,j,left(node),a,(a+b)/2),query(i,j,right(node),(a+b)/2+1,b)); // Composicion
	}

};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	vector<int> A = {5,9,2,3,8,10,-10,4,1};
	segmentTree S(A);

	return 0;
}