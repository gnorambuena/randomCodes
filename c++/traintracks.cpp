#include <iostream>
#include <string>

using namespace std;
int main(){
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	for(int i = 0 ; i < n ; i++){
		string s;
		getline(cin,s);
		int m=0,f=0;
		for(char c:s){
			if(c=='M'){
				m++;
			}else if(c=='F'){
				f++;
			}
		}
		if(m==1 && f==1){
			cout<<"NO LOOP\n";
		}else if(m==f){
			cout<<"LOOP\n";
		}else{
			cout<<"NO LOOP\n";
		}
	}
}