#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct SegmentTree
{
    vector<int> ST,A;
    int N;

    SegmentTree(vector<int> &V)
    {
        A = V;
        A.push_back(-1);
        N = V.size();
        ST.resize(N<<2);
        build(1,0,N-1);
    }

    void build(int n, int l, int r)
    {
        if(l == r)
        {
            ST[n] = r;
            return;
        }

        build(n<<1,l,(l+r)/2);
        build(n<<1|1,(l+r)/2+1,r);

        ST[n] = (A[ST[n<<1]] >= A[ST[n<<1|1]] ? ST[n<<1] : ST[n<<1|1]);
    }

    void update(int i, int val)
    {
        update(1,0,N-1,i,val);
    }

    void update(int n, int l, int r, int i, int val)
    {
        if(r < i || l > i) return;
        if(l == r)
        {
            A[r] = val;
            return;
        }

        update(n<<1,l,(l+r)/2,i,val);
        update(n<<1|1,(l+r)/2+1,r,i,val);

        ST[n] = (A[ST[n<<1]] >= A[ST[n<<1|1]] ? ST[n<<1] : ST[n<<1|1]);
    }

    int query(int i, int j)
    {
        return query(1,0,N-1,i,j);
    }

    int query(int n, int l, int r, int i, int j)
    {
        if(r < i || l > j) return N;
        if(l >= i && r <= j) return ST[n];
        
        int left = query(n<<1,l,(l+r)/2,i,j), right = query(n<<1|1,(l+r)/2+1,r,i,j);
        return (A[left] >= A[right] ? left : right);
    }
};

int main(){
	int n;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		vector<int> V(n+1);
		for(int i = 1 ; i <= n ; i++){
			cin>>V[i];
		}
		SegmentTree ST(V);
		int q;
		cin>>q;
		while(q--){
			char mander;
			int x,y;
			cin>>mander>>x>>y;
			if(mander=='Q') {
				long long firstmax = ST.query(x,y);
				long long val = V[firstmax];
				ST.update(firstmax,INT_MIN);
				long long secondmax = ST.query(x,y);
				ST.update(firstmax,val);
				cout<<V[firstmax]+V[secondmax]<<"\n";
			}
			else{
				V[x] = y;
				ST.update(x,y);
			} 
		}
	}
	return 0;	
}