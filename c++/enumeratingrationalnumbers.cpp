#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long phi(long long n) {          
	long long result = n;          
	for(long long i=2;i*i <= n;i++) {            
		if (n % i == 0) result -= result / i;            
		while (n % i == 0) n /= i;          
	}          
	if (n > 1) result -= result / n;          
	return result;        
}

long long gcd(long long a,long long b){
	long long c = max(a,b);
	long long d = min(a,b);
	if(d==0)return c;
	else
		return gcd(d,c%d);
}
vector<long long> sum(200002,0);
int main(){
	sum[0] = 0;
	sum[1] = 2;
	for(int i = 2; i < 200002 ; i++){
		sum[i] = sum[i-1] + phi(i);
	}
	//cout<<"termine\n";
	//cout<<sum.back()<<"\n";
	//cout<<phi(1e9+7)<<"\n";
	long long k;
	while(cin>>k){
		if(k==0)break;
		if(k==1){
			cout<<"0/1\n";
		}else if(k==2){
			cout<<"1/1\n";
		}else{
			auto it = lower_bound(sum.begin(),sum.end(),k);
			int i = (int)(it-sum.begin());
			//cout<<i<<"\n";
			//cout<<sum[i-1]<<"\n";
			//cout<<sum[i]<<"\n";
			long long n = k-sum[i-1];
			//cout<<n<<"\n";
			//cin>>k;
			int j = i;
			for(int j = 0; j <= i ; j++){
				//cout<<n<<"\n";
				if(gcd(i,j)==1)n--;
				if(n==0){
					cout<<j<<"/"<<i<<"\n";
					break;
				}
			}
		}
	}

	return 0;
}