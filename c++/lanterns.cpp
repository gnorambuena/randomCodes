#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
double max(double a, double b){
	return (a>b?a:b);
}
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	int n,l;
	cin>>n>>l;
	vector<int>lanternpos(n);
	for(int &a : lanternpos)
		cin>>a;
	sort(lanternpos.begin(),lanternpos.end());
	double maxdist = lanternpos[0];
	for(int i = 1 ; i < lanternpos.size() ; i++){
		maxdist = max(maxdist,(double)(lanternpos[i]-lanternpos[i-1])/2.0);
	}
	maxdist = max(maxdist,l-lanternpos[n-1]);
	cout<<maxdist<<"\n";
	return 0;
}