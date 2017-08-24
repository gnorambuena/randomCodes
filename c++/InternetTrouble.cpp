#include <bits/stdc++.h>
using namespace std;

#define INF 1e14L

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

vvl DP;
vl S1,S2;

int N,B,C;
ll cost(int i,int j){
	int m = (i+j)/2;
	//cout<<i<<" "<<j<<"\n";
	ll sum1 = S1[m]-S1[i-1];
	ll sum2 = -i*(S2[m]-S2[i-1]);
	ll sum3 = j*(S2[j]-S2[m]);
	ll sum4 = -1*(S1[j]-S1[m]);
	//cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<"\n";
	return C*(sum1+sum2+sum3+sum4);
}

void solve(int k,int l,int r,int opt_l,int opt_r){
	if(r<l)return;

	int m = (l+r)/2;

	int opt_m = -1;

	for(int i = opt_l; i <= min(r-1,opt_r);i++){
		if(DP[k-1][i] + cost(i,m) < DP[k][m]){
			DP[k][m] = DP[k-1][i]+cost(i,m);
			//cout<<"cost = "<<cost(i,m)<<"\n";	
			//cout<<"DPant = "<<DP[k-1][i]<<"\n";
			//cout<<"DP = "<<DP[k][m]<<"\n";
			opt_m = i;
		}
	}

	solve(k,l,m-1,opt_l,opt_m);
	solve(k,m+1,r,opt_m,opt_r);
}


int main(){

	cin>>N>>B>>C;
	vector<ll> H(N+1);
	DP.assign(N+1,vl(N+1,INF));
	S1.assign(N+1,0);
	S2.assign(N+1,0);

	for(int i = 1 ; i < N+1; i++){
		cin>>H[i];
	}

	for(int i = 1; i < N+1 ; i++){
		S1[i] = S1[i-1] + i * H[i];
		S2[i] = S2[i-1] + H[i];
	}

	ll optp = INF;
	for(int i = 1; i < N+1 ; i++){
		DP[1][i] = C * (i * S2[i] - S1[i]);
		optp = min(DP[1][i] + C*(S1[N]-S1[i-1] - i*(S2[N]-S2[i-1])),optp);
		//cout<<DP[1][i]<<"\n";
	}
	cout<<optp+B<<" ";
	for(int k = 2 ; k < N+1 ; k++){
		//cout<<"caca\n";
		solve(k,1,N,1,N);
		//cout<<"caca2\n";
		ll opt = INF;
		for(int i = 1 ; i < N + 1 ; i++){
			opt = min(opt, DP[k][i] + C*(S1[N]-S1[i] - i*(S2[N]-S2[i])));
		}
		cout<<B*k+opt;
		if(k != N )
			cout<<" ";
	}
	cout<<"\n";
	return 0;
}
