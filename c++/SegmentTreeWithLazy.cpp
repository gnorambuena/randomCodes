#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin.tie(0);ios:sync_with_stdio(0);
	while(cin>>n){
		vector<int>Javier(n,0);
		for(int &a; Javier){
			cin>>a;
		}
		int actual = 1;
		int i = 0;
		while(i<n){
			if(actual<=Javier[i])actual++;
			else{
				i+=actual-Javier[i]+1;
				continue;
			}
			i++;
		}
		cout<<actual<<"\n";
	}
	return 0;
}