#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n && n!=0){
		vector<int>car(n,0);
		vector<int>pos(n,0);
		vector<int>rec(n,-1);
		for(int i = 0 ; i < n ; i++){
			int a,b;
			cin>>a>>b;
			car[i]=a;
			pos[i]=b;
		}
		bool flag = true;
		for(int i = 0 ; i < n ; i++){
			int c = car[i];
			int d = pos[i]+i;
			if(d<0 || d>=n || rec[d]!=-1){
				flag = false;
				break;
			}
			else{
				rec[d]=car[i];
			}
		}
		if(flag){
			for(int i = 0 ; i < n ; i++){
				cout<<rec[i];
				if(i+1!=n)cout<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<"-1\n";
		}
	}
	return 0;
}