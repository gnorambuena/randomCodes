#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

vector<vector<char> > forest;

vector<vector<int> > dist;

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};

bool check(int x,int y){
	return x>=0 && x<forest.size() && y>=0 && y<forest[0].size() && forest[x][y]!='T';
}

int numBreeders(int x, int y){
	if(forest[x][y]!='T' && forest[x][y]!='E' && forest[x][y]!='S')
		return forest[x][y]-'0';
	return 0;
}

pair<int,int> entry;
pair<int,int> salida;

void findEntryExit(){
	for(int i = 0 ; i < forest.size() ; i++){
		for(int j = 0 ; j < forest[0].size() ; j++){
			if(forest[i][j]=='E'){
				salida = {i,j};
			}
			if(forest[i][j]=='S'){
				entry = {i,j};
				//cout<<"asdasd "<<i<<" "<<j<<"\n";
			}
		}
	}
}

void bfs(){
	queue<pair<int,int> > q;
	findEntryExit();
	q.push(salida);
	dist.assign(forest.size(),vector<int>(forest[0].size(),INT_MAX));
	dist[salida.first][salida.second] = 0;
	while(!q.empty()){
		auto p = q.front();q.pop();
		int xp = p.first;
		int yp = p.second;
		//cout<<xp<<" "<<yp<<"\n";
		for(int i = 0 ; i < 4 ; i++){
			if(check(xp+X[i],yp+Y[i])){
				if(dist[xp][yp] + 1 < dist[xp+X[i]][yp+Y[i]]){
					dist[xp+X[i]][yp+Y[i]] = dist[xp][yp] + 1; 
					q.push({xp+X[i],yp+Y[i]});
				}
			}
		}
	}
}

int ans(){
	bfs();
	int distToExit = dist[entry.first][entry.second];
	//cout<<entry.first<<" "<<entry.second<<"\n";
	//cout<<distToExit<<"\n";
	int res = 0;
	for(int i = 0 ; i < forest.size() ; i++){
		for(int j = 0 ; j < forest[0].size() ; j++){
			if(dist[i][j] <= distToExit){
				//cout<<i<<" "<<j<<"\n";
				res+=numBreeders(i,j);
			}
		}
	}
	return res;
}
int main(){
	int r,c;
	cin>>r>>c;
	forest.assign(r,vector<char>(c));
	for(auto &a:forest)
		for(auto &c:a)
			cin>>c;
	cout<<ans()<<"\n";
	return 0;
}