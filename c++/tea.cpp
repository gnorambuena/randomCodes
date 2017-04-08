#include <iostream>
using namespace std;
int main(){
	int t;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>t){
		int ans = 0;
		for(int i = 0 ; i < 5 ; i++){
			int b;
			cin>>b;
			ans+=(b==t?1:0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}