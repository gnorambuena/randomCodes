#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,k;
vector<vector<bool>> visited;

bool isVisitable(pii pos)
{
	return 0 <= pos.first && pos.first < n && 0 <= pos.second && pos.second < m && !visited[pos.first][pos.second];
}

pii adjacent(pii pos)
{
	if(isVisitable(pii(pos.first+1,pos.second)))
		return pii(pos.first+1,pos.second);
	if(isVisitable(pii(pos.first,pos.second+1)))
		return pii(pos.first,pos.second+1);
	if(isVisitable(pii(pos.first-1,pos.second)))
		return pii(pos.first-1,pos.second);
	return pii(pos.first,pos.second-1);
}

vector<pii> dfs(pii pos,int length)
{
	vector<pii> ans;
	ans.pb(pos);
	visited[pos.first][pos.second] = true;
	for(int i = 1; i < length; ++i)
	{
		pos = adjacent(pos);
		visited[pos.first][pos.second] = true;
		ans.pb(pos);
	}
	return ans;
}

struct tube
{
	int r;
	vector<pii> structure;
	
	tube()
	{
		r = -1;
		structure = vector<pii>();
	}
	
	tube(pii pos, int length)
	{
		r = length;
		structure = dfs(pos,length);
	}
	
	pii last()
	{
		return structure[r-1];
	}
};

ostream& operator<<(ostream& os, tube& t)
{
	os << t.r;
	for(pii pos : t.structure)
		os << ' ' << pos.first+1 << ' ' << pos.second+1;
	return os;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	visited.assign(n,vector<bool>(m,false));
	int magic = m*n/k;
	pii pos(0,0);
	
	vector<tube> table(k);
	table[0] = tube(pos,magic+m*n%k);
	pos = adjacent(table[0].last());
	
	for(int i = 1; i < k; ++i)
	{
		table[i] = tube(pos,magic);
		pos = adjacent(table[i].last());
	}
	
	for(tube t : table)
		cout << t << '\n';
	
	return 0;
}