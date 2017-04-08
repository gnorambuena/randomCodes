#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int x=0;
	while(n--){
		string s;
		cin>>s;
		if(s=="++X")x++;
		if(s=="X++")x++;
		if(s=="--X")x--;
		if(s=="X--")x--;
	}
	cout<<x<<"\n";
	return 0;
}