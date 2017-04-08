#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	long long n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n && n!=0){
		vector<long long>C(n);
		for(long long &el:C)cin>>el;
		vector<long long>P(n);
		for(long long &el:P)cin>>el;
		sort(C.begin(),C.end(),greater<int>());
		sort(P.begin(),P.end());
		unsigned long long ans = 0;
		for(int i = 0 ; i < n ; i++){
			ans+=C[i]*P[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}