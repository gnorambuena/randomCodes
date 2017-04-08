#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > graph;
vector<int>dist;
vector<bool>visited;
void dfs(int node){
    for(int &v : graph[node]){
        if(!visited[v]){
            visited[v]=true;
            dfs(v);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        graph.assign(n+1,vector<int>());
        dist.assign(n+1,0);
        visited.assign(n+1,false);
        visited[0]=true;
        map<pair<int,int>,int>m;
        for(int i = 1 ; i <= n ; i++){
            pair<int,int> pii;
            int d;
            cin>>pii.first>>pii.second>>d;
            //cout<<pii.first<<" "<<pii.second<<" "<<m[pii]<<" "<<d<<endl;
            if(m[pii]!=0){
				//cout<<"asdas"<<endl;
				if(d>=dist[m[pii]]){
						visited[m[pii]]=true;
						dist[i]=d;
						m[pii]=i;
						//cout<<"gana "<<d<<endl;
				}
			}
			else{
				m[pii]=i;
				dist[i]=d;
			}
        }
        for(auto it = m.begin() ; it!=m.end(); it++){
            for(auto it2 = m.begin() ; it2!=m.end() ; it2++){
                pair<int,int>aux1= it->first;
                pair<int,int>aux2= it2->first;
				int res1 = 2*abs(aux1.first-aux2.first);
				int res2 = 2*abs(aux1.second-aux2.second);
				int d1 = dist[it->second];
				int d2 = dist[it2->second];
				if((res1<=d1 && res2<=d1)||(res1<=d2 && res2<=d2)){
					//cout<<(it->second)+1<<" "<<it2->second+1<<endl;
					graph[it->second].push_back(it2->second);
					graph[it2->second].push_back(it->second);
				}
            }
        }
        int count = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
				//cout<<"no visitado "<<i<<endl;
                count++;
                visited[i]=true;
                dfs(i);
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
