#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <iterator>
#include <map>
#define PRINT(X) copy(X.begin(),X.end(),ostream_iterator<int>(cout," "));cout<<endl
#define UNVISITED -10
using namespace std;

int dfsNumberCounter,dfsRoot,rootChildren;
vector<int>dfs_num,dfs_low,dfs_parent,articulation_vertex;
vector<vector<bool> > AdjList;
vector<bool> visited;
bool found = false;
map< pair<int,int>,pair<int,int> >m;
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void articulationPointAndBridge(int u){
	dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
	for(int j = 0; j<(int)AdjList[u].size();j++){
		int N = AdjList[u][j];
		//cerr<<N<<endl;
		if(dfs_num[N] == UNVISITED){
			dfs_parent[N]=u;
			if(u==dfsRoot)rootChildren++;
			articulationPointAndBridge(N);
			if(dfs_low[N]>=dfs_num[u])
				articulation_vertex[u]=true;
			if(dfs_low[N]>dfs_num[u]){
				//cout<<"Edge "<<u<<" "<<N<<" is a Bridge"<<endl;
				//cerr<<"Erasing "<<u<<" "<<N<<endl;
				pair<int,int>p1(u,N),p2(N,u);
				if(m.count(p1)){
					pair<int,int> p3=m[p1];
					int a=p3.first,b=p3.second;
					AdjList[u].erase(AdjList[u].begin()+a,AdjList[u].begin()+a+1);
					AdjList[N].erase(AdjList[N].begin()+b,AdjList[N].begin()+a+1);
				}
				else{
					pair<int,int> p3=m[p1];
					int a=p3.first,b=p3.second;
					AdjList[u].erase(AdjList[u].begin()+a,AdjList[u].begin()+a+1);
					AdjList[N].erase(AdjList[N].begin()+b,AdjList[N].begin()+a+1);
				}		
			}
			dfs_low[u]=min(dfs_low[u],dfs_low[N]);
		}
		else if(N!=dfs_parent[u])
			dfs_low[u]=min(dfs_low[u],dfs_num[N]);
	}
}
void dfs(int start,int stop){
	stack<int> s;
	s.push(start);
	visited[start]=true;
	while(!s.empty()){
		int u = s.top();s.pop();
		for(int i = 0;i < AdjList[u].size() ; i++){
			int v=i;
			//cerr<<"u="<<u<<" v="<<v<<endl;
			if(v==stop){
				found=true;
				return;
			}
			if(!visited[v]){
				visited[v]=true;
				s.push(v);
			}
		}
	}
}
int main(){
	int n,m1;
	int cases=0;
	cin>>n>>m1;
	while(n!=0 && m1!=0){
		n++;
		dfs_num.clear();dfs_low.clear();dfs_parent.clear();articulation_vertex.clear();
		AdjList.clear();visited.clear();
		dfsNumberCounter=0; dfs_num.assign(n,UNVISITED);dfs_low.assign(n,0);
		dfs_parent.assign(n,0);articulation_vertex.assign(n,0);AdjList.resize(n);
		AdjList.assign(n,vector<bool>(n,false));
		found=false;
		UnionFind UF(n);
		visited.assign(n,false);
		m.clear();
		for(int i = 0 ; i < m1 ; i++){
			int a,b;
			cin>>a>>b;
			pair<int,int> p(a,b);
			if(!m.count(p)){
				AdjList[a].push_back(b);
				AdjList[b].push_back(a);
				pair<int,int> p2(AdjList[a].size()-1,AdjList[b].size()-1);
				m[p]=p2;
			}
			else{
				UF.unionSet(a,b);
			}
		}
		int s,t;
		cin>>s>>t;
		//cout<<"Bridges:"<<endl;
		//Merge de nodos
		for(int i = 0 ; i < AdjList.size() ; i++){
			for(int j = i+1 ; j < AdjList.size();j++){
				if(UF.isSameSet(i,j)){
					//cerr<<"SameSet "<<i<<" "<<j<<endl;
					int rep = UF.findSet(i);
					int notrep;
					(i!=rep)? notrep=i:notrep=j;
					for(int k = 0; k < AdjList[notrep].size();k++){
						AdjList[rep].push_back(AdjList[notrep][k]);
					}
					AdjList[notrep].clear();
				}
			}
		}
		for(int i=0;i < n;i++)
			if(dfs_num[i]==UNVISITED){
				dfsRoot = i;rootChildren=0;articulationPointAndBridge(i);
				articulation_vertex[dfsRoot]=(rootChildren>1);
			}
		//cerr<<"finding nodes"<<UF.findSet(s)<<" "<<UF.findSet(t)<<endl;
		dfs(UF.findSet(s),UF.findSet(t));
		cout<<"Case "<<++cases<<": ";
		if(!found){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
		cin>>n>>m1;
	}
	return 0;
}