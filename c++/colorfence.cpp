#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b){
	if(a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}
int main(){
	int v;
	cin>>v;
	vector<int> vpii(10,0);
	int mval = INT_MAX;
	int m = 1;
	for(int i = 1 ; i <= 9 ; i++){
		int a;
		cin>>a;
		vpii[i]=a;
		if(a<mval){
			mval = a;
			m = i;
		}
	}
	int len = v/mval;
	v-=len*mval;
	string ans(len,(char)(m+'0'));
	for(int i = 0 ; i < len ; i++){
		for(int j = 9 ; j >= m ; j--){
			if(v-vpii[j]+mval>=0){
				cout<<"ans"<<endl;
				ans[i]=(char)(j+'0');
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}