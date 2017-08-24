#include <iostream>
using namespace std;

typedef long long ll;

ll num = 0;

ll fibonacci(ll a){
	if(a<=1)return a;
	else{
		num+=2;
		return fibonacci(a-1)+fibonacci(a-2);
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		ll x;
		num = 0;
		cin>>x;
		ll ans = fibonacci(x);
		cout<<"fib("<<x<<") = "<<num<<" calls = "<<ans<<"\n";
	}
	return 0;
}