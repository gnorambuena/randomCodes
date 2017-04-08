#include <iostream>
#include <cmath>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int a,b,mmax=0,cur=0;
	for(int i = 0; i < n ; i++){
		cin>>a>>b;
		cur-=a;
		cur+=b;
		//cerr<<cur<<endl;
		mmax=max(cur,mmax);
	}
	cout<<mmax<<"\n";
	return 0;
}