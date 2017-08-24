#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef pair<int,int> ii;

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
	int n;
	while (cin >> n){
		map<int, int> mapa;
	
		vector<vector<char> > mat(n+5, vector<char>(n+5,0));
		vector<vector<int> > mathor(n+5, vector<int>(n+5,0));
		vector<vector<int> > matver(n+5, vector<int>(n+5,0));
		int cont = 0;
		int contmapa = 0;

		for (int i = 1; i <= n; i++){
			string s;
			cin >> s;
			for (int j = 1; j <= n; j++){
				mat[i][j] = s[j-1];
			}
		}
		for (int i = 0; i <= n+1; i++){
			mat[i][0] = 'X';
			mat[0][i] = 'X';
		}
		for (int i = 0; i <= n+1; i++){
			mat[i][n+1] = 'X';
			mat[n+1][i] = 'X';
		}

/*

		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

*/

		
		
		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				if (mat[i][j] != 'X'){
					mathor[i][j] = cont;
					if (mapa[cont] == 0){
						contmapa++;
						mapa[cont] = contmapa;
					}
				}
				else cont++;
			}
		}

		
		int cantizq = contmapa;
		
		cont++;

		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				if (mat[j][i] != 'X'){
					matver[j][i] = cont;
					if (mapa[cont] == 0){
						contmapa++;
						mapa[cont] = contmapa;
					}
				}
				else cont++;
			}
		}		
		
		int cantder = contmapa - cantizq;
/*
		for (ii a : mapa){
			cout << a.first << " " << a.second << endl;
		}


		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				cout << mathor[i][j] << " ";
			}
			cout << endl;
		}
	
		cout << endl;

		
		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				cout << matver[i][j] << " ";
			}
			cout << endl;
		}

		cout << "hola" << endl;

*/

		Dinic flujo(contmapa+3);

		//cout << "cantizq es " << cantizq << endl;
		//cout << "cantder es " << contmapa << endl;
		
		for (int i = 1; i <= cantizq; i++)
			flujo.add_edge(contmapa+1, i, 1);
		for (int i = cantizq+1; i <= contmapa; i++)
			flujo.add_edge(i, contmapa+2, 1);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (mathor[i][j] != 0 && matver[i][j] != 0){
					flujo.add_edge(mapa[mathor[i][j]], mapa[matver[i][j]], 1);
					//flujo.add_edge(mapa[matver[i][j]], mapa[mathor[i][j]], 1);
				}
			}
		}

		cout << flujo.max_flow(contmapa+1, contmapa+2) << endl;

	}

}