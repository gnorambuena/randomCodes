#include <iostream>
#include <string>
using namespace std;

string genNextNum(string s){
	for(int i = s.size()-1 ; i >=0 ; i--){
		if(s[i]=='0'){
			s[i]='1';
			break;
		}
		else if(s[i]=='1'){
			s[i]='0';
		}
	}
	return s;
}
bool checkZeros(string s){
	for(int i = 0 ; i < s.size() ;i++){
		if(s[i]=='1')return false;
	}
	return true;
}
int main(){
	string s ="0";
	cout<<s<<"\n";
	for(int i = 0 ; i < 100 ; i++){
		s = genNextNum(s);
		if(checkZeros(s)){
			s.push_back('0');
		}
		cout<<s<<"\n";
	}
	return 0;
}