#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree{
	vector<int>f;
	FenwickTree(vector<int>&a){
		f.assign(a.size()+10,0);
		for(int i = 0 ; i < a.size() ; i++){
			update(i+1,a[i]);
		}
	}
	int query(int x){
		int ans = 0;
		while(x!=0){
			ans+=f[x];
			x-=(x&-x);
		}
		return ans;
	}
	void update(int x , int val){
		while(x < f.size()){
			f[x]+=val;
			x+=(x&-x);
			//cerr<<x<<endl;
		}
	}
	void updateRange(int l, int r , int val){
		update(l,val);
		update(r+1,-val);
	}
};
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,u;
		cin>>n>>u;
		vector<int>arr(n,0);
		FenwickTree FT(arr);
		int l,r,val;
		for(int i = 0 ; i < u ; i++){
			//cerr<<u<<endl;
			cin>>l>>r>>val;
			FT.updateRange(l+1,r+1,val);
		}
		//cerr<<"asd"<<endl;
		int q;
		cin>>q;
		for(int i = 0 ; i < q ; i++){
			int n;
			cin>>n;
			cout<<FT.query(n+1)<<"\n";
		}
	}
	return 0;
}