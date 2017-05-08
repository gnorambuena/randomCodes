#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<long long>memo;
vector<long long>holes;
int t1,t2,c;
int nextHole(int curHole,int largo){
	auto it = upper_bound(holes.begin(),holes.end(),curHole+largo);
	//cout<<"nexthole = "<<*it<<"\n";
	return (int)(it-holes.begin());
}

int Pf;
long long dp(int index){
	//cout<<index<<"\n";
	if(memo[index]!=-1)return memo[index];
	else{
		long long izq,der;
		if(holes[index] > Pf) return 0;

		izq = t1 + dp(nextHole(holes[index],t1));
	
		der = t2 + dp(nextHole(holes[index],t2));
		return memo[index] = min(izq,der);
	}
}

int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n>>c>>t1>>t2){
		holes.assign(n,0);
		memo.assign(2*n,-1);
		
		for(long long &d:holes)cin>>d;
		vector<long long>aux = holes;
		for(long long &d:aux)holes.push_back(d+c);

		//for(long long &d:holes)cout<<d<<"\n";
		long long res = INT_MAX;
		Pf = holes[n-1];
		for(int i = 0 ; i < n; i++){
			memo.assign(2*n,-1);
			res = min(dp(i),res);
			Pf = holes[i+n];
		}
		cout<<res<<"\n";
	}
}