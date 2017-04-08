#include <iostream>
#include <vector>
#include <queue>
#define FREE -1
#define pq priority_queue

using namespace std;
typedef pair<int,int> pii; 

void releaseMemory(pq<pii,vector<pii>,greater<pii> > &UsedMemory,pq<int,vector<int>,greater<int> > &FreeMemory,vector<int> &time,int t){
	while(!UsedMemory.empty() && t-UsedMemory.top().first >= 600){
		pii block = UsedMemory.top();UsedMemory.pop();
		if(time[block.second]!=FREE && block.first!=time[block.second]){
			block.first=time[block.second];
			UsedMemory.push(block);
		}
		else{
			time[block.second]=FREE;
			FreeMemory.push(block.second);
		}
	}
}
int main(){
	vector<int> time(30001,FREE);
	priority_queue<int,vector<int>,greater<int> > FreeMemory;
	priority_queue<pii,vector<pii>,greater<pii> > UsedMemory;
	int t;
	char mander;
	for(int i = 1; i < 30001 ; i++){
		FreeMemory.push(i);
	}
	while(cin>>t>>mander){
		releaseMemory(UsedMemory,FreeMemory,time,t);
		if(mander=='.'){
			int n;
			cin>>n;
			if(time[n]!=FREE){
				time[n] = t;
				cout << '+' << endl;
			}
			else{
				cout << '-' << endl;
			}
		}
		else{
			int k = FreeMemory.top();FreeMemory.pop();
			UsedMemory.push(make_pair(t,k));
			time[k]=t;
			cout<< k << endl;
		}
	}
	return 0;
}