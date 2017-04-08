#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int N;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>N){
		vector<int>izq(N,0),der(N,0),h(N,0);
		for(int &a:h)cin>>a;
		izq[0]=1;
		der[N-1]=1;
		for(int i = 1 ; i < N ; i++)izq[i]=min(izq[i-1]+1,h[i]);
		for(int i = N-2 ; i >= 0 ; i--)
			der[i]=min(der[i+1]+1,h[i]);
		int mx=-1;
		for(int i = 0 ; i < N ; i++)
			mx=max(min(izq[i],der[i]),mx);
		cout<<mx<<"\n";
	}
	return 0;
}