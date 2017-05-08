#include <iostream>
using namespace std;

int main(){
	int N,B;
	while(cin>>N>>B){
		if(N==0 && B==0)break;
		int cost = 0;
		while(N--){
			int a;
			cin>>a;
			cost+=a;
		}
		cout<<B/cost<<"\n";
	}

	return 0;
}