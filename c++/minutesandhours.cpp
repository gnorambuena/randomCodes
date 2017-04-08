#include <iostream>
using namespace std;
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		cout<<(n%6==0?"Y":"N")<<"\n";
	}
}