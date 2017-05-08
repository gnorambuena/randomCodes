#include <iostream>
#include <vector>
using namespace std;

vector<long long>dp(10000,1);
vector<int> coin = {5,10,25,50};

void ways(){
	for(int c:coin){
		for(int j = c; j < dp.size() ; j++)
			dp[j] += dp[j-c];
	}
}
int main(){
	int n;
	ways();
	while(cin>>n){
		cout<<dp[n]<<"\n";
	}
	return 0;
}
