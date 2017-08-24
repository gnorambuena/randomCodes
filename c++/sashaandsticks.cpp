#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	cin>>n>>k;
	ll ans = n/k;
	cout<<(n%2==1?"YES":"NO")<<"\n";
	return 0;
}