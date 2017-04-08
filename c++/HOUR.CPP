#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>seq;
		int a;
		cin>>a;
		seq.push_back(a);
		for(int i = 1 ; i < n ; i++){
			cin>>a;
			vector<int>::iterator low;
			low = lower_bound(seq.begin(),seq.end(),a,greater<int>());
			if(low==seq.end()){
				seq.push_back(a);
			}
			else{
				*low=a;
			}
		}
		cout<<seq.size()<<"\n";
	}
	return 0;
}