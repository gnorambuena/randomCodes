#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,b;
	while(cin>>n>>b && n!= -1 && b!=-1){
		vector<int>pop(n);
		int mmax = -1;
		for(int &a : pop){
			cin>>a;
			mmax = max(mmax,a);
		}
		int l = 1;
		int r = mmax;

		while(r>l){
			//cerr<<l<<" "<<r<<endl;
			int m = (r+l)/2;
			int count = 0;
			for(int i = 0 ; i < n ; i++){
				//cerr<<i<<" "<<pop[i]/m+1<<"\n";
				int aux = (pop[i]+m-1)/m;
				count += aux;
			}
			//cout<<"count "<<count<<endl;
			//cout<<maxp<<endl;
			if(count>b)
				l = m+1;
			else{
				r = m;
			}
		}
		cout<<l<<"\n";
}
	return 0;
}