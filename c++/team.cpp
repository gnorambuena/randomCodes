#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,m;
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n>>m;
	if(n>m+1 || m>2*(n+1)){
		cout<<"-1"<<endl;
		return 0;
	}
	string s;
	int ones,zeros;
	if(n==m+1){
		s="";
		ones=m;
		zeros=n;
	}
	else{
		s="1";
		ones=m-1;
		zeros=n;
	}
	while(ones>zeros && ones>2){
		s.append("101");
		ones-=2;
		zeros-=1;
	}
	while(ones>0 && zeros>0){
		s.append("01");
		ones--;
		zeros--;
	}
	if(zeros==1)s.append("0");
	else if(ones==1)s.append("1");
	cout<<s<<endl;
	return 0;
}