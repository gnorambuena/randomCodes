#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int>h;
bool makeTriangle(int i, int testingH){
	int left= i-1;
	int right= i+1;
	while(left>=0 && right<h.size() && testingH>0){
		if(h[left]>=testingH && h[right]>=testingH){
			left--;
			right++;
			testingH--;
		}
		else break;
		i++;
	}
	return testingH==0;
}
int main(){
	int N;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>N){
		h.assign(N,0);
		for(int &a:h)cin>>a;
		int actualmax=-1;
		for(int i = 0 ; i < N ; i++){
			int left = actualmax;
			int right = h[i];
			while(right-left>3){
				int m=(left+right)/2;
				if(makeTriangle(i,m))
					left=m;
				else
					right=m-1;
			}
			for(;right>=left;right--)
				if(makeTriangle(i,right))
					break;
			actualmax=max(actualmax,right);
		}
		cout<<actualmax<<"\n";
	}
	return 0;
}