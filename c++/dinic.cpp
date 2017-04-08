#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;
#define MAXN 100000
#define INF INT_MAX
class Dinic {
	long long n, m, head[MAXN], level[MAXN], s, t, work[MAXN];
	struct edge {
		long long v, c, f, nxt;
		edge() {}
		edge(long long v, long long c, long long f, long long nxt): v(v), c(c), f(f), nxt(nxt) {}
	} e[MAXN];
	bool _bfs() {
		static long long q[MAXN];
		memset(level, -1, sizeof(long long) * n);
		long long le = 0, ri = 0;
		q[ri++] = s;
		level[s] = 0;
		while(le < ri) {
			for(long long k = q[le++], i = head[k]; i != -1; i = e[i].nxt) {
				if(e[i].f < e[i].c && level[e[i].v] == -1) {
					level[e[i].v] = level[k] + 1;
					q[ri++] = e[i].v;
				}
			}
		}
		return (level[t] != -1);
	}
	long long _dfs(long long u, long long f) {
		if(u == t)
			return f;
		for(long long& i = work[u]; i != -1; i = e[i].nxt) {
			if(e[i].f < e[i].c && level[u] + 1 == level[e[i].v]) {
				long long minf = _dfs(e[i].v, min(f, e[i].c - e[i].f));
				if(minf > 0) {
					e[i].f += minf;
					e[i ^ 1].f -= minf;
					return minf;
				}
			}
		}
		return 0;
	}
public:
	void init(long long nn, long long src, long long dst) {
		n = nn;
		s = src;
		t = dst;
		m = 0;
		memset(head, -1, sizeof(long long) * n);
	}
	void addEdge(long long u, long long v, long long c, long long rc) {
		//assert(u < n);
		//assert(v < n);
		e[m] = edge(v, c, 0, head[u]);
		head[u] = m++;
		e[m] = edge(u, rc, 0, head[v]);
		head[v] = m++;
		//assert(m < MAXN);
	}
	long long maxFlow() {
		long long ret = 0;
		while(_bfs()) {
			memcpy(work, head, sizeof(long long) * n);
			while(true) {
				long long delta = _dfs(s, INF);
				if(delta == 0)
					break;
				ret += delta;
			}
		}
		return ret;
	}
};

int main(){
    long long V,E;
    long long a,b;
    //Acelerar I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Lectura vertices arista
    while(true)
    {
	    // Inicializacion mega-hermosa
	    //cerr<<V<<E<<endl;
	    cin >> V >> E;
	    if(V==0 && E==0)break;
	    Dinic G;
	    G.init(V+2,0,V+1);
	   // cerr<<"asd"<<endl;
	    //Lectura del grafo
	    //cerr<<"V= "<<V<<endl;
	    for(long long i = 0; i < V ; ++i)
	    {
	    	//cerr<<"i= "<<i<<endl;
	    	long long n;
	    	cin>>n;
	    	if(!n){
	    		G.addEdge(0,i+1,1,0);
	    	}
	    	else{
	    		G.addEdge(i+1,V+1,1,0);
	    	}
	    }
	    for(long long i = 0; i < E ;i++){
	            cin >> a >> b;
	            // Los -1 son por numerar desde 1.
	            G.addEdge(a,b,1,1);
	    }
	    // Respuesta hermosa
	    cout << G.maxFlow() << endl;
	    //G.clear();
    }
    return 0;
}