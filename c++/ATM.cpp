#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a,int b){
	return a<=b;
}
int main(){
	//cin.tie(0);ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	vector<int>bills(n);
	for(int &a : bills){
		cin>>a;
	}
	int q;
	cin>>q;
	for(int i = 0  ; i < q ; i++){
		int cash;
		cin>>cash;
		int ans = 0;
		int rep = 0;
		while(cash>0){
			rep++;
			auto it = lower_bound(bills.begin(),bills.end(),cash,comp);
			int aux;
			//cerr<<cash<<endl;
			if(it!=bills.begin()){
				int bill = *(it-1);
				//cerr<<bill<<"asd"<<endl;
				aux = cash/bill;
				cash -= aux*bill;
				//cerr<<cash<<endl;
			}
			else{
				int bill = *it;
				//cerr<<bill<<endl;
				if(bill>cash)break;
				aux = cash/bill;
				cash -= aux*bill;
				//cerr<<cash<<endl;
			}
			ans += aux;
		}
		cout<<(cash==0 && ans<=k && rep<=2?ans:-1)<<"\n";
	}
	return 0;
}