#include <iostream>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long a=1,b;
	long long time=0;
	for(int i = 0 ; i < m ; i++){
		cin>>b;
		if(a<=b)time+=(b-a);
		else time+=n-a+b;
		a=b;
	}
	cout<<time<<endl;
	return 0;
}