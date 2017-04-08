#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void* f(){
	return f;
}
int main(){
	
	cin.tie(0);ios::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;

	vector<int>num(n);
	for(int &a : num)
		cin>>a;
	for(int i = 0 ; i < q ; i++){
		int a;
		cin>>a;
		vector<int>::iterator it = upper_bound(num.begin(),num.end(),a);
		cout<<*num.end()<<endl;
		cout<<(*(it-1)==a?it-num.begin()-1:-1)<<"\n";
	}
	return 0;
}