#include <iostream>
#include <vector>
using namespace std;
typedef 
struct SegmentTree{
	vector<int>ST;
	vector<int>lazy;
	int n;
	SegmentTree(vector<int>&a){
		ST.assign(4*a.size(),0);
		lazy.assign(4*a.size(),0);
		n=a.size();
		build(a,1,0,n-1);
	}
	void build(vector<int>&a,int node,int i , int j){
		if(i==j){
			ST[node]=a[i];
			return ;
		}
		build(a,node<<1,i,(i+j)/2);
		build(a,(node<<1)+1,((i+j)/2)+1,j);
 
		ST[node]=ST[node<<1]*ST[(node<<1)+1];
	}
	void update(int a, int b,int val){
		update(a,b,1,0,n-1,val);
	}
	void update(int a, int b, int node, int i , int j , int val){
		/*if(lazy[node]!=0){
			ST[node]+=lazy[node]*(j-i+1);
			if(i!=j){
				lazy[node<<1]+=lazy[node];
				lazy[(node<<1)+1]+=lazy[node];
			}
			lazy[node]=0;
		}*/
		if(j<a || i>b)return;
		if(i>=a && j<=b){
			ST[node]+=val;
			/*if(i!=j){
				lazy[node<<1]+=val;
				lazy[(node<<1)+1]+=val;
			}*/
			return;
			//cerr<<ST[node]<<" "<<node<<endl;
		}
		else{
			update(a,b,node<<1,i,(i+j)/2,val);
			update(a,b,(node<<1)+1,(i+j)/2+1,j,val);
			ST[node]=ST[node<<1]*ST[(node<<1)+1];
		}
 
	}
	int query(int a, int b){
		return query(a,b, 1,0,n-1);
	}
	int query(int a, int b, int node,int i, int j){
		if(j<a || i>b)return 1;
		/*if(lazy[node]!=0){
			ST[node]+=lazy[node]*(j-i+1);
			if(i!=j){
				lazy[node<<1]+=lazy[node];
				lazy[(node<<1)+1]+=lazy[node];
			}
			lazy[node]=0;
		}*/
		if(i>=a && j<=b)return ST[node];
		else{
			return query(a,b,node<<1,i,(i+j)/2)*query(a,b,(node<<1)+1,(i+j)/2+1,j);
		}
	}
};
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,u;
		cin>>n>>u;
		vector<int>a(n,0);
		SegmentTree ST(a);
		for(int i = 0; i < u ; i++){
			int l,r,val;
			cin>>l>>r>>val;
			ST.update(l,r,val);
		}
		int q;
		cin>>q;
		for(int i = 0; i < q; i++){
			int a;
			cin>>a;
			cout<<ST.query(a,a)<<"\n";
		}
	}
	return 0;
} 