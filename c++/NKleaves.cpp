#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e12L
typedef long long ll;
typedef vector<ll> vll;

vll S1,S2;
vector<vll> DP,opt;

ll cost(int i,int j){
	//cout<<i<<" "<<j<<"\n";
	ll sum1 = j*(S1[j]-S1[i-1]);
	ll sum2 = -1*(S2[j]-S2[i-1]);
	//cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<"\n";
	return sum1+sum2;
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
		S1.assign(n+2,0);
		S2.assign(n+2,0);
		vll H(n+1,0);
		DP.assign(k+2,vll(n+2,1e12L));
		opt.assign(k+2,vll(n+2));

		for(int i = 0; i < opt.size();i++){
			opt[i][0] = 1;
			opt[i][n+1] = n;
		}

		for(int i = 0; i < n ;i++){
			cin>>H[i];
		}
		reverse(H.begin(),H.end());

		for(int i = 1 ; i < n+1 ; i++){
			S1[i] = S1[i-1] + H[i];
			S2[i] = S2[i-1] + H[i] * i;
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