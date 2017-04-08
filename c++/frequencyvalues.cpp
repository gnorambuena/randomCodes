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
    int offset = 100000;
    while(cin>>n && n!=0){
        int q;
        cin>>q;
        vector<int>frequencies(2*offset+1,0);
        vector<int>ending(n+1);
        vector<int>starting(n+1);
        vector<int>values(n+1);
        for(int i = 1 ; i <= n ; i++) {
            int a;
            cin>>a;
            values[i]=a+offset;
            frequencies[a+offset]++;
        }
        int init = values[1];
        int curIndex = 1;
        starting[1] = 1;
        for(int i = 1 ; i <= n ; i++) {
            if(values[i]==init) {
                starting[i] = curIndex;
            }
            else{
                starting[i]=i;
                init = values[i];
                curIndex = i;
            }
        }
        init = values[n];
        curIndex = n;
        ending[n]=n;
        for(int i = n; i>=0 ; i--){
            if(values[i]==init){
                ending[i] = curIndex;
            }
            else{
                ending[i]=i;
                init = values[i];
                curIndex = i;
            }
        }
        SegmentTree ST(frequencies);
        /*for(int i = 0 ; i <= n ; i++) {
            cout<<starting[i]<<" "<<ending[i]<<"\n";
        }*/
        while(q--){
            int l,r;
            cin>>l>>r;
            if(values[l]==values[r]){
                //cerr<<"asdasd"<<endl;
                cout<<(r-l+1)<<"\n";
                continue;
            }
            int i = ending[l];
            int j = starting[r];
            //cout<<i<<" "<<j<<endl;
            if(i+1==j){
                //int ans = ST.query(i-l+1+offset,r-j+1+offset);
                //cerr<<"asdasd"<<endl;
                cout<<max(i-l+1,r-j+1)<<"\n";
            }
            else{
                int first = i-l+1;
                int third = r-j+1;
                //cout<<first<<" "<<third<<endl;
                //cout<<ST.query(values[i+1],values[j-1])<<endl;
                int second = frequencies[ST.query(values[i+1],values[j-1])];
                cout<<max(first,max(second,third))<<"\n";
            }
        }
    }
    return 0;
}