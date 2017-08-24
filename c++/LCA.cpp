#include <iostream>
#include <vector>
using namespace std;
vector<int>L;
vector<bool>visited;
int log2(int index){
	int targetlevel = 0;
	while (index >>= 1) ++targetlevel;
	return targetlevel;
}
int query(vector<vector<int> > &P, int p, int q)
  {
    int tmp, log, i;
    int N = P.size();
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;
    log = log2(L[p]);
   
    for (i = log; i >= 0; i--)
	    if (L[p] - (1 << i) >= L[q])
	        p = P[p][i];

	if (p == q)
        return p;
    
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
   
    return P[p][0];
  }
void dfs(int node,int depth,vector<vector<int> > &graph){
	for(int i = 0 ; i < graph[node].size() ; i++){
		int u = graph[node][i];
		if(!visited[u])
		{
			visited[u]=true;
			L[u]=depth+1;
			dfs(u,depth+1,graph);
		}
	}
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i = 1 ; i <= t ; i++){
		int N;
		cin>>N;
		vector<int> parent(N,0);
		visited.assign(N,false);
		L.assign(N,0);
		vector<vector<int> >graph(N);
		vector<vector<int> > M(N,vector<int>(log2(N)+1,0));
		//cerr<<M[0].size()<<endl;
		int root=0;
		for(int j = 0 ; j < N ; j++){
			int M;
			cin>>M;
			for(int k = 0 ; k < M ; k++){
				int a;
				cin>>a;
				graph[j].push_back(--a);
				parent[a]=j;
			}
		}
		visited[0]=true;
		dfs(0,0,graph);
		//for(int i = 0 ; i < N ; i++)
			//cerr<<"parent: "<<parent[i]+1<<" node: "<<i+1<<endl;
		//SparseTable ST(graph,root);
		for(int i = 0 ; i < N ; i++){
			M[i][0] = parent[i];
			//cerr<<i+1<<" "<<L[i]<<endl;
		}
		//cerr<<endl;
		for(int k = 1 ; (1<<k) < N ; k++){
			for(int i = 0 ; i < N ; i++){
				//cerr<<i<<" "<<(1<<k)<<endl;
				//cerr<<M[i][k-1]<<endl;
				M[i][k] = M[ M[i][k-1] ] [k-1];
				//cerr<<i+1<<" "<<(1<<k)<<" "<<M[i][k]+1<<endl;
			}
			//cerr<<"asd\n";
		}
		//cerr<<"asd\n";
		int Q;
		cin>>Q;
		cout<<"Case "<<i<<":\n";
		for(int j = 0 ; j < Q ; j++){
			int a,b;
			cin>>a>>b;
			cout<<query(M,--a,--b)+1<<"\n";
		}
	}
}