#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
bool makeTriangle(int testing,vector<int>&height){
	if(testing == 1)return true;
 	int H = 1;
 	bool dir = true;
 	for(int i = 0 ; i < height.size() ; i++)
 	{
  		if(height[i] < H)
  		{
   			H = height[i];
   			dir = true;
  		}

		if(H == testing)dir = false;

		if(!dir && H == 1)return true;

		H += (dir ? 1 : -1);
 	}
	return false;
}
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		vector<int>height(n,0);
		int r=-1;
		for(int &a: height){
			cin>>a;
			r=max(a,r);
		}
		int l = 1;
		while(r-l>2){
			int h = (l+r)/2;
			if(makeTriangle(h,height))l=h;
			else r=h-1;
		}
		for(; r >= l; --r)
			if(makeTriangle(r,height))break;
		cout<<r<<'\n';
		}
 return 0;
}