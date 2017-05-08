#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k1,k2,n1,n2;
int r = 1e8;

vector<vector<vector<int> > > dp;

long long ans(int n1,int n2,bool b){
	if(n1 == 0 && n2 == 0) return 1;

	if(dp[n1][n2][b] != -1) return dp[n1][n2][b];

	int q = 0;
	int m1 = min(n1,k1);
	int m2 = min(n2,k2);
	if(!b){
		for(int i = 1 ; i <= m1 ; i++){
			q += ans(n1-i,n2,!b);
			q %= r;
		}
	}else{
		for(int i = 1 ; i <= m2 ; i++){
			q+= ans(n1,n2-i,!b);
			q %= r;
		}
	}
	return dp[n1][n2][b] = q;
}
int main(){
	int n1,n2;
	cin>>n1>>n2>>k1>>k2;
	dp.assign(n1+1,vector< vector<int> > (n2+1,vector<int>(2,-1)));
	cout<<(ans(n1,n2,true)+ans(n1,n2,false))%r<<"\n";

	return 0;
}