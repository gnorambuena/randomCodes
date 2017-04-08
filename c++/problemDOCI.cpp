#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long>expresion(2*n-1);
	for(long long &a : expresion)cin>>a;
	for(int i = 1 ; i < expresion.size() ; i+=2){
		if(expresion[i]){
			expresion[i]=0;
			expresion[i+1]*=expresion[i-1];
			expresion[i-1]=0;
		}
	}
	int ans = 0;
	for(int i = 0 ; i < expresion.size() ; i++){
		ans+=expresion[i];
	}
	cout<<ans<<"\n";
	return 0;
}