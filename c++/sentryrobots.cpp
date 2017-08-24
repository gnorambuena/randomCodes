#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define pb push_back

typedef long long ll;

class Dinic {
	struct edge {
    	int to, rev;
    	ll f, cap;
	};
 
	vector<vector<edge>> g;
	vector<ll> dist;
	vector<int> q, work;
	int n, sink;
 
	bool bfs(int start, int finish) {
    	dist.assign(n, -1);
    	dist[start] = 0;
    	int head = 0, tail = 0;
    	q[tail++] = start;
    	while (head < tail) {
        	int u = q[head++];
        	for (const edge &e : g[u]) {
            	int v = e.to;
            	if (dist[v] == -1 and e.f < e.cap) {
                	dist[v] = dist[u] + 1;
                	q[tail++] = v;
            	}
        	}
    	}
    	return dist[finish] != -1;
	}
 
	ll dfs(int u, ll f) {
    	if (u == sink)
        	return f;
    	for (int &i = work[u]; i < (int)g[u].size(); ++i) {
        	edge &e = g[u][i];
        	int v = e.to;
        	if (e.cap <= e.f or dist[v] != dist[u] + 1)
            	continue;
        	ll df = dfs(v, min(f, e.cap - e.f));
        	if (df > 0) {
            	e.f += df;
            	g[v][e.rev].f -= df;
            	return df;
        	}
    	}
    	return 0;
	}
 
public:
	Dinic(int n) {
    	this->n = n;
    	g.resize(n);
    	dist.resize(n);
    	q.resize(n);
	}
 
	void add_edge(int u, int v, ll cap) {
    	edge a = {v, (int)g[v].size(), 0, cap};
    	edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
    	g[u].pb(a);
    	g[v].pb(b);
	}
 
	ll max_flow(int source, int dest) {
    	sink = dest;
    	ll ans = 0;
    	while (bfs(source, dest)) {
        	work.assign(n, 0);
        	while (ll delta = dfs(source, LLONG_MAX))
            	ans += delta;
    	}
    	return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int y,x;
		cin>>x>>y;
		vector<vector<int>>grid(128,vector<int>(128,0));
		int p;
		cin>>p;
		for(int i = 0; i < p; i++){
			int px,py;
			cin>>px>>py;
			grid[px][py] = 1;
		}
		int w;
		cin>>w;
		for(int i = 0; i < w; i++){
			int wx,wy;
			cin>>wx>>wy;
			grid[wx][wy] = 2;
		}

		vector<vector<int>>row(128,vector<int>(128)),col(x+1,vector<int>(128));
		int contr = 0, contc = 0;
		for(int i = 1; i <= x; i++){
			for(int j = 1 ; j <= y; j++ ){
				if(j==1 || (grid[i][j]!=2 && grid[i][j-1] == 2 )){
					contr++;
				}
				row[i][j] = contr;
			}
		}

		for(int j = 1; j <= y ; j++)
			for(int i = 1; i <= x ; i++){
				if(i==1 || (grid[i][j]!=2 && grid[i-1][j] == 2)){
					contc++;
				}
				col[i][j] = contc;
			}

		Dinic D(contc+contr+5);

		for(int i = 1 ; i <= x ; i++)
			for(int j = 1 ; j<= y ; j++)
				if(grid[i][j]==1)
					D.add_edge(row[i][j]-1,col[i][j]+contr-1,1);

		for(int i = 1 ; i <= contr ; i++)
			D.add_edge(contc+contr+1,i-1,1);
		for(int j = 1 ; j <= contc ; j++)
			D.add_edge(j-1+contr,contc+contr+2,1);

		cout<<D.max_flow(contc+contr+1,contc+contr+2)<<"\n";
	}
	return 0;
}