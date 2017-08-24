#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define INF 1e12L
typedef long long ll;
typedef vector<ll> vll;

vll W,WX,X;
vector<vll> C,DP,opt;

ll cost(int i, int j){
	if(C[i][j]!= - 1)return C[i][j];
	return C[i][j] = X[j]*(W[j]-W[i-1]) - (WX[j]-WX[i-1]);
}

void calc(int k, int l, int r){
	if(l>r)return;
	ll m = (l+r)/2;

	DP[k][m] = INF;

	for(int i = opt[k][l-1]; i <= min(opt[k][r+1],m-1); i++){
		if(DP[k-1][i] + cost(i+1,m) < DP[k][m]){
			DP[k][m] = DP[k-1][i] + cost(i+1,m);
			opt[k][m] = i;
		}
	}

	calc(k,l,m-1);
	calc(k,m+1,r);
}

int main(){
	int n,k;
	cin.tie(0);
	ios::sync_with_stdio(0);
	while(cin>>n>>k){
		vll wp(n+1);
		W.assign(n+2,0);
		X.assign(n+2,0);
		WX.assign(n+2,0);
		C.assign(n+2,vll(n+2,-1));
		DP.assign(k+2,vll(n+2,1e12L));
		opt.assign(k+2,vll(n+2));
		for(int i = 0; i < opt.size();i++){
			opt[i][0] = 1;
			opt[i][n+1] = n;
		}
		for(int i = 1; i <= n ;i++){
			cin>>X[i]>>wp[i];
			W[i] = W[i-1] + wp[i];
			WX[i] = WX[i-1] + wp[i] * X[i];
		}
		for(int i = 0; i <= n;i++){
			DP[1][i] = cost(1,i);
		}
		for(int l = 2; l <= k; l++)
			calc(l,1,n);
		cout<<DP[k][n]<<"\n";
	}
	return 0;
}