#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	locale loc;
	for(int i = 0 ; i < s1.size() ; i++){
		s1[i]=tolower(s1[i],loc);
	}
	
	for(int i = 0 ; i < s2.size() ; i++){
		s2[i]=tolower(s2[i],loc);
	}
	if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end())){
		cout<<"-1"<<endl;
	}
	else if(s1==s2){
		cout<<"0"<<endl;
	}
	else
		cout<<"1"<<endl;
	return 0;
}