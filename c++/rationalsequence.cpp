#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int P;
	cin>>P;
	while(P--){
		int k;
		string a;
		long long p,q;
		cin>>k;
		scanf("%lld/%lld",&p,&q);
		//cout<<p<<" "<<q<<endl;
		string s="";
		while(p!=1 || q!=1){
			if(p>q){
				s.push_back('r');
				p -=q;
			}
			else{
				s.push_back('l');
				q-=p;
			}
		}
		//cout<<s<<endl;
		reverse(s.begin(),s.end());
		long long ans = 1;
		for(char c : s){
			if(c=='l'){
				ans*=2;
			}
			else{
				ans*=2;
				++ans;
			}
		}
		cout<<k<<" "<<ans<<"\n";
	}
	return 0;
}				