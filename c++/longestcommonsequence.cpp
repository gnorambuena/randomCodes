#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

vector<vector<int> > DP;

int lcs(string &a,string &b,int m,int n){
	if(DP[m][n]!=-1)
		return DP[m][n];
	if(m == 0 || n == 0)
		return 0;
	else if(a[m-1]==b[n-1])
		return DP[m][n] = (1+lcs(a,b,m-1,n-1));
	else
		return DP[m][n] = max(lcs(a,b,m,n-1),lcs(a,b,m-1,n));
}

int main(){
	string a,b;
	while(true){
		getline(cin,a); if(a == "") break;
		getline(cin,b);
		DP.assign(a.size()+1,vector<int>(b.size()+1,-1));
		cout<<lcs(a,b,a.size(),b.size())<<"\n";
	}
	return 0;
}