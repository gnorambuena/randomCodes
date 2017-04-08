#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;

struct SegmentTree
{
	vector<int> st;
	int n;

	SegmentTree()
	{}
		
	SegmentTree(vector<int> &A) : n(A.size()-1)
	{
		st.resize(n<<2);
		construct(A,1,0,n-1);
	}

	void construct(vector<int> &A, int node, int l, int r)
	{
		if(l == r)
		{
			st[node] = A[l];
			return;
		}
		
		construct(A,node<<1,l,(l+r)/2);
		construct(A,node<<1|1,(l+r)/2+1,r);

		st[node] = max(st[node<<1],st[node<<1|1]);
	}

	void update(int i, int val)
	{
		update(1,0,n-1,i,val);
	}

	void update(int node, int l, int r, int i, int val)
	{
		if(i < l || r < i)
			return;
		
		if(l == r)
		{
			st[node] = val;
			return;
		}

		update(2*node,l,(l+r)/2,i,val);
		update(2*node+1,(l+r)/2+1,r,i,val);
		
		st[node] = max(st[node<<1],st[node<<1|1]);
	}

	int query(int i, int j)
	{
		return query(1,0,n-1,i,j);
	}

	int query(int node, int l, int r, int i, int j)
	{
		if(j < l || r < i)
			return INT_MIN;

		if(i <= l && j >= r)
			return st[node];
		
		return max(query(node<<1,l,(l+r)/2,i,j),query(node<<1|1,(l+r)/2+1,r,i,j));
	}
};

struct SparseTable
{
	int log2(int n)
	{
		int ans = 0;
		while(n >>= 1) ans++;
		return ans;
	}

	vector< vector<int> > ST;
	vector<int> L;

	SparseTable()
	{}
	
	SparseTable(vector<int> &parent, vector<int> &level)
	{
		int n = parent.size();
		ST.assign(n,vector<int>(log2(n)+1,-1));
		L = level;

		for(int i = 0; i < n; ++i)
			ST[i][0] = parent[i];

		for(int k = 1; (1<<k) < n; ++k)
			for(int i = 0; i < n; ++i)
				if(ST[i][k-1] != -1)
					ST[i][k] = ST[ST[i][k-1]][k-1];
	}

	int lev(int u, int level)
	{
		while(L[u] > level)
			u = ST[u][log2(L[u]-level)];
		return u;
	}

	int lca(int u, int v)
	{
		if(L[u] > L[v])
			swap(u,v);

		v = lev(v,L[u]);

		while(u != v)
		{
			int k = log2(L[u]);
			while(k > 0 && ST[u][k] == ST[v][k]) k--;
			u = ST[u][k];
			v = ST[v][k];
		}	

		return u;
	}
};

struct HeavyLight
{
	vector< vector<int> > G,C;
	vector<int> P,L,STS,CN,CI;
	vector<int> W;
	vector<SegmentTree> HL;
	SparseTable ST;
	int N;

	HeavyLight(vector< vector<int> > &graph, vector<int> &weight) : N(graph.size())
	{
		G = graph;
		W = weight;
		P.resize(N);
		L.assign(N,-1); L[0] = 0; P[0] = -1;
		STS.assign(N,1);

		dfs(0);
		ST = SparseTable(P,L);

		CI.assign(N,-1); CN.assign(N,-1);
		hld(0);

		HL.resize(C.size());
		for(int i = 0; i < C.size(); ++i)
		{
			vector<int> V(C[i].size());
			for(int j = 0; j < C[i].size(); ++j)
				V[j] = W[C[i][j]];
			HL[i] = SegmentTree(V);
		} 
	}

	void dfs(int u)
	{
		for(int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			if(L[v] == -1)
			{
				L[v] = L[u]+1;
				P[v] = u;
				dfs(v);
				STS[u] += STS[v];
			}
		}
	}

	void hld(int u)
	{
		static int chainNum = 0;

		if(CN[u] == -1)
		{
			C.pb(vector<int>());
			CN[u] = chainNum++;
			CI[u] = 0;
		}

		C[CN[u]].pb(u);

		int special = -1;
		int maxSize = -1;
		for(int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			if(CN[v] == -1 && STS[v] > maxSize)
			{
				maxSize = STS[v];
				special = v;
			}
		}

		if(special != -1)
		{
			CN[special] = CN[u];
			CI[special] = CI[u]+1;
			hld(special);
		}

		for(int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			if(CN[v] == -1)
				hld(v);
		}
	}

	void update(int u, int val)
	{
		HL[CN[u]].update(CI[u],val);
	}

	int query(int u, int v)
	{
		int A = ST.lca(u,v);
		int ans = -1;

		while(CN[u] != CN[A])
		{
			ans = max(ans,HL[CN[u]].query(0,CI[u]));
			u = P[C[CN[u]][0]];
		}
		ans = max(ans,HL[CN[u]].query(CI[A],CI[u]));

		while(CN[v] != CN[A])
		{
			ans = max(ans,HL[CN[v]].query(0,CI[v]));
			v = P[C[CN[v]][0]];
		}
		ans = max(ans,HL[CN[v]].query(CI[A],CI[v]));

		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int N; cin >> N;
		vector< vector<int> > graph(2*N-1,vector<int>());
		vector<int> weight(2*N-1,0);
		for(int i = 0; i < N-1; ++i)
		{
			int a,b; ll c; cin >> a >> b >> c;
			graph[--a].pb(N+i);
			graph[N+i].pb(--b);
			graph[b].pb(N+i);
			graph[N+i].pb(a);
			weight[N+i] = c;
		}

		HeavyLight HL(graph,weight);

		string s; cin >> s;
		while(s != "DONE")
		{
			if(s == "QUERY")
			{
				int a,b; cin >> a >> b;
				cout << HL.query(--a,--b) << '\n';
			}
			else
			{
				int i,ti; cin >> i >> ti;
				HL.update(N+i-1,ti);
			}
			cin >> s;
		}
	}
	return 0;
}	