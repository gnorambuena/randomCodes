#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	vector<long long>a(3);
	cin>>a[0]>>a[1]>>a[2];
	sort(a.begin(),a.end());
	if(2*(a[0]+a[1])<=a[2]){
		cout<<a[0]+a[1]<<endl;
	}
	else{
		while(max(a[0],a[1])>a[2]){
			if(a[0]>a[1])
				a[0]--;
			else
				a[1]--;
			a[2]-=2;
		}
		cout<<(a[0]+a[1]+a[2])/3<<endl;
	}
	return 0;
}