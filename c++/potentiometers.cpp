#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct FenwickTree{
	vector<long long>f;
	FenwickTree(vector<long long>&a){
		f.assign(a.size()+10,0);
		for(int i = 0 ; i < a.size() ; i++){
			update(i+1,a[i]);
		}
	}
	long long sum(int b){
		long long ans = 0;
		for(;b;b-=(b&-b))ans+=f[b];
			return ans;
	}
	long long sum(int a,int b){
		return sum(b)-(a==1?0:sum(a-1));
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
	int n;
	int cases=1;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n && n!=0){
		if(cases!=1)cout<<"\n";
		vector<long long>f(n);
		for(int i = 0 ; i < f.size() ; i++){
			cin>>f[i];
		}
		FenwickTree FT(f);
		string c;
		int l,r;
		cout<<"Case "<<cases++<<":\n";
		while(cin>>c && c!="END"){
			cin>>l>>r;
			if(c=="M"){
				cout<<FT.sum(l,r)<<"\n";
			}
			else{
				//int a =FT.query(l);
				FT.update(l,r-f[l-1]);
				f[l-1] = r;
			}
		}
	}
	return 0;
}