#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	while(t--){
		for(int i = 0 ; i+1 < n ; i++){
			if(s[i]=='B' && s[i+1]=='G'){
				s[i]='G';
				s[++i]='B';
			}
		}
	}
	cout<<s<<endl;
	return 0;
}