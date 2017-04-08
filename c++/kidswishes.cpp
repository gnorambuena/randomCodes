#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <map>
using namespace std;
vector<bool>visited;
vector<int>depth;
vector<int>parent;
map<int,vector<int> > graph;
bool dfs(int node){
		stack<int>s;
		s.push(node);
		visited[node]=true;
		parent[node]=-1;
		int first_node=-1,last_node=-1;
		while(!s.empty() && last_node==-1){
			int v = s.top();s.pop();
			visited[v]=true;
			for(int i = 0 ; i < graph[v].size() ; i++){
				if(!visited[graph[v][i]]){
					parent[graph[v][i]]=v;
					s.push(graph[v][i]);
				}
				else{
					last_node=v; 
					first_node=graph[v][i];
					break;
				}
			}
		}
		//cout<<last_node+1<<" "<<first_node+1<<"\n";
		//cout<<depth[last_node]<<" "<<depth[first_node]<<"\n";
		if(last_node!=-1){
			int cont=1;
			int aux = last_node;
			while(aux!=first_node){
				aux=parent[aux];
				cont++;
			}
			//cout<<cont<<endl;
			if(cont==graph.size()-1)return true;
			return false;
		}
		return false;
	}
int main(){
	int k,w;
	while(cin>>k>>w && k!=0){
		if(w==0){
			cout<<"Y\n";
			continue;
		}
		graph.clear();
		for(int i = 0 ; i < w ; i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		visited.assign(k,false);
		parent.assign(k,0);
		cout<<(dfs(0)?"Y":"N")<<"\n";
	}
	return 0;
}