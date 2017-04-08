#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	string s;
	cin>>n;
	cin>>s;
	int res=0;
	for(int i = 0 ; i+1 < n ; i++){
		if(s[i]==s[i+1]){
			//s.erase(i,1);
			//--i;
			//cout<<s<<endl;
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}