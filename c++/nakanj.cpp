#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int X[] = {2,1,-1,-2,-2,-1,1,2};
int Y[] = {1,2,2,1,-1,-2,-2,-1};
vector<vector<int> > dist (8,vector<int>(8,INT_MAX));

bool check(int x,int y){
	return (x>=0 && x<8 && y>=0 && y < 8);
}

int bfs(int xi,int yi, int xf,int yf){
	queue<pair<int,int> > q;
	q.push({xi,yi});
	dist.assign(8,vector<int>(8,INT_MAX));
	dist[xi][yi] = 0;
	while(!q.empty()){
		auto p = q.front();q.pop();
		int xp = p.first;
		int yp = p.second;
		//cout<<xp<<" "<<yp<<"\n";
		for(int i = 0 ; i < 8 ; i++){
			if(check(xp+X[i],yp+Y[i])){
				if(dist[xp][yp] + 1 < dist[xp+X[i]][yp+Y[i]]){
					dist[xp+X[i]][yp+Y[i]] = dist[xp][yp] + 1; 
					q.push({xp+X[i],yp+Y[i]});
				}
			}
		}
	}
	return dist[xf][yf];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<bfs((int)(a[0]-'a'),(int)(a[1]-'1'),(int)(b[0]-'a'),(int)(b[1]-'1'))<<"\n";
	}
	return 0;
}