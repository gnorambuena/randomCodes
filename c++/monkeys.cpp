#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int j = 1 ; j <= t ; j++){
		int n;
		cin>>n;
		vector<int>heights(n);
		for(int &a : heights)cin>>a;
		int ans,k=0;
		for(int i = 1 ; i <= n ; i++){
			k=max(k,heights[i]-heights[i-1]);
		}
		ans=k;
		cerr<<ans<<endl;
		for(int i = 1 ; i <= n ; i++){
			if(k == heights[i]-heights[i-1])k--;
			else if(k<heights[i]-heights[i-1]){
				ans++;
				break;
			}
		}
		cout<<"Case "<<j<<": "<<ans<<"\n";
	}
	return 0;
}