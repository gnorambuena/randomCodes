#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	string s;
	set<char>vowels;
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');
	vowels.insert('y');
	cin>>s;
	transform(s.begin(),s.end(),s.begin(), ::tolower);
	string s2;
	for(int i = 0 ; i < s.size() ; i++){
		if(!vowels.count(s[i]))s2.push_back(s[i]);
	}
	string res;
	for(int i = 0 ; i < s2.size() ; i++){
		res.push_back('.');
		res.push_back(s2[i]);
	}
	cout<<res<<"\n";
	return 0;
}