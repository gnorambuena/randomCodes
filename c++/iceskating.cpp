#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<bool> > visited;
vector<vector<bool>> isSlide;

int bfs(vector<pair<int,int>>&points){
	int n = 0;
	for(int i = 0 ; i < points.size() ; i++){
		if(visited[points[i].first][points[i].second])
			continue;
		else{
			queue<pair<int,int> > q ; q.push(points[i]);
			visited[points[i].first][points[i].second] = true;
			while(!q.empty()){
				auto t = q.front(); q.pop();
				for(int i = 0 ; i < visited.size() ; i++){
					if(isSlide[i][t.second] && !visited[i][t.second]){
						q.push({i,t.second});
					}
					visited[i][t.second] = true;
				}

				for(int j = 0 ; j < visited[t.first].size() ; j++){
					if(isSlide[t.first][j] && !visited[t.first][j]){
						q.push({t.first,j});
					}
					visited[t.first][j] = true;
				}
			}
			n++;
		}
	}
	return n;
}

int main(){
	visited.assign(1010,vector<bool>(1010,0));
	isSlide.assign(1010,vector<bool>(1010,0));
	vector<pair<int,int>>points;
	int n;
	cin>>n;
	for(int i = 0; i < n ; i++){
		int a,b;
		cin>>a>>b;
		points.push_back({a,b});
		isSlide[a][b] = true;
	}
	cout<<bfs(points)-1<<"\n";
	return 0;
}