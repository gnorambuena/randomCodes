#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> newgraph(vector<string>&g){
	vector<vector<int>> v(g[0].size()*4+2+1,vector<int>(g[0].size()*4+1,0));
	//cout<<g[0].size()*4+3<<" "<<g[0].size()*4+1<<"\n";
	for(int i = 0; i < v.size();i++){
		v[i][0] = 2;
		v[i][v[0].size()-1] = 2;
	}
	for(int j = 0; j < v[0].size() ;j++){
		v[0][j] = 2;
		v[v.size()-1][j] = 2;
	}
	for(int i = 1; i <= g.size() ; i++)
		for(int j = 1; j <= g[0].size() ; j++){
			if(i%2==1){
				if(g[i-1][j-1]=='V'){
					for(int k = 2*i-2; k <= 2*i+2 && k < v[0].size() ; k++){
						//cout<<4*j-2<<" "<<k<<"\n";
						v[4*j-2][k] = 2;
					}
				}else{
					for(int k = 2*(2*j-1)-2; k <= 2*(2*j-1)+2 && k < v.size() ; k++){
						//cout<<k<<" "<<2*i<<"\n";						
						v[k][2*i] = 2;
					}
				}
			}else{
				if(g[i-1][j-1]=='V'){
					for(int k = 2*i-2; k <= 2*i+2 && k < v[0].size() ; k++){
						//cout<<4*j<<" "<<k<<"\n";
						v[4*j][k] = 2;
					}
				}else{
					for(int k = 2*(2*j)-2; k <= 2*(2*j)+2&& k < v.size() ;k++){
						//cout<<k<<" "<<2*i<<"\n";
						v[k][2*i] = 2;
					}
				}
			}	
		}
	/*for(int i = 0; i < v.size() ; i++){
		for(int j = 0; j < v[0].size();j++)
			cout<<v[i][j]<<" ";
		cout<<"\n";
	}*/
	return v;
}

int X[] = {1,0,-1,0}, Y[] = {0,1,0,-1};

bool check(int x,int y,vector<vector<int>>&g){
	return x>=0 && y>=0 && x<=g.size() && y<=g[0].size();
}
void bfs(int x,int y,vector<vector<int>>&g){
	queue<pair<int,int>>q;
	q.push({x,y});
	g[x][y] = 1;
	while(!q.empty()){
		auto p = q.front();q.pop();
		auto curx = p.first,cury = p.second;
		for(int i = 0 ; i < 4; i++){
			if(check(curx+X[i],cury+Y[i],g) && g[curx+X[i]][cury+Y[i]]==0){
				q.push({curx+X[i],cury+Y[i]});
				g[curx+X[i]][cury+Y[i]] = 1;
			}
		}
	}
}
int main(){
	int n;
	
	while(cin>>n){
		vector<string>gp(2*n-1);
		for(auto &v:gp)
			cin>>v;
		auto g = newgraph(gp);
		int ans = 0;
		for(int i = 0; i< g.size() ;i++){
			for(int j = 0; j < g[0].size();j++){
				if(g[i][j]==0){
					ans++;
					bfs(i,j,g);
				}
			}
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}