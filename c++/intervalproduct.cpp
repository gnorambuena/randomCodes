#include <iostream>
#include <vector>
using namespace std;

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
		if(j<a || i>b)return;
		if(i>=a && j<=b){
			ST[node]=val;
			return;
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

		if(i>=a && j<=b)return ST[node];
		else{
			return query(a,b,node<<1,i,(i+j)/2)*query(a,b,(node<<1)+1,(i+j)/2+1,j);
		}
	}
};
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,k;
	while(cin>>n>>k){
		vector<int>a(n+1,0);
		for(int i = 1 ; i <= n ; i++){
			int aux;
			cin>>aux;
			if(aux>0){
				a[i]=1;
			}
			else if(aux<0){
				a[i]=-1;
			}
		}
		SegmentTree ST(a);
		for(int i = 0 ; i < k ; i++){
			char c;
			cin>>c;
			if(c=='C'){
				int I,v;
				cin>>I>>v;
				if(v>0){
					ST.update(I,I,1);
				}
				else if(v<0){
					ST.update(I,I,-1);
				}
				else{
					ST.update(I,I,0);
				}
			}
			else{
				int I,J;
				cin>>I>>J;
				int ans=ST.query(I,J);
				if(ans==1)cout<<"+";
				else if(ans==-1)cout<<"-";
				else cout<<0;
			}
		}
		cout<<"\n";
	}
	return 0;
} 
