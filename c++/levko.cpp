#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <iterator>
#define PRINT(X) copy(X.begin(),X.end(),ostream_iterator<int>(cout," "));cout<<endl
using namespace std;

typedef pair<long long,long long> pii;
const long long INF = 1e18;
vector<vector<long long> >dist;
vector<vector<pii > > edges;


void Dijkstra(int s,int num){
	priority_queue<pii,vector<pii >, greater<pii > > pq;
	dist[num].assign(edges.size(),INF);
	dist[num][s]=0;
	pq.push(make_pair(dist[num][s],s));
	while(!pq.empty()){
		//nodo fuente
		int u=pq.top().second; long long d = pq.top().first ;pq.pop();

		if(dist[num][u] != d)
			continue;

		for(int i=0;i<edges[u].size();i++){

			int v=edges[u][i].first;//nodo
			if(dist[num][v]>dist[num][u]+edges[u][i].second){
				dist[num][v]=dist[num][u]+edges[u][i].second;
				pq.push(make_pair(dist[num][v],v));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n,m,k,s1,s2,f;
	cin>>n>>m>>k>>s1>>s2>>f;
	vector<long long>settedpath;
	edges.resize(n+1); dist.resize(2,vector<long long>(n+1));
	for(int i = 0 ; i < m ; i++){
		pii p;long long a;
		cin>>a>>p.first>>p.second;
		edges[a].push_back(p);

	}
	vector<vector<pair<pii,pii> > >mod(n+1);
	for(int i=0; i < k ; i++){
		long long a,b,l,r;
		cin>>a>>b>>l>>r;
		edges[a].push_back(make_pair(b,r));
		pii p1=make_pair(b,edges[a].size()-1);
		pii p2=make_pair(l,r);
		mod[a].push_back(make_pair(p1,p2));
	}

	Dijkstra(s1,0);
	Dijkstra(s2,1);
	for(int i = 0 ; i < mod.size() ;i++){
		for(int j = 0 ; j < mod[i].size();j++){
			pair<pii,pii> p = mod[i][j];
			long long a=i,b=p.first.first,index=p.first.second,l=p.second.first,r=p.second.second;
			if(dist[0][a]<=dist[1][a]){
				edges[a][index]=make_pair(b,l);
				settedpath.push_back(l);
				Dijkstra(s1,0);
				Dijkstra(s2,1);
			} 
			else{
				settedpath.push_back(r);
			}
		}
	}
	if(dist[0][f]<dist[1][f]){
		cout<<"WIN"<<endl;
		PRINT(settedpath);
	}
	else if(dist[0][f]==dist[1][f]){
		cout<<"DRAW"<<endl;
		PRINT(settedpath);
	}
	else{
		cout<<"LOSE"<<endl;
		PRINT(settedpath);
	}
	return 0;
}