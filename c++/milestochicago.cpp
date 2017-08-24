#include <bits/stdc++.h>
using namespace std;

typedef pair<long double, int> ii;

int n, m;

vector<vector<long double> > adj;

vector<long double> d;
vector<int> visited;

void dijkstra(int nodo){
	d.assign(n+5, 0.0);
	visited.assign(n+5, 0);
	priority_queue<ii, vector<ii> > cola;

	cola.push(ii(0,nodo));
	d[nodo] = 1.0;
	
	while (!cola.empty()){
		ii u = cola.top(); cola.pop();
		int Actual = u.second;
		visited[Actual] = 1;
		for (int i = 1; i <= n; i++){
			int nodoVecino = i;
			long double pesoVecino = adj[Actual][nodoVecino];
			if (!visited[nodoVecino] && d[Actual] * pesoVecino > d[nodoVecino]) {
				d[nodoVecino] = d[Actual] * pesoVecino;
				cola.push(ii(d[nodoVecino], nodoVecino));
			}
		}
	}
}


int main(){
	cin >> n;
	while (n != 0){
		cin >> m;
		adj.assign(n+5, vector<long double>(n+5, 0));

		for (int i = 0; i < m; i++){
			int a, b, p;
			cin >> a >> b >> p;
			adj[a][b] = p/100.0;
			adj[b][a] = p/100.0;
			//cout << adj[a][b] << endl;
		}

		dijkstra(1);

		//cout << d[n] << endl;
		cout << setprecision(6) << fixed;
		cout << d[n] * 100 << " percent"<< endl;
		cin >> n;
	}

	return 0;
}