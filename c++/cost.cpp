#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize,numPairs;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    numPairs.assign()
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
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,pair<int,int> >> EdgeList(m);
  UnionFind UF(n);
  for(int i = 0 ; i < m ; i++){
    pair<int,int> p;
    int w;
    cin>>p.first>>p.second>>w;
    EdgeList.push_back(make_pair(w,p));
  }
  int ans = 0;
  sort(EdgeList.begin(),EdgeList.end(),greater<pair<int,pair<int,int>>>());
  for(int i = 0 ; i < EdgeList.size() ; i++){
    auto p = EdgeList[i];
    int w = p.first;
    pair<int,int> aux = p.second;
    UF.unionSet(aux.first,aux.second);

  }
  return 0;
}