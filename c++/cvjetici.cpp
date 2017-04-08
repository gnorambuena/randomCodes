#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct FenwickTree{
	vector<long long>f;
	FenwickTree(vector<long long>&a){
		f.assign(2*a.size(),0);
		for(int i = 0 ; i < a.size() ; i++){
			update(i+1,a[i]);
		}
	}
	long long sum(int x){
		long long ans = 0;
		for(;x;x-=(x&-x))ans+=f[x];
		return ans;
	}
	long long sum(int a,int b){
		return sum(b)-(a==1?0:sum(a-1));
	}
	void update(int x , int val){
		for(;x <= f.size();x+=x&(-x)){
			f[x]+=val;
			//cerr<<x<<endl;
		}
	}
	void updateRange(int l, int r , long long val){
		update(l,val);
		update(r+1,-val);
	}
};
int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	vector<long long>a(n+1,0);
	FenwickTree FT(a);
	for(int i = 0 ; i < n ;i++){
		int l,r;
		cin>>l>>r;
		long long b = FT.sum(l),c=FT.sum(r);
		FT.update(l,-b);FT.update(r,-c);
		FT.update(l+1,b);FT.update(r+1,c);
		FT.update(l+1,1);FT.update(r,-1);
		cout<<b+c<<"\n";
	}
	return 0;
}