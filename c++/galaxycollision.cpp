#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>color;

ll bfs(vector<vector<ll>>&graph,ll start){
	queue<ll>q;
	color[start] = 1;
	q.push(start);
	ll ans1 = 0 ,ans2 = 0;
	while(!q.empty()){
		ll node = q.front();q.pop();
		if(color[node]==1){
			ans1++;
		}else{
			ans2++;
		}
		for(ll i = 0 ; i < graph[node].size() ; i++){
			ll u = graph[node][i];
			if(color[u]==0){
				q.push(u);
				color[u] = (color[node]==1?2:1);
			}
		}
	}
	return min(ans1,ans2);
}
int main(){
	ll n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		map<pair<ll,ll>,ll> m;
		for(ll i = 0 ; i < n ; i++){
			ll x,y;
			cin>>x>>y;
			m[{x,y}] = i;
		}
		vector<vector<ll>> graph(n,vector<ll>());
		color.assign(n,0);
		for(auto it:m){
			auto coord = it.first;
			auto num = it.second;
			for(ll i = coord.first-5; i <= coord.first+5;i++){
				for(ll j = coord.second - 5; j <= coord.second+5;j++){
					auto poll = m.find({i,j});
					if( (poll!=m.end() && poll->first!=coord) && ( (coord.first-i)*(coord.first-i)+(coord.second-j)*(coord.second-j) <= 25)){
						graph[num].push_back(poll->second);
					}
				}
			}
		}

		ll ans = 0;

		for(ll i = 0; i < graph.size() ; i++){
			if(color[i]==0){
				ans += bfs(graph,i);

				//cout<<ans2<<"\n";
			}
		}
	cout<<ans<<"\n";
	}
	return 0;
}