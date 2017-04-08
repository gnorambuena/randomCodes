#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long int n;
	cin>>n;
	n&1?cout<<((-1)*(2*n+1)-1)/4<<endl:cout<<n/2<<endl;
	return 0;
}
