#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>cash = {10000,5000,2000,1000,500,200,100,50,20,10,5};

vector<long long>DP(30100,0);

long long cont(int k){
	cout<<k<<"\n";
	if(k==0){
		cout<<"K=0"<<"\n";
		return 1;
	}
	if(DP[k]!=0){
		cout<<"memo\n";
		//cout<<"asdasd\n";
		return DP[k];
	}
	long long res = LLONG_MAX;
	for(int i = 0 ; i < cash.size() ; i++){
		cout<<"asdasd "<<k-cash[i]<<"\n";
		if(k>=cash[i]){
			res=1+min(res,cont(k-cash[i]));
		}
	}
	cout<<k<<" res= "<<(DP[k]=res)<<"\n";
	return DP[k];
}
int main(){
	double n;
	while(cin>>n){
		int x = (int)(n*100);
		if(x==0)
			break;
		cout<<cont(x)<<"\n";
	}
	return 0;
}