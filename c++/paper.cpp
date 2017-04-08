#include <iostream>
#include <algorithm>
using namespace std;
long long fold(long long a, long long b){
	long long count=0;
	while(a>0 && b>0){
	if(a>b){count+=a/b;a=a%b;}else{count+=b/a;b=b%a;}
	}
	return count;
}
int main(){
	long long a,b;
	cin>>a>>b;
	cout<<fold(a,b)<<endl;
	return 0;
}
