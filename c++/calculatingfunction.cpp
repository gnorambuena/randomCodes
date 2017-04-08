#include <iostream>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	long long n;
	cin>>n;
	if(n&1)cout<<(-1)*((n/2)+1)<<"\n";
	else cout<<(n/2)<<"\n";
	return 0;
}