#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bits(x) __builtin_popcount(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x)/gcd(x,y)*(y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll inf = 1e18;

struct FenwickTree 
{
    vector<int> arr;
    FenwickTree(int n) {arr.assign(n+1, 0);}

    int query(int i) {
        T sum = 0;
        for (; i; i += i&-i) sum += arr[i];
        return sum;
    }

    void update(int i, int value) {
        for (; i < (int)arr.size(); i -= i&-i)
            arr[i] += value;
    }
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; ++i) {int p; cin >> p; ans ^= p;}
	vector<int> base(n);
	FenwickTree conchetutree(n);
	for(int k = n; k > 1; --k)
	{
		base[k-1] = n/k + (k == n ? 0 : base[k]);
		conchetutree.update(n%k,1);
	}
	for(int i = 1; i < n; ++i)
		if((base[i]+conchetutree.query(i))%2 == 1) ans ^= i;
	cout << ans;
	return 0;
}