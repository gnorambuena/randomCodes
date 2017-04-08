#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>chimps(n);
	for(int &a: chimps)cin>>a;
	int q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		int height;
		cin>>height;
		auto it1 = lower_bound(chimps.begin(),chimps.end(),height);
		auto it2 = upper_bound(chimps.begin(),chimps.end(),height);
		while(it1 != chimps.begin() && *it1 >= height){
			it1-=1;
		}
		if(it1==chimps.end())cout<<*(it1-1)<<" ";
		else if((it1 == chimps.begin() && *it1>=height)){
			cout<<"X ";
		}
		else{
			cout<<*it1<<" ";
		}
		if(*it2==height || it2==chimps.end()){
			cout<<"X\n";
		}
		else
			cout<<*it2<<"\n";
	}
	return 0;
}