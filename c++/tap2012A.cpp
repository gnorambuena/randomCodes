#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=-1){
		int a = 0;
		vector<int>stones(n+1,0);
		for(int i = 1 ; i <= n  ; i++){
			cin>>stones[i];
		}
		for(int i = n ; i > 0 ; i--){
			if((stones[i]+a)%i==0){
				//cout<<i<<endl;
				a+=(stones[i]+a)/i;
				stones[i]=0;
			}
		}
		bool flag = true;
		for(int i = 1 ; i <= n ; i++){
			if(stones[i]!=0){
				flag = false;
				break;
			}
		}
		cout<<(flag?"S":"N")<<"\n";
	}
}