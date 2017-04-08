#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool flag = true;
	for(char c: s){
		if(c=='i')flag = false;
	}
	cout<<(flag?"S":"N")<<"\n";
}