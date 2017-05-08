#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(char a,char b){
	return a<b;
}
bool isTidy(long long num){
	string n = to_string(num);
	//reverse(n.begin(),n.end());
	return is_sorted(n.begin(),n.end(),comp);
}

int main(){
	int t;
	cin>>t;
	for(int l = 1 ; l <= t ;l++){
		long long n;
		cin>>n;
		while(!isTidy(n)){n--;}
		cout<<"Case #"<<l<<": "<<n<<"\n";
	}
	return 0;
}