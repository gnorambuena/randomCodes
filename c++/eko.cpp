#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	long long n,target;
	cin>>n>>target;
	vector<long long>trees(n);
	for(auto &a: trees)cin>>a;
	sort(trees.begin(),trees.end());
	long long l = 0;
	long long r = trees.back();
	long long m = (r+l)/2;
	long long last = 0;
	long long sum = 0;
	for(int i = 0; i < 64 ; i++){
		//cout<<"en while"<<m<<"\n";
		sum = 0;
		auto it = lower_bound(trees.begin(),trees.end(),m);
		while(it!=trees.end()){
			sum+= (*it)-m;
			it++;
		}
		//cout<<"sum="<<sum<<"\n";
		if(sum==target){
			break;
		}
		else if(sum>target){
			l=m+1;
		}else{
			r=m-1;
		}
		last = m;
		m=(l+r)/2;
	}
	cout<<m<<"\n";
	return 0;
}