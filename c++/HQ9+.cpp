#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
	string s;
	set<char>myset;
	myset.insert('H');
	myset.insert('Q');
	myset.insert('9');
	cin>>s;
	bool flag = false;
	for(int i = 0 ; i < s.size() && !flag; i++){
		if(myset.find(s[i])!=myset.end()){
			flag=true;
		}
	}
	cout<<(flag?"YES\n":"NO\n");
	return 0;
}