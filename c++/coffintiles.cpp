#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> crib(1000001,-1);
vector<int> numdiv(1000001,1);
vector<int> mininv(1000001,INT_MAX);
void gencrib(){
	for(int i = 2 ; i < crib.size() ; i++){
		for(int j = i ; j < crib.size() ; j+=i){
			if(crib[j]==-1)
				crib[j] = i;
			/*if(j==36864){
				cout<<i<<endl;
				cout<<numdiv[j]+1<<endl;
			}*/
			numdiv[j]++;
		}
	}
	for(int i = 2 ; i < numdiv.size() ; i++){
		numdiv[i]=(numdiv[i]+1)/2;
	}
	for(int i = 1 ; i < numdiv.size() ; i++){
		int ans = numdiv[i];
		mininv[ans]=min(mininv[ans],i);
	}
}

int main(){
	gencrib();
	int n;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		if(mininv[a]==INT_MAX)cout<<"Too big\n";
		else cout<<mininv[a]<<"\n";
	}
	return 0;
}