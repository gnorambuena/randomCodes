#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a,int b){
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}
std::vector<int> divisors(int n)
{
	vector<int> D;
	for(int d = 1; d*d <= n; ++d)
		if(n%d == 0)
		{
			D.push_back(d);
			D.push_back(n/d);
		}
	sort(D.begin(),D.end());
	return D;
}

vector<int>calcdiv;

int modifiedgcd(int low, int high){
	int l = 0;
	int r = calcdiv.size();
	int m = (l+r)/2;
	for(int i = 0 ; i < 64 ; i++){
		//cout<<calcdiv[m]<<"\n";
		if(calcdiv[m]<=high){
			l = m;
		}else{
			r = m;
		}
		m = (l+r)/2;
	}
	if(calcdiv[m]>=low)return calcdiv[m];
	else return -1;
}
int main(){
	//cout<<"asdasdasd\n";
	//cin.tie(0);ios::sync_with_stdio(0);
	int a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	int g = gcd(a,b);
	calcdiv = divisors(g);
	//cout<<"asd\n";
	while(n--){
		int low,high;
		cin>>low>>high;
		//cout<<"asdasd\n";
		cout<<modifiedgcd(low,high)<<"\n";
	}
	return 0;
}