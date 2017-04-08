#include <iostream>
#include <vector>
using namespace std;
 
struct FenwickTree{
	vector<long long>f;
	FenwickTree(vector<long long>&a){
		f.assign(a.size()+10,0);
		for(int i = 0 ; i < a.size() ; i++){
			update(i+1,a[i]);
		}
	}
	long long query(int x){
		long long ans = 0;
		while(x!=0){
			ans+=f[x];
			x-=(x&-x);
		}
		return ans;
	}
	long long sum(int b){
		long long ans = 0;
		for(;b;b-=(b&-b))ans+=f[b];
			return ans;
	}
	long long sum(int a,int b){
		return sum(b)-(a==1 ? 0 : sum(a-1));
	}
	void update(int x , int val){
		while(x < f.size()){
			f[x]+=val;
			x+=(x&-x);
			//cerr<<x<<endl;
		}
	}
	void updateRange(int l, int r , long long val){
		update(l,val);
		update(r+1,-val);
	}
};
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<long long>arr(n,0);
	for(long long &a:arr)cin>>a;
	FenwickTree FT(arr);
	int q;
	cin>>q;
	char c;int l,r;
	for(int i = 0 ; i < q ; i++){
		cin>>c>>l>>r;
		if(c=='u'){
			FT.update(l,r);
		}
		else{
			cout<<FT.sum(l,r)<<"\n";
		}
	}
	return 0;
} 