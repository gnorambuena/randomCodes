#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef vector<int>BigInt;
void ToBigInt(string s){
	BigInt(160) intstring;
	for(int i=0;i<s.size();i++){
	intstring.push_back(int(s[i]-'0'));
	}
	for(int i=0;i<intstring.size();i++){
	cout<<intstring[i];
	}
	cout<<endl;
}
int main(){
	string s;
	cin>>s;
	ToBigInt(s);
	return 0;
}
