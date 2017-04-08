#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int cards[] ={1,10,100,1000,10000};
int main(){
	int n,m;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n>>m){
		int ans = 0;
		for(int i = 0 ; i < m ; i++){
			int b;
			cin>>b;
			int daedalus;
			cin>>daedalus;
			for(int j = 1 ; j < n ; j++){
				int a;
				cin>>a;
				b-=a;
			}
			int res = -1;
			for(;cards[res+1]<=b && res < 4;res++){}
			int r = (res>=0?cards[res]:0);
			//cout<<b<<endl;
			//cout<<"chosen "<<r<<"\n";
			if(b-daedalus>0)
				ans+=r-daedalus;
			else if (b-r>0){
				ans+=r;
			}
			//cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}