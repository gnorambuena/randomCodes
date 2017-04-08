#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int x,y;
	for(int i = 0; i < 5 ; i++){
		for(int j = 0; j<5; j++){
			int a;
			cin>>a;
			if(a){
				x=i;
				y=j;
			}
		}
	}
	cout<<abs(2-x)+abs(2-y)<<"\n";
	return 0;
}