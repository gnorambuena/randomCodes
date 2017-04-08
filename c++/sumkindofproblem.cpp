#include <iostream>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int p;
	cin>>p;
	while(p--){
		int n;
		cin>>k>>n;
		cout<<k<<" "<<(n*(n+1))/2<<" "<<((2*n+1)*(2*n+2))/2<<" "<<n*(n+1)<<"\n";
	}
	return 0;
}