#include <iostream>
using namespace std;
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n && n!=0){
		int ans = 0;
		for(int i = 1 ; i <= n ;i++){
			ans+=(i*i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}