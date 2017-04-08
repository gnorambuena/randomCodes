#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX_V 1000
#define INF INT_MAX
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis;                                          // global variables

int Aug(int l) {                 // return 1 if an augmenting path is found
  if (vis[l]) return 0;                               // return 0 otherwise
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                           // found 1 matching
  } }
  return 0;                                                  // no matching
}

int main(){
    //Acelerar I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Lectura vertices arista
    int k;
    cin>>k;
    while(k--)
    {
	    // Inicializacion mega-hermosa
	    //cerr<<V<<E<<endl;
	    //memset(res, 0, sizeof res);
	    int p,t,v,c;
	    cin >> p >> t >> v >> c;
	    AdjList.assign(p+t+3, vi());
	   // cerr<<"asd"<<endl;
	    //Lectura del grafo
	    //cerr<<"V= "<<V<<endl;
	    vector<pair<int,int> > passenger;
	    for(int i = 0; i < p ; ++i)
	    {
	    	//cerr<<"i= "<<i<<endl;
	    	long long n,m;
	    	cin>>n>>m;
	    	passenger.push_back(make_pair(n,m));
	    	//G.addEdge(0,i+1,INF,0);
	    }
	    vector<pair<int,int> > taxi;
	    for(int i = 0; i < t; ++i){
	    	//cerr<<i<<endl;
	    	long long n,m;
	    	cin>>n>>m;
	    	pair<int,int>t1(n,m);
	    	taxi.push_back(t1);
	    	//G.addEdge(p+i+1,p+t+1,INF,0);

	    	for(int j = 0;j<passenger.size();j++)
	    	{
	    		pair<int,int> p1=passenger[j];
	    		int dist=abs(t1.first-p1.first)+abs(t1.second-p1.second);
	    		if(200*dist<=v*c)
	    		{
	    			//G.addEdge(j+1,p+j+1,1,1);
	    			AdjList[i].push_back(t+j);
	    			AdjList[t+j].push_back(i);
	    			//res[j+1][p+j+1]=1;
	    			//res[p+j+1][j+1]=1;
	    		}
	    	}
	    }
		int V = p+t, Vleft = t;                               // we ignore vertex 0
		int MCBM = 0;
		match.assign(V, -1);    // V is the number of vertices in bipartite graph
		for (int l = 0; l < Vleft; l++) {         // Vleft = size of the left set
		    vis.assign(Vleft, 0);                    // reset before each recursion
		    MCBM += Aug(l);
		}
		cout<<MCBM<<endl;  // the answer is 2 for Figure 4.42
 	}
 
    return 0;
}