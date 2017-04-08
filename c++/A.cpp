#include <iostream>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int a,b,c;
	while(cin>>a>>b>>c){
		if(a==b || a==c || b==c || (a+b)==c || (a+c)==b || (b+c)==a)
			cout<<"S\n";
		else
			cout<<"N\n";
	}
	return 0;
}