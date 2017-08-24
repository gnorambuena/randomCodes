#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
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
    	edge b = {u, (int)g[u].size(), 0, cap}; //Poner cap en vez de 0 si la arista es bidireccional
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
    int n,m;
    cin>>n>>m;
    Dinic graph(n+1);
    for(int i = 0; i < m ; i++){
        long long a,b,c;
        cin>>a>>b>>c;
        graph.add_edge(a,b,c);
    }
    cout<<graph.max_flow(1,n)<<"\n";
    return 0;
}