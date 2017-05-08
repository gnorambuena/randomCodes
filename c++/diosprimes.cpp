#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#define gcd __gcd
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll mulmod(ull a, ull b, ull c) 
{
    ull x = 0, y = a % c;
    while (b) {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n) {
        if (n & 1) ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}
const int N = 1e6;
int P[N+1];

bool isPrime(ll n) 
{
  if(n==1)return false;
  if(n <= N) return P[n] == n;
  if(n%2 == 0) return false;
    int a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        s++;
        d >>= 1;
    }

    // It's guaranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
    
    for(int i = 0; i < 7; i++) {
      ll fp = fastPow(a[i], d, n);
        bool comp = (fp != 1);
        if(comp) for(int j = 0; j < s; j++) {
            if (fp == n - 1) {
                comp = false;
                break;
            }

            fp = mulmod(fp,fp,n);
        }
        if(comp) return false;
    }
    return true;
}



ull rnd() {
  static ull r = 123;
  return r = r * 69069 + 1;
}

ull f(ull y, ull c, ull n)
{
	return (mulmod(y,y,n)+c)%n;
}

ull abs(ull x, ull y)
{
	if(x >= y)
		return x-y;
	return y-x;
}

ll brent(ll n, ll u = 0)
{
    if(n%2 == 0)
        return 2;
    ll x, ys, y = (u+2)%(n-1), c = (3*u+2)%(n-1), m = (5*u+2)%(n-1);
    
    ll g = 1, r = 1, q = 1;
    while(g == 1)
    {
        x = y;
        for(ll i = 0; i < r; ++i)
            y = (mulmod(y,y,n)+c)%n;
        for(ll k = 0; k < r && g == 1; k += m)
        {
            ys = y;
            ll M = min(m,r-k);
            for(ll i = 0; i < M; ++i)
            {
                y = (mulmod(y,y,n)+c)%n;
                q = mulmod(q,abs(x-y),n);
            }
            g = __gcd(q,n);
        }
        r *= 2;
    }
    if(g == n)
        do
        {
            ys = (mulmod(ys,ys,n)+c)%n;
            g = __gcd(abs(x-ys),n);
        } while(g == 1);

    if(g == n)
        return brent(n,u+1);
    
    return g;
}

void factorize(ll n, map<ll,int> &M)
{
    if(n <= N)
    {
        while(n != 1)
        {
            ++M[P[n]];
            n /= P[n];
        }
        return;
    }

    if(isPrime(n))
    {
        ++M[n];
        return;
    }

    ll d = brent(n);
    factorize(d,M); factorize(n/d,M);
}

ll POW(ll x, ll n)
{
	ll ans = 1;
	for(int i = 0; i < n; ++i)
		ans *= x;
	return ans;
}

ll sigma(ll n)
{
	map<ll,int> M; factorize(n,M);

	ll ans = 1;
	for(auto p : M)
		ans *= (POW(p.first,p.second+1)-1)/(p.first-1);
	return ans-n;
}

long long convert(string s){
	long long ans = s[0]-'0';
	for(int i = 1 ; i < s.size() ; i++){
		ans*=10;
		ans+=(s[i]-'0');
	}
	return ans;
}


vector<vector<long long> > dprimes = {{2,3,5,7},{37,73}};
void genAns(){
	for(int exp = 2 ; exp<= 9 ; exp++){
		vector<long long>res;
		for(long long dprime: dprimes[exp-1]){
			cout<<"processing:"<<dprime<<"\n";
			for(int i = 2 ; i <= 9 ; i++){
				long long ans = POW(10,exp)*i+dprime;
				cout<<"candidate:"<<ans<<"\n";
				string s = to_string(ans);
				reverse(s.begin(),s.end());
				long long ans2=convert(s);
				if(isPrime(ans) && isPrime(ans2)){
					res.push_back(ans);
					res.push_back(ans2);
					cout<<"diosprime"<<ans<<"\n";
				}
			}
		}
		sort(res.begin(),res.end());
		dprimes.push_back(res);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i <= N; ++i) P[i] = i;
    for(int i = 2; i*i <= N; ++i)
        if(P[i] == i)
            for(int j = i*i; j <= N; j += i)
                P[j] = i;

	//cout<<isPrime(7643)<<"\n";
	//cout<<"asd\n";
	genAns();
	int c = 0;
	set<long long>res;
	for(auto v:dprimes){
		for(auto i:v){
			res.insert(i);
		}
	}
	cout<<res.size()<<"\n";
	cout<<"asdasdasd\n";
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		//auto it = lower_bound(dprimes.begin(),dprimes.end(),a);
		//auto it2 = lower_bound(dprimes.begin(),dprimes.end(),b);
		//cout<<it2-it<<"\n";
	}
}

