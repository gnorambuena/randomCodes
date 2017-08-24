#include <iostream>
using namespace std;

typedef long long ll;


ll count(ll a){
	ll ans = 0;
	ll unos = 0;
	for(int i = 64; i>=0 ; i--){
		ll b = (1L<<i)&a;
		if(b){
			ans += (1L<<(i-1)) * i + unos * (1L<<i);
			unos++;
		}	
	}
	return ans + unos;
}

int main(){
	ll a,b;
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin>>a>>b){
		cout<<count(b)-count(a-1)<<"\n";
	}
	return 0;
}