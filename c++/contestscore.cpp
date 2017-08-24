#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	priority_queue<int,vector<int>,greater<int>>pq;
	long long currenttime = 0;
	long long ans = 0;
	if(k>n)k=n;
	for(int i = 0 ; i < k ; i++){
		int a;
		cin>>a;
		pq.push(a);
	}
	for(int i = k ; i < n ; i++){
		int t = pq.top();pq.pop();
		currenttime+=t;
		ans+=currenttime;
		int a;
		cin>>a;
		pq.push(a);
	}
	while(!pq.empty()){
		int t = pq.top();pq.pop();
		currenttime+=t;
		ans+=currenttime;
	}
	cout<<ans<<"\n";
	return 0;
}