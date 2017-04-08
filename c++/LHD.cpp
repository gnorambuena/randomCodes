#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
#define pb push_back
#define eb emplace_back
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/__gcd(x,y)*(y)
#define bits(x) __builtin_popcount(x)
#define SORT(X) sort(X.begin(),X.end())
#define PRINT(X) copy(X.begin(),X.end(),ostream_iterator<int>(cout," "));cout<<endl
#define MAX_N 100000
using namespace std;

typedef long long ll;   
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const double pi = 3.14159265358979323846;

vector< vector<int> > edges;
vector<int>L,E,H;
vector<bool> visited;
int idx;
 
 
struct segmentTree
{
    inline int left(int n) {return (n << 1);}
    inline int right(int n) {return ((n << 1) + 1);}
 
    vector<int> st,lazy,A;
    int size;
 
    segmentTree(vector<int> &arr)
    {
        A = arr;
        size = A.size();
        lazy.assign(4*size,0LL);
        st.resize(4*size);
        build(1,0,size-1);
    }
 
    void build(int node, int a, int b)
    {
        if(a > b) return;
 
        if(a == b) 
        {
            st[node] = A[a];
            return;
        }
 
        build(left(node),a,(a+b)/2);
        build(right(node),(a+b)/2+1,b);
 
        //Combinacion
        st[node] = st[left(node)]+st[right(node)];
    }
 
    void update(int i, int j, int value)
    {
        update(i,j,value,1,0,size-1);
    }
 
    void update(int i, int j, int value, int node, int a, int b)
    {
 
        if(lazy[node] != 0LL)
        {
            st[node] += (b-a+1)*lazy[node];
 
            if(a != b)
            {
                lazy[left(node)] += lazy[node];
                lazy[right(node)] += lazy[node];    
            }
 
            lazy[node] = 0LL;
        }
 
        if(a > b || a > j || b < i)
            return;
 
        if(a >= i && b <= j)
        {
            st[node] += (b-a+1)*value;
            if(a != b)
            {
                lazy[left(node)] += value;
                lazy[right(node)] += value; 
            }
            return;
        }
 
        update(i,j,value,left(node),a,(a+b)/2);
        update(i,j,value,right(node),(a+b)/2+1,b);
 
        st[node] = st[left(node)]+st[right(node)];
    }
 
    ll query(int i, int j)
    {
        return query(i,j,1,0,size-1);
    }
 
    ll query(int i, int j, int node, int a, int b)
    {
        if(a > b || a > j || b < i)
            return 0; //NEUTRO!
 
        if(lazy[node] != 0LL)
        {
            st[node] += lazy[node];
 
            if(a != b)
            {
                lazy[left(node)] += lazy[node];
                lazy[right(node)] += lazy[node];
            }
 
            lazy[node] = 0LL;
        }
 
        if(a >= i && b <= j)
            return st[node];
        else
            return query(i,j,left(node),a,(a+b)/2)+query(i,j,right(node),(a+b)/2+1,b); // Composicion
    }
};
void dfs(int cur, int depth) {
 // if(!visited[cur])
  	H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  visited[cur]=true;
  //cerr<<cur<<endl;
  for (int i = 0; i < edges[cur].size(); i++) {
  	//if(!visited[edges[cur][i]])
  	//{
    	dfs(edges[cur][i], depth+1);
    	E[idx] = cur;                              // backtrack to current node
    	L[idx++] = depth;
    //}
  }
}
int LCA(segmentTree &S,int u,int v){
	return E[S.query(H[u],H[v])];
}
int main(){
	int n,m;
	cin>>n>>m;
	
	edges.resize(n+1);
	L.resize(2*MAX_N);E.resize(2*MAX_N);H.resize(MAX_N,-1);visited.resize(n+1,0);

	for(int i = 0; i < edges.size();i++){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		//edges[b-1].push_back(a-1);
	}
	cout<<"dfs"<<endl;
	dfs(1,0);
	for(int i=0;i<edges.size()+1;i++){
		cout<<H[i]<<" ";
	}
	cout<<H[9]<<" "<<H[12]<<endl;
	segmentTree S(L);
	/*for(int i=9;i<15;++i){
		cout<<i<<endl;
		cout<<L[i]<<" ";
	}*/
	cout<<endl;
	cout<<S.query(10,15)<<endl;
	cout<<LCA(S,8,11)<<endl;
}