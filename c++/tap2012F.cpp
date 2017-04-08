#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#define DFS_WHITE -1
#define DFS_BLACK 1
using namespace std;
typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   
vi topoSort;
vi dfs_num;
vector<vector<int> > AdjList;
             // global vector to store the toposort in reverse order
void dfs2(int u) {    // change function name to differentiate with original dfs
  dfs_num[u] = DFS_BLACK;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == DFS_WHITE)
      dfs2(v);
  }
  topoSort.push_back(u); } 
 
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n && n!=-1){
		map<ii,int>m;
		AdjList.assign(10000,vector<int>());
		vii rev;
		for(int i = 2 ; i <= n ; i++){
			string s;
			cin>>s;
			vi order;
			for(int j = 0 ; j < s.size() ; j++){
				ii p = {min(i,s[j]-'0'),max(i,s[j]-'0')};
				if(m[p]==0){
					cout<<m.size()<<endl;
					cout<<p.first<<" "<<p.second<<"\n";
					m[p]=m.size();
					rev.push_back(p);
				}
				order.push_back(m[p]);
			}
			for(int j = 0 ; j+1 < order.size();j++){
				AdjList[order[j]].push_back(order[j+1]);
			}
		}
		topoSort.clear();
 		dfs_num.assign(AdjList.size(), DFS_WHITE);
  		for (int i = 0; i < AdjList.size(); i++)            // this part is the same as finding CCs
    		if (dfs_num[i] == DFS_WHITE)
      			dfs2(i);
  		reverse(topoSort.begin(), topoSort.end());
  		for(int i = 0 ; i < topoSort.size() ; i++){
  			int u = topoSort[i];
  			ii p = rev[u];
  			if(p.first==1)cout<<p.second;
  		}
  		cout<<"\n";
	}
	return 0;
}