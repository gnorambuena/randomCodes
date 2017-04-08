#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	double R = 1e10;
	double L = 0;
	int n;
	cin>>n;
	vector<long long> x(n),v(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>v[i];
	}
	double max_r,mid;
	int cycle=0;
	while(R-L>1e-10 && cycle <=64){
		mid = (R+L)/2.0;
		max_r=-9e99;
		bool collide=false;
		for(int i=0;i<n;i++){
			//cout<<"pos"<<x[i]+v[i]*mid<<endl;
			if(v[i]>0){
				max_r=max(max_r,x[i]+v[i]*mid);
				//cout<<i<<" "<<max_r<<endl;
			}
			else if(max_r>=x[i]+v[i]*mid){
				//se chocan las particulas
				//cout<<i<<endl;
				//cout<<max_r<<" "<<x[i]+v[i]*mid<<endl;
				//cout<<"collision"<<endl;
				collide=true;
			}
		}
		if(collide){
			R=mid;
		}
		else{
			L=mid;
		}
		//cout<<R<<" "<<L<<endl;
		cycle++;
	}
	if(mid>1e9){
		cout<<-1<<endl;
	}
	else{
		cout<<fixed<<setprecision(16)<<mid<<endl;
	}
	return 0;
}