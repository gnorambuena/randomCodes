#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

vector<bool>visited;
vector<int>dist;

void bfs(vector<vector<int> >&graph){
	queue<int>q;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int v: graph[node]){
			if(!visited[v]){
				visited[v]=true;
				dist[v]=dist[node]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int A,N;
	cin>>A>>N;
	visited.assign(N+A+1,false);
	dist.assign(N+A+1,0);
	vector<vector<int> > graph(N+A+1);
	for( int i = N+1; i < N+A+1 ; i++){
		int C;
		cin>>C;
		for(int j = 0 ; j < C ; j++){
			int P;
			cin>>P;
			graph[i].push_back(P);
			graph[P].push_back(i);
		}
	}
	bfs(graph);
	int D=0;
	int M=-1;
	int S=0;
	for(int i = 1 ; i <= N ; i++){
		if(visited[i]){
			D++;
			M=max(M,dist[i]/2);
			S+=dist[i]/2;
		}
	}
	cout<<D<<" "<<M<<" "<<S<<endl;
	return 0;
}