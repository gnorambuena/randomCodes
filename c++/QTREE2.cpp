#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int>L;
vector<bool>visited;
vector<int>dist;
vector<int> parent;
int mxnode;
int mxdist;
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
int kth(vector<vector<int> > &P, int p, int q,int k,int lca){
     int a = lca ;
     int d;
    if( a == p ){
        d = L[q] - L[p] + 1 ;
        swap(p,q); // ans lies on the q side
        k = d - k + 1 ;
    }
    else if( a == q ) ; // do nothing as ans lies on p side
    else {
        if( k > L[p] - L[a] + 1 ) { // if k lies form p to lca + lca to ... means ans is on the q side so substact the k from p to lca dist
            d = L[p] + L[q] - 2 * L[a] + 1 ;
            k = d - k + 1 ;
            swap(p,q);
        }
        else ; // do nothing as k lies from p to under the lca means it is in p side
    }
    int lg ; for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
    k--;
    for( int i = lg ; i >= 0 ; i-- ){
        if( (1 << i) <= k ){
            p = P[p][i];
            k -= ( 1 << i );
        }
    }
    return p;
}
void dfs(int node,int depth,vector<vector<pair<int,int> > > &graph){
	for(int i = 0 ; i < graph[node].size() ; i++){
		int u = graph[node][i].first;
		if(!visited[u])
		{
			visited[u]=true;
			L[u]=depth+1;
			parent[u]=node;
			dist[u]=dist[node]+graph[node][i].second;
			if(L[u]>mxdist){
				mxdist=L[u];
				mxnode= u;
			}
			dfs(u,depth+1,graph);
		}
	}
}
int findroot(vector<vector<pair<int,int> > > &graph,int N){
	visited.assign(N,false);
	dist.assign(N,-1);
	parent.assign(N,0);
	L.assign(N,0);
	visited[0]=true;
	dist[0]=0;
	mxdist=-1;
	mxnode=-1;
	dfs(0,0,graph);
	int aux = mxnode;

	visited.assign(N,false);
	dist.assign(N,-1);
	parent.assign(N,0);
	L.assign(N,0);
	visited[aux]=true;
	dist[aux]=0;
	dfs(aux,0,graph);
	int m = L[mxnode]/2;
	int center = mxnode;
	while(m>0){
		center = parent[center];
		m--;
	}

	return center;
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;

	for(int i = 1 ; i <= t ; i++){
		int N;
		cin>>N;

		visited.assign(N,false);
		dist.assign(N,-1);
		parent.assign(N,0);
		L.assign(N,0);
		vector<vector< pair<int,int> > >graph(N);
		vector<vector<int> > M(N,vector<int>(log2(N)+1,0));

		for(int j = 0 ; j < N-1 ; j++){
			int a,b,c;
			cin>>a>>b>>c;
			graph[--a].push_back(make_pair(--b,c));
			graph[b].push_back(make_pair(a,c));
		}

		int root=findroot(graph,N);

		visited.assign(N,false);
		dist.assign(N,-1);
		parent.assign(N,0);
		L.assign(N,0);
		visited[root]=true;
		dist[root]=0;

		dfs(root,0,graph);

		for(int j = 0 ; j < N ; j++)
			M[j][0] = parent[j];
	
		for(int k = 1 ; (1<<k) < N ; k++)
			for(int j = 0 ; j < N ; j++)
				M[j][k] = M[ M[j][k-1] ] [k-1];
			
		string s;
		cin>>s;
		while(s!="DONE"){
			int a,b;
			cin>>a>>b;
			int lca = query(M,--a,--b);
			if(s=="DIST"){
				cout<<(dist[a]-dist[lca])+(dist[b]-dist[lca])<<"\n";
			}
			else if(s=="KTH"){
				int k;
				cin>>k;
				if(a!=b)
					cout<<kth(M,a,b,k,lca)+1<<"\n";
				else 
					cout<<a+1<<endl;
			}
			cin>>s;
		}
		cout<<"\n";
	}
	return 0;
}