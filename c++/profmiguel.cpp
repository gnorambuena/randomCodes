#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<long long>>young,mature;
vector<long long>disty,distm;

void dijkstray(int start){
	disty.assign(26,1e9L);
	disty[start] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,start});
	while(!pq.empty()){
		auto el = pq.top();pq.pop();
		int node = el.second,dist = el.first;
		if(dist > disty[node])
			continue;
		for(int i = 0 ; i < young[node].size(); i++){
			int next = i;
			if(disty[node] + young[node][next] < disty[next]){
				disty[next] = disty[node] + young[node][next];
				pq.push({disty[next],next});
			}
		}
	}
}

void dijkstram(int start){
	distm.assign(26,1e9L);
	distm[start] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,start});
	while(!pq.empty()){
		auto el = pq.top();pq.pop();
		int node = el.second,dist = el.first;
		if(dist > distm[node])
			continue;
		for(int i = 0 ; i < mature[node].size(); i++){
			int next = i;
			if(distm[node] + mature[node][next] < distm[next]){
				distm[next] = distm[node] + mature[node][next];
				pq.push({distm[next],next});
			}
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		young.assign(26,vector<long long>(26,1e9L));
		mature.assign(26,vector<long long>(26,1e9L));
		for(int i = 0 ; i < n ; i++){
			char a,b,c,d;
			int cost;
			cin>>a>>b>>c>>d>>cost;
			if(a=='Y'){
				young[(int)c-'A'][(int)d-'A'] = cost;
				if(b=='B'){
					young[(int)d-'A'][(int)c-'A'] = cost;
				}
			}
			else{
				mature[(int)c-'A'][(int)d-'A'] = cost;
				if(b=='B')
					mature[(int)d-'A'][(int)c-'A'] = cost;
			}
		}
		char x,y;
		cin>>x>>y;
		dijkstray(x-'A');
		dijkstram(y-'A');
		long long mmin = 1e9L;
		for(int i = 0; i < disty.size() ; i++){
			if(disty[i]+distm[i] < mmin){
				mmin = disty[i]+distm[i];
			}
		}
		vector<int>ans;
		for(int i = 0; i < disty.size() && mmin!=1e9L; i++){
			if(disty[i]+distm[i] == mmin)
				ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		if(ans.size()!=0){
			cout<<mmin<<" ";
			for(int i = 0 ; i < ans.size() ; i++){
				cout<<(char)(ans[i]+'A');
				if(i+1!=ans.size())
					cout<<" ";
			}
			cout<<"\n";
		}else{
			cout<<"You will never meet.\n";
		}
	}
	return 0;
}