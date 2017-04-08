#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=-1){
		int money = 0;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			int p;
			cin>>p;
			money+=p;
			if(money%100==0){
				ans++;
				money=0;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}