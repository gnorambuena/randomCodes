#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int>seq;
	int a;
	cin>>a;
	seq.push_back(a);
	vector<int>sz;
	sz.push_back(1);
	for(int i = 1 ; i < n ; i++){
		cin>>a;
		vector<int>::iterator low;
		low = lower_bound(seq.begin(),seq.end(),a,greater<int>());
		if(low==seq.end()){
			seq.push_back(a);
			sz.push_back(1);
		}
		else{
			*low=a;
			sz[low-seq.begin()]++;
		}
	}
	cout<<*max_element(sz.begin(),sz.end())<<"\n";
	return 0;
}