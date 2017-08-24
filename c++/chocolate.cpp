#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int l = 0; l < t ; l++){
		int m,n;
		cin>>m>>n;
		vector<int>x(m-1),y(n-1);
		for(auto &a: x) cin>>a;
		for(auto &a: y) cin>>a;
		
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());

		sort(y.begin(), y.end());
		reverse(y.begin(), y.end());
		int yindex = 0, xindex = 0;
		int verticalcuts = 1, horizontalcuts = 1;
		long long ans = 0;
		while(yindex < y.size() || xindex < x.size()){
			if(yindex==y.size() || (xindex < x.size() && x[xindex] >= y[yindex])){
				verticalcuts++;
				ans+= horizontalcuts * x[xindex];
				xindex++;
			}else{
				horizontalcuts++;
				ans+= verticalcuts * y[yindex];
				yindex++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}