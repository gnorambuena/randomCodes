#include <string>
#include <vector>
#include <iostream>
using namespace std;
string initials(string s){
	string res;
	res.push_back(s[0]);
	for(int i=1;i+1<s.size();i++){
		if(s[i]==' ' && s[i+1]!=' '){
			res.push_back(s[i+1]);
		}
	}	
	return res;
}

int main(){
	string authors,words;
	while(getline(cin,authors)){
		string initaut(initials(authors));
		getline(cin,words);
		string comp(initials(words));
		if(initaut==comp){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
