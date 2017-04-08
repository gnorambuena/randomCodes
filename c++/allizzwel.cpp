#include <iostream>
#include <vector>
#include <string>
using namespace std;
string c = "ALLIZZWELL";
vector<vector<bool> > visited;
vector<int>xindex={-1,-1,-1,0,1,1,1,0};
vector<int>yindex={-1,0,1,1,1,0,-1,-1};
bool dfs(vector<vector<char>>&table,int x, int y,int index){
	//cout<<s<<endl;
	//cout<<x<<" "<<y<<endl;
	visited[x][y]=true;
	if(index==9){
		return true;
	}
	for(int i = 0 ; i < xindex.size() ;i++){
		if(x+xindex[i]>=0 && y+yindex[i]>=0 && x+xindex[i]<table.size() && y+yindex[i]<table[0].size() && !visited[x+xindex[i]][y+yindex[i]] && c[index+1]==table[x+xindex[i]][y+yindex[i]]){
			if(dfs(table,x+xindex[i],y+yindex[i],index+1))return true;
			visited[x+xindex[i]][y+yindex[i]]=false;
		}
	}
	return false;
}
int main(){
	int t;
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		vector<vector<char>>table(r,vector<char>(c));
		visited.assign(r,vector<bool>(c,false));
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				cin>>table[i][j];
			}
		}
		bool flag = false;
		for(int i = 0 ; i < r && !flag; i++){
			for(int j = 0 ; j < c && !flag; j++){
				visited.assign(r,vector<bool>(c,false));
				if(table[i][j]=='A' && dfs(table,i,j,0))
					flag = true;
			}
		}
		cout<<(flag?"YES":"NO")<<"\n";
	}
	return 0;
}