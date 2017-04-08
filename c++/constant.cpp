#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<ll> > mat;
vector<int> C;
int N;
ll DP(ll i, ll sum){
	if(i<0)return (sum==0);
	if(sum<0)return 0;
	if(mat[i][sum]!=-1)return mat[i][sum];
	else{
		mat[i][sum] = 0;
		for(int j = 0 ; sum>= j * C[i] ; j++){
			mat[i][sum]+=DP(i-1,sum-C[i]*j);
			//cout<<mat[i][sum]<<endl;
		}
		return mat[i][sum];
	} 
}
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
 	int t;
 	cin>>t;
 	for(int k = 1 ; k <= t ; k++){
 		C.assign(8,0);
 		for(int i = 0 ; i < 8 ; i++){
 			cin>>C[i];
 		}
 		cin>>N;
 		mat.assign(10,vector<ll>(N+1,-1));
 		cout<<"Equation #"<<k<<": "<<DP(7,N)<<endl;
 	}
 	return 0;
 }