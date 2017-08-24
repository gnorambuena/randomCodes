#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
vector<ll>S,S2;
int n,m,x,y;
vector<vector<ll>>DP;
ll numberOfWhites(int x, int y){
	//cout<<y<<" "<<x-1<<"\n";
	return S[y]-S[x-1];
}

ll numberOfBlacks(int x, int y){
	//cout<<y<<" "<<x-1<<"\n";
	return S2[y]-S2[x-1];
}

ll calcDP(bool b, int i){
	if(DP[b][i]!=-1)return DP[b][i];
	ll ans = 1e12L;
	if(!b){
		for(int a = x; a <= y ;a++){
			if(i>=a)
				ans = min(calcDP(1,i-a)+ numberOfWhites(i-a+1,i),ans);
		}
	}else{
		for(int a = x; a <= y ; a++){
			if(i>=a)
				ans = min(calcDP(0,i-a) + numberOfBlacks(i-a+1,i),ans);
		}
	}
	return DP[b][i] = ans;
}
int main(){
	cin>>n>>m>>x>>y;
	vector<ll>Sp(m+1,0),Sp2(m+1,0);
	S.assign(m+1,0);
	S2.assign(m+1,0);
	DP.assign(2,vector<ll>(m+1,-1));
	for(int i = 0; i < n ; i++){
		for(int j = 1; j <= m ; j++){
			char c;
			cin>>c;
			if(c=='#'){
				Sp2[j]++;
			}else{
				Sp[j]++;
			}
		}
	}
	for(int i = 1 ; i < S.size(); i++){
		S[i] = S[i-1] + Sp[i];
		S2[i] = S2[i-1] + Sp2[i]; 
	}

	DP[0][0] = DP[1][0] = 0;
	cout<<min(calcDP(0,m),calcDP(1,m))<<"\n";
	return 0;
}