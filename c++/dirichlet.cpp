#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector<vector<int>>DP;
ll n;
ll poww(int a,int b){
	ll p = 1;
	while(b--){
		p*=a;
		//cout<<p<<"\n";
	}
	return p;
}

int calc(ll a, int b){
	//cout<<a<<" "<<b<<"\n";
	if(DP[a][b]!=-1)return DP[a][b];
	if(b==1 && a*a>=n)
		return DP[a][b] = ((n-a)%2==1?0:2);
	if(poww(a,b)>=n){
		//cout<<"caca2\n";
		return DP[a][b] = 2;
	}
	if(a==1 && poww(2,b) >= n){
		//cout<<"caca\n";
		return DP[a][b] = 1;
	}
	return DP[a][b] = max(2-calc(a+1,b),2-calc(a,b+1));
}
int main(){
	ll a,b;
	cin>>a>>b>>n;
	if(a*a>=n){
		//cout<<p<<"\n";
		cout<<(((a*a)-n)%2==1?"Stas":"Masha")<<"\n";
	}else{
		DP.assign(4e4,vector<int>(31,-1));
		ll ans = calc(a,b);
		if(ans==2)
			cout<<"Masha\n";
		else if(ans==0)
			cout<<"Stas\n";
		else
			cout<<"Missing\n";
	}
	return 0;
}