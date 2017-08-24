#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll r1,r2;
vector<ll>x,y,z,p1,p2;


ll distToP1(int ind){
	cout<<"P1\n";
	return (x[ind]-p1[0])*(x[ind]-p1[0])+(y[ind]-p1[1])*(y[ind]-p1[1])+(z[ind]-p1[2])*(z[ind]-p1[2]);
}

ll distToP2(int ind){
	return (x[ind]-p2[0])*(x[ind]-p2[0])+(y[ind]-p2[1])*(y[ind]-p2[1])+(z[ind]-p2[2])*(z[ind]-p2[2]);
}
bool comp(int a,int b){
	int ind1 = a,ind2 = b;
	ll d1 = distToP1(ind1);
	ll d2 = distToP1(ind2);
	return d1<d2;
}
bool comp2(int a,int b){
	int ind1 = a,ind2 = b;
	ll d1 = distToP2(ind1);
	ll d2 = distToP2(ind2);
	return d1<d2;
}

int bsearch(vector<ll>&v,ll d,bool b = 1){
	int l = 0; int r = v.size();
	while(l<r){
		int m = (l+r)/2;
		if(b){
			if(distToP2(v[m]) <= d){
				l = m;
			}else{
				r = m-1;
			}
		}else{
			cout<<"planeta "<<v[m]<<" "<<distToP1(v[m])<<"\n";
			if(distToP1(v[m]) <= d){
				l = m;
			}else{
				r = m-1;
			}
		}
		cout<<l<<" "<<r<<"\n";
	}
	return l;
}
struct MergeSortTree{
	
	vector<vector<ll>> tree;
	int n; 
	#define all(v) v.begin(), v.end()
	MergeSortTree(vector<ll>&v){
		n = v.size();
		tree.assign(4*n+5,vector<ll>());
		build(v,1,0,n-1);
	}

	void build(vector<ll>&v,int node, int l, int r) {
		if(l == r) {
			tree[node].push_back(v[l]);
			return;
		} 
		int mid = (l + r) >> 1, 
		left = node << 1, right = left|1;
		
		build(v,left, l, mid);
		build(v,right, mid+1, r);
		
		merge(all(tree[left]), all(tree[right]),back_inserter(tree[node]),comp2);
	}

	ll query(int i,int j){
		return query(1,0,n-1,i,j);
	}
	ll query(int node, int l, int r, int i, int j) {
		if(i > r || l > j) return 0;
		if(i <= l && r <= j) {
			return bsearch(tree[node],r2);
		} 
		int mid = (l + r) >> 1, 
			left = node << 1, right = left|1;
		return query(left, l, mid, i, j) + 
			   query(right, mid+1, r, i, j);
	}
};

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	//vector<int>p1(3),p2(3);
	while(cin>>n){
		p1.assign(3,0);
		p2.assign(3,0);
		x.assign(n-2,0);
		y.assign(n-2,0);
		z.assign(n-2,0);
		cin>>p1[0]>>p1[1]>>p1[2];
		cin>>p2[0]>>p2[1]>>p2[2];
		vector<ll>v(n-2),v2;
		for(int i = 0; i < n-2 ; i++){
			cin>>x[i]>>y[i]>>z[i];
			v[i] = i;
		}
		v2 = v;
		sort(v.begin(),v.end(),comp);
		for(auto &el: v)cout<<el<<" ";
		cout<<"\n";
		MergeSortTree ST(v);
		sort(v2.begin(),v2.end(),comp2);
		for(auto &el: v2)cout<<el<<" ";
		cout<<"\n";
		int m;
		cin>>m;
		for(int i = 0; i < m ; i++){
			cin>>r1>>r2;
			ll ind = bsearch(v,r1,0);
			ll ind2 = bsearch(v2,r2);
			ll s = ST.query(0,ind);
			cout<<ind<<" "<<ind2<<" "<<s<<"\n";
			cout<<ind+ind2-s<<"\n";
		}
	}

	return 0;
}