#include <iostream>
#include <vector>
#include <map>
#include <climits>
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
    int t;
    cin>>t;
    for(int l = 1; l <= t ; l++){
        int n,d;
        cin>>n>>d;
        map<pair<int,int>,int>m;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= d; j++){
                m[{i,j}] = m.size();
                //cout<<m[{i,j}]<<"\n";
            }
        }
        int q;
        cin>>q;
        vector<vector<int>>flights(q,vector<int>(5,0));
        for(auto &v:flights)
            for(auto &e:v)
                cin>>e;
        vector<int>z(n);
        int total = 0;
        for(auto &el:z){
            cin>>el;
            total+=el;
        }
        //cout<<total<<"\n";
        int left = 0;
        int right = 100000;
        int mid = right/2;
        int S = m[{1000,1000}] = m.size();//source
        int T = m[{1500,1500}] = m.size();//dest
        for(int k = 0; k < 32 ; k++){
            Dinic graph(m.size()+1);
            //cout<<mid<<"\n";
            graph.add_edge(m[{n,d}],T,INT_MAX);
            for(int i = 1; i <= n ; i++){
                graph.add_edge(S,m[{i,0}],z[i-1]);
                for(int j = 0; j+1 <= d;j++){
                    graph.add_edge(m[{i,j}],m[{i,j+1}],INT_MAX);
                }
            }
            for(int i = 0 ; i < flights.size() ; i++){
                auto curflight = flights[i];
                if(curflight[3]<=mid){
                    graph.add_edge(m[{curflight[0],curflight[4]}],m[{curflight[1],curflight[4]+1}],curflight[2]);
                }
            }
            long long res = graph.max_flow(S,T);
            //cout<<"res= "<<res<<"\n";
            if(res!=total && mid == 100000){
                mid = 1000000;
                break;
            }
            if(res==(long long)total){
                right = mid;
            }else{
                left = mid+1;
            }
            mid = (left+right)/2;
        }
        cout<<"Case #"<<l<<": ";
        if(mid>100000){
            cout<<"Impossible\n";
        }else{
            cout<<mid<<"\n";
        }
    }
    return 0;
}