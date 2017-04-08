#include <iostream>
#include <vector>
#define rep(i,n) for(i;i<n;i++)
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n),s(n);
	vector<bool>counter(n);	
	int i=0,sum=0;
	rep(i,n){
		cin>>arr[i];
		sum+=arr[i];
		s[i]=sum;
	}
	if(sum%3!=0){
		cout<<"0"<<endl;
		return 0;
	}
	i=0;
	int count=0;
	rep(i,n){
		if(s[i]==sum/3 || s[i]==2*sum/3){
			cout<<i<<endl;
			counter[i]=true;
			count++;
		}
		else{
			counter[i]=false;
		}
	}
	s[0]=arr[0];
	cout<<count<<endl;
}