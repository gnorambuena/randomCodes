#include <iostream>
#include <vector>
using namespace std;
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	int n,m,b,mod,totalways=0;;
	cin>>n>>m>>b>>mod;
	vector<int>a(n);
	vector<vector<int> >Ways(m+1,vector<int>(501,0));
	Ways[0][0]=1;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		for(int j = 0 ; j+1 < Ways.size() ; j++){
			for(int bugs = 0 ; bugs + a[i] <=b; bugs++){
				//cerr<<"j="<<j<<" bugs"<<bugs<<endl;
				Ways[j+1][bugs+a[i]]=(Ways[j][bugs]+Ways[j+1][bugs+a[i]])%mod;
				//cerr<<Ways[j+1][bugs+a[i]]<<endl;
			}
		}
	}
	//cerr<<"asd"<<endl;
	for(int i = 0 ; i < Ways[m].size() ; i++){
		//cerr<<totalways<<endl;
		totalways+=Ways[m][i];
		totalways%=mod;
	}
	cout<<totalways<<endl;
	return 0;
}