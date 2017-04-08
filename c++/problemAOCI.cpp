#include <iostream>
#include <vector>
using namespace std;
int main(){
	int H,M;
	int totalsec;
	cin>>H>>M;
	totalsec = H*3600+M*60;
	int N;
	cin>>N;
	vector<int>S(N);
	for(int i = 0 ; i < N ; i++){
		int a,b;
		cin>>a>>b;
		S[i]=60*a+b;
	}
	int ans = 0;
	int i = 0;
	while(ans+S[i]<=totalsec){
		ans+=S[i];
		i++;
		//cerr<<ans<<endl;
	}
	cout<<i<<"\n";
	return 0;
}