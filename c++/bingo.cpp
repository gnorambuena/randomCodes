#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,b;
	while(cin>>n>>b && n!=0 && b!=0){
		vector<int>balls(b);
		for(int &a: balls)cin>>a;
		vector<bool>reach(n+1,false);
		for(int i = 0; i < b ; i++){
			for(int j = 0 ; j < b ;j++){
				int aux = abs(balls[i]-balls[j]);
				reach[aux]=true;
			}
		}
		bool flag = true;
		for(int i = 0 ; i < n+1 ; i++){
			if(!reach[i]){
				flag = false;break;
			}
		}
		cout<<(flag?"Y":"N")<<"\n";
	}
	return 0;
}