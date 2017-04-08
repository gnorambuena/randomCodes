#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
	long long n,target;
	cin>>n>>target;
	vector<long long>trees(n);
	for(long long &a:trees)cin>>a;
	sort(trees.begin(),trees.end());
	vector<long long>parsum(n);
	parsum[0] = trees[0];
	for(int i = 1 ; i < n ; i++){
		parsum[i] = parsum[i-1] + trees[i];
	}
	int l = 0;
	int r = n-1;
	int m = (r+l)/2;
	long long total = parsum[n-1];
	for(int i = 0 ; i < 64 ; i++){
		if(total-parsum[m]==target)break;
		if(total-parsum[m]<target){
			r = m;
		}else{
			l = m;
		}
		m = (r+l)/2;
	}
	cout<<trees[m]<<"\n";
	return 0;
}