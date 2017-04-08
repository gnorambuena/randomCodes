#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	map<int,long long>m;
	long long n;
	cin>>n;
	vector<long long> f(n+1,0);
	for(int i = 0; i < n ; i++)
	{
		long long a;
		cin>>a;
		m[a]++;
	}
	f[1]=m[1];
	f[0]=0;
	for(int i = 2 ; i <= n; i++){
		if(f[i-1]>f[i-2]+m[i]*i)
			f[i]=f[i-1];
		else
			f[i]=f[i-2]+m[i]*i;
	}
	cout<<f[n]<<"\n";
}