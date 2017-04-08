#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
vector<int>sol;
vector<int>n;
vector<bool>ind;
bool found = false;
void backtracking(int index, int cur){
	if(0>cur)return;
	if(index==10){
		found = true;
		return ;
	}
	for(int i = 0; i < 10; i++){
		if(!ind[i]){
			sol.push_back(i);
			ind[i]=true;
			backtracking(index+1,cur-n[index]*i);
			if(found)break;
			sol.pop_back();
			ind[i]=false;
		}
	}
	return;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		n.assign(10,0);
		sol.clear();
		ind.assign(10,false);
		for(int &a : n)cin>>a;
		int val ;
		cin>>val;
		backtracking(0,val);
		if(!found)cout<<"-1\n";
		else{
			copy(sol.begin(),sol.end(),ostream_iterator<int>(cout," "));
			cout<<"\n";
		}
		found = false;
	}	
	return 0;
}
