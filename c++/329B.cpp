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

int r,c; 
vector<vector<char>> forest;
bool visitable(int row, int col)
{
	return row >= 0 && col >= 0 && row < r && col < c && forest[row][col] != 'T';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	forest.assign(r,vector<char>(c));
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		
			cin >> forest[i][j];
	
	int exrow = -1,excol = -1;
	for(int i = 0; i < r && exrow == -1; ++i)
		for(int j = 0; j < c && excol == -1; ++j)
			if(forest[i][j] == 'E')
			{
				exrow = i;
				excol = j;
			}
			
	vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
	dist[exrow][excol] = 0;
	queue<pii> q; q.emplace(exrow,excol);
	
	while(!q.empty())
	{
		int row = q.front().first, col = q.front().second; q.pop();
		if(visitable(row+1,col) && dist[row+1][col] > dist[row][col]+1)
		{
			dist[row+1][col] = dist[row][col]+1;
			q.emplace(row+1,col);
		}
		if(visitable(row-1,col) && dist[row-1][col] > dist[row][col]+1)
		{
			dist[row-1][col] = dist[row][col]+1;
			q.emplace(row-1,col);
		}
		if(visitable(row,col+1) && dist[row][col+1] > dist[row][col]+1)
		{
			dist[row][col+1] = dist[row][col]+1;
			q.emplace(row,col+1);
		}
		if(visitable(row,col-1) && dist[row][col-1] > dist[row][col]+1)
		{
			dist[row][col-1] = dist[row][col]+1;
			q.emplace(row,col-1);
		}
	}
	
	int distance = -1;
	for(int i = 0; i < r && distance == -1; ++i)
		for(int j = 0; j < c && distance == -1; ++j)
			if(forest[i][j] == 'S')
				distance = dist[i][j];

	int ans = 0;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			if(dist[i][j] <= dist && forest[i][j] > '0' && forest[i][j] <= '9')
				ans += forest[i][j] - '0';
	
	cout << ans;
	return 0;
}