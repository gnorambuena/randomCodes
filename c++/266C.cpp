#include <bits/stdc++.h>
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

struct operation
{
	int t,i,j;

	operation(int t, int i, int j) : t(t), i(i), j(j) {} 
};

ostream &operator<< (ostream &out, operation &o)
{
	out << o.t << ' ' << o.i+1 << ' ' << o.j+1;
	return out;
}

int n;
queue<operation> Q;
void quicksort(vector<vector<int>> &V, int i = 0, int j = n-1)
{
	if(i >= j)
		return;
	int index = i;
	for(int k = i; k < j; ++k)
		if(V[k].size() <= V[j].size())
		{	
			if(index != k)
			{
				swap(V[index],V[k]);
				Q.emplace(1,index,k);
			}
			index++;
		}
	if(index != j)
	{
		swap(V[index],V[j]);
		Q.emplace(1,index,j);
	}
			
	quicksort(V,i,index-1);
	quicksort(V,index+1,j);
}

void quacksort(vector<int> &V, int i = 0, int j = n-1)
{
	if(i >= j)
		return;
	int index = i;
	for(int k = i; k < j; ++k)
		if(V[k] <= V[j])
		{	
			if(index != k)
			{
				swap(V[index],V[k]);
				Q.emplace(2,index,k);
			}
			index++;
		}
	if(index != j)
	{
		swap(V[index],V[j]);
		Q.emplace(2,index,j);
	}
			
	quacksort(V,i,index-1);
	quacksort(V,index+1,j);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<vector<int>> rows(n);
	vector<vector<int>> matrix(n,vector<int>(n,0));
	for(int i = 0; i < n-1; ++i)
	{
		int x,y; cin >> x >> y;
		rows[--x].pb(--y);
		matrix[x][y] = 1;
	}

	quicksort(rows);

	vector<int> cols(n,INT_MAX);
	for(int i = 0; i < n; ++i)
		for(int j : rows[i])
			cols[j] = min(cols[j],i);

	quacksort(cols);

	cout << Q.size() << '\n';
	while(!Q.empty())
	{
		operation op = Q.front(); Q.pop();
		cout << op << '\n';
		if(op.t == 1)
			swap(matrix[op.i],matrix[op.j]);
		else
		{
			for(int i = 0; i < n; ++i)
				swap(matrix[i][op.i],matrix[i][op.j]);
		}
	}
	cout << endl;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
