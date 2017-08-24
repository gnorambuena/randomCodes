#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>graph;
vector<int>weight;
vector<int>temperatures;
vector<int>parent;
int dfs(int node){
	if(graph[node].size()==0){
		return weight[node] = temperatures[node];
	}
	int w = temperatures[node];
	for(int i = 0; i < graph[node].size() ; i++){
		int aux = dfs(graph[node][i]);
		w+=aux;
	}
	return weight[node] = w;
}

vector<int>ans;
bool dfs2(int node,int target){
	bool des = false;
	for(int i = 0 ; i < graph[node].size() ; i++){
		cout<<graph[node][i]<<" asdasd\n";
		des = des || dfs2(graph[node][i],target);
	}
	cout<<node<<" "<<des<<"\n";
	if(weight[node]==target && !des){
		ans.push_back(node);
	}
	return des || (weight[node]==target);
}

void dfs3(int node,int target,int u = -1){
	//cout<<weight[node]<<" "<<node<<"\n";
	if(weight[node]==2*target){
		u = node;
		//cout<<"node2 "<<node<<"\n";
	}
	if(weight[node]==target && u!=-1){
		//cout<<"node "<<node<<"\n";
		ans[0] = node;
		ans[1] = u;
	}
	else{
		for(int i = 0 ; i < graph[node].size(); i++){
			dfs3(graph[node][i],target,u);
		}
	}
}

int main(){
	int n;
	cin>>n;
	temperatures.resize(n+1);
	weight.resize(n+1);
	graph.assign(n+1,vector<int>());
	parent.resize(n+1);
	int root;
	for(int i = 1 ; i <= n ; i++){
		int a;
		cin>>a;
		graph[a].push_back(i);
		parent[i] = a;
		if(a == 0)root = i;
		cin>>temperatures[i];
	}
	cout<<"\n\n";
	int total = dfs(root);
	if(total%3!=0)cout<<"-1\n";
	else{
		dfs2(root,total/3);
		if(ans.size()>=2){
			cout<<ans[0]<<" "<<ans[1]<<"\n";
		}
		else{
			ans.assign(2,-1);
			//cout<<ans[0]<<" "<<ans[1]<<"\n";
			//cout<<"asdasd\n";
			dfs3(root,weight[root]/3);
			if(ans[0]!=-1 && ans[1]!=-1){
				cout<<ans[0]<<" "<<ans[1]<<"\n";
			}
			else{
				cout<<"-1\n";
			}
		}
	}
	return 0;
}