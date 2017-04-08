#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int n,m;
vector<vector<bool> > tree;
vector<vector<int> > value;

bool adj(int i, int j){
	if(i == 0 or i == n-1 or j == 0 or j == m-1)
		return true;
	if(!tree[i-1][j])
		return true;
	if(!tree[i+1][j])
		return true;
	if(!tree[i][j-1])
		return true;
	if(!tree[i][j+1])
		return true;
	return false;
}

int main(){
	cin>>n>>m;
	tree.assign(n,vector<bool>(m,false));
	value.assign(n,vector<int>(m,-1));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char mander;
			cin>>mander;
			if(mander=='T'){
				tree[i][j]=true;
			}
			else{
				value[i][j]=0;
			}
		}
	}

	queue<pii> q;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(tree[i][j] && adj(i,j))
			{
				q.push(pii(i,j));
				value[i][j] = 1;
			}

	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if(i > 0 && value[i-1][j] == -1)
		{
			value[i-1][j] = value[i][j]+1;
			q.push(pii(i-1,j));
		}
		if(i < n-1 && value[i+1][j] == -1)
		{
			value[i+1][j] = value[i][j]+1;
			q.push(pii(i+1,j));
		}
		if(j > 0 && value[i][j-1] == -1)
		{
			value[i][j-1] = value[i][j]+1;
			q.push(pii(i,j-1));
		}
		if(j < m-1 && value[i][j+1] == -1)
		{
			value[i][j+1] = value[i][j]+1;
			q.push(pii(i,j+1));
		}
	}
	
	int M = -1;
	for(vector<int> mywea : value)
		for(int wea : mywea)
			M = max(M,wea);

	vector<string> output;
	if(M < 10)
	{
		output.assign(n,string(2*m,'.'));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(value[i][j] > 0)
					output[i][2*j+1] = '0'+value[i][j];
	}
	else
	{
		output.assign(n,string(3*m,'.'));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				if(value[i][j] >= 10)
				{
					output[i][3*j+2] = '0'+value[i][j]%10;
					value[i][j] /= 10;
					output[i][3*j+1] = '0'+value[i][j];
				}
				else
					if(value[i][j] != 0)
					output[i][3*j+2] = '0'+value[i][j];
			}
	}
	int count = 0;
	for(string lawea : output)
		cout << lawea << '\n';
	return 0;
}