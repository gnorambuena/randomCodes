#include <iostream>
#include <vector>
using namespace std;

int log2(int index){
	int targetlevel = 0;
	while (index >>= 1) ++targetlevel;
	return targetlevel;
}
struct SparseTable{
	vector <int> E,F,D;
	vector <vector<int> > graph,M;
	vector<bool>visited;
	int root;
	SparseTable(vector<vector<int> > &g, int r){
		graph = g;
		root = r;
		F.assign(graph.size(),-1);
		visited.assign(graph.size(),false);
		visited[root]=true;
		dfs(r,0);
		M = vector<vector<int> >(E.size()+2,vector<int>(log2( E.size() )+2 , 0));
		preprocess();
	}
	void dfs(int root,int depth){
		E.push_back(root);
		D.push_back(depth);
		if(F[root]==-1)
			F[root]=E.size()-1;
		for(int i = 0 ; i < graph[root].size() ; i++){
			int node = graph[root][i];
			if(!visited[node]){
				visited[node]=true;
				dfs(node,depth+1);
				E.push_back(root);
				D.push_back(depth);
			}
		}
	}
	void preprocess(){ 
	    int i, j, N = M.size()-1;       
	    for (i = 0; i < N; i++)
	        M[i][0] = i;         
	    for (j = 1; 1 << j < N; j++)            
	        for (i = 0; i + (1 << j) - 1 <= N; i++)           
	                if (D[M[i][j - 1]] < D[M[i + (1 << (j - 1))][j - 1]])           
	                	M[i][j] = M[i][j - 1];               
	           		else                
	                	M[i][j] = M[i + (1 << (j - 1))][j - 1]; 
	}
	int RMQ(int i , int j){
		int k=log2(j-i+1);
		if( D[M[i][k]] <= D[ M[j-(1<<k)+1][k] ] )
			return M[i][k];
		return M[j-(1<<k)+1][k];
	}
	int LCA(int u , int v){
		if(F[u]<F[v])
			return E[RMQ(F[u],F[v])];
		return E[RMQ(F[v],F[u])];
	}
};

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i = 1 ; i <= t ; i++){
		int N;
		cin>>N;
		vector<vector<int> > graph(N);
		int root=0;
		for(int j = 0 ; j < N ; j++){
			int M;
			cin>>M;
			for(int k = 0 ; k < M ; k++){
				int a;
				cin>>a;
				a--;
				graph[j].push_back(a);
			}
		}
		SparseTable ST(graph,root);
		int Q;
		cin>>Q;
		cout<<"Case "<<i<<":\n";
		for(int j = 0 ; j < Q ; j++){
			int a,b;
			cin>>a>>b;
			cout<<ST.LCA(a-1,b-1)+1<<"\n";
		}
	}
	return 0;
}