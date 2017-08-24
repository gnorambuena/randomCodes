#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
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
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,g;
    while(cin>>n>>m>>g){
        if(n==0 && m == 0 && g ==0)
            break;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        vector<int>points(n,0);
        for(int k = 0; k < g ; k++){
            int i,j;
            char c;
            cin>>i>>c>>j;
            matrix[j][i]+=1;
            matrix[i][j]+=1;
            if(c=='<'){
                points[j] += 2;
            }else{
                points[i] += 1;
                points[j] += 1;
            }
        }

        int p = points[0];
        for(int i = 1; i < n ; i++){
            p+= (m-matrix[0][i])*2;
        }
        //cout<<p<<"\n";
        int k = 0;
        map<pair<int,int>,int>mm;
        int a = 0;
        //calcular la cantidad de partidos restantes
        for(int i = 1 ; i < n ; i++)
            for(int  j = i + 1 ; j < n ; j++){
                if(matrix[i][j] < m){
                   k++;
                   a += (m-matrix[i][j])*2;
                   mm[{i,j}] = mm.size()-1 + n;
                }
            }
        Dinic graph(n+k+2);
        bool sw = true;
        for(int i = 1 ; i < n ; i++){
            if(points[i] >= p)
                sw = false;
        }
        if(sw){
            for(int i = 1; i < n ; i++){
                graph.add_edge(i,n+k+1,p-1-points[i]);
                for(int  j = i + 1 ; j < n ; j++){
                    if(matrix[i][j] < m ){
                        //partidos a equipos
                        graph.add_edge(mm[{i,j}],i,2 * (m-matrix[i][j]));
                        graph.add_edge(mm[{i,j}],j,2 * (m-matrix[i][j]));
                        graph.add_edge(n+k,mm[{i,j}],2 * (m-matrix[i][j]));
                    }
                }
            }
            long long ans = graph.max_flow(n+k,n+k+1);
            //cout<<ans<<"\n";
            cout<<(ans==a?'Y':'N')<<"\n";
        }else{
            cout<<"N\n";
        }
    }
    return 0;
}
