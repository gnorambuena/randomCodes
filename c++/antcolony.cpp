#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<long long>dist;
long long log2(long long index){
	long long targetlevel = 0;
	while (index >>= 1) ++targetlevel;
	return targetlevel;
}
struct SparseTable{
	vector <long long> E,F,D;
	vector <vector<long long> > graph,M;
	vector<bool>visited;
	long long root;
	SparseTable(vector<vector<long long> > &g, long long r){
		graph = g;
		root = r;
		F.assign(graph.size(),-1);
		visited.assign(graph.size(),false);
		visited[root]=true;
		dfs(r,0);
		M = vector<vector<long long> >(E.size()+2,vector<long long>(log2( E.size() )+2 , 0));
		preprocess();
	}
	void dfs(long long root,long long depth){
		E.push_back(root);
		D.push_back(depth);
		if(F[root]==-1)
			F[root]=E.size()-1;
		for(long long i = 0 ; i < graph[root].size() ; i++){
			long long node = graph[root][i];
			if(!visited[node]){
				visited[node]=true;
				dfs(node,depth+1);
				E.push_back(root);
				D.push_back(depth);
			}
		}
	}
	void preprocess(){ 
	    long long i, j, N = M.size()-1;       
	    for (i = 0; i < N; i++)
	        M[i][0] = i;         
	    for (j = 1; 1 << j < N; j++)            
	        for (i = 0; i + (1 << j) - 1 <= N; i++)           
	                if (D[M[i][j - 1]] < D[M[i + (1 << (j - 1))][j - 1]])           
	                	M[i][j] = M[i][j - 1];               
	           		else                
	                	M[i][j] = M[i + (1 << (j - 1))][j - 1]; 
	}
	long long RMQ(long long i , long long j){
		long long k=log2(j-i+1);
		if( D[M[i][k]] <= D[ M[j-(1<<k)+1][k] ] )
			return M[i][k];
		return M[j-(1<<k)+1][k];
	}
	long long LCA(long long u , long long v){
		if(F[u]<F[v])
			return E[RMQ(F[u],F[v])];
		return E[RMQ(F[v],F[u])];
	}
};
void dijkstra(vector<vector<pair<long long,long long>>> &g,long long start){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> > , greater<pair<long long,long long> > >q;
	q.push({0,start});
	dist[start]=0;
	while(!q.empty()){
		long long priority = q.top().first, u = q.top().second;
		q.pop();
		if(priority!=dist[u])continue;
		for(pair<long long,long long> p : g[u]){
			long long v = p.first, w= p.second;
			if(dist[u]+w < dist[v]){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	long long n;
	while(cin>>n && n!=0){
		vector<vector<long long> > graph(n);
		vector<vector<pair<long long,long long>>> wgraph(n);
		for(long long i = 1 ; i < n ; i++){
			long long a,l;
			cin>>a>>l;
			graph[i].push_back(a);
			graph[a].push_back(i);
			wgraph[i].push_back(make_pair(a,l));
			wgraph[a].push_back(make_pair(i,l));
		}
		SparseTable ST(graph,0);
		dist.assign(n,LLONG_MAX);
		dijkstra(wgraph,0);
		long long q;
		cin>>q;
		for(long long i = 0 ; i < q ; i++){
			long long s,t;
			cin>>s>>t;
			long long lca = ST.LCA(s,t);
			cout<<dist[s]+dist[t]-2*dist[lca];
			if(i+1!=q)cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}