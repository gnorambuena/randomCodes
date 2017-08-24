#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};
vector<vector<char> > maze;

vector<pair<int,int>>entryExit;
bool checkEntryExit(){
	int n = maze.size();
	int m = maze[0].size();
	int entrys = 0;
	entryExit.clear();
	vector<vector<bool> > visited(n,vector<bool>(m,0));
	//arriba y abajo
	for(int j = 0 ; j < m ; j++){
		if(maze[0][j]=='.' && !visited[0][j]){
			entrys++;
			entryExit.push_back({0,j});
			visited[0][j]= true;
		}
		if(maze[n-1][j]=='.' && !visited[n-1][j]){
			entrys++;
			entryExit.push_back({n-1,j});
			visited[n-1][j]= true;
		}
	}
	//derecha y izquierda
	for(int i = 0 ; i < n ; i++){
		if(maze[i][m-1]=='.' && !visited[i][m-1]){
			entrys++;
			entryExit.push_back({i,m-1});
			visited[i][m-1] = true;
		}
		if(maze[i][0]=='.' && !visited[i][0]){
			entrys++;
			entryExit.push_back({i,0});
			visited[i][0] = true;
		}
	}
	//cout<<entrys<<"\n";
	return entrys==2;
}

bool check(int x,int y){
	return (x>=0 && x<maze.size() && y>=0 && y < maze[0].size() && maze[x][y]=='.');
}

vector<vector<bool> > visit;
bool bfs(){
	queue<pair<int,int> > q;
	if(!checkEntryExit())return false;
	q.push(entryExit[0]);
	visit.assign(maze.size(),vector<bool>(maze[0].size(),false));
	visit[entryExit[0].first][entryExit[0].second] = true;
	while(!q.empty()){
		auto p = q.front();q.pop();
		int xp = p.first;
		int yp = p.second;
		//cout<<"queue :"<<xp<<" "<<yp<<"\n";
		for(int i = 0 ; i < 4 ; i++){
			if(check(xp+X[i],yp+Y[i]) && !visit[xp+X[i]][yp+Y[i]]){
				visit[xp+X[i]][yp+Y[i]] = true;
				q.push({xp+X[i],yp+Y[i]});
			}
		}
	}
	return visit[entryExit[1].first][entryExit[1].second];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		maze.assign(n,vector<char>(m));
		for(auto &a : maze)
			for(auto &c : a)
				cin>>c;
		//cout<<checkEntryExit()<<"\n";
		cout<<(bfs()?"valid\n":"invalid\n");
		//cout<<entryExit[0].first<<" "<<entryExit[0].second<<"\n";
		//cout<<entryExit[1].first<<" "<<entryExit[1].second<<"\n";
	}
	return 0;
}