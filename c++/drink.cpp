#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int>shops(n);
	for(int &a:shops)cin>>a;
	sort(shops.begin(),shops.end());
	int q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		int a;
		cin>>a;
		auto it = upper_bound(shops.begin(),shops.end(),a);
		cout<<it-shops.begin()<<"\n";
	}
	return 0;
}