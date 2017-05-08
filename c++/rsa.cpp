#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef map<long long, long long> mii;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<long long>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1;                   // add 1 to include upperbound
	bs.set();                                                 // set all bits to 1
	bs[0] = bs[1] = 0;                                     // except index 0 and 1
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		// cross out multiples of i starting from i * i!
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);  // also add this vector containing list of primes
	} 
}

pair<long long,long long> genpq(long long n){
	for(auto prime: primes){
		if(n%prime==0){
			return {n/prime,prime};
		}
	}
	return {0,0};
}

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


vector<long long> egcd(long long n, long long m)
{
    long long r0 = n, r1 = m;
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;

    while(r1 != 0)
    {
        long long q = r0/r1;
        long long r = r0 - q*r1; r0 = r1; r1 = r;
        long long s = s0 - q*s1; s0 = s1; s1 = s;
        long long t = t0 - q*t1; t0 = t1; t1 = t;
    }

    return {r0,s0,t0};
}

int main(){
	sieve(1e6);
	long long n,e,c;
	while(cin>>n>>e>>c){
		pair<long long,long long> pq =genpq(n);
		long long phi = (pq.first-1)*(pq.second-1);
		//cout<<"phi= "<<phi<<"\n";
		auto ansv = egcd(e,phi);
		long long d = (ansv[1]%phi+phi)%phi;
		//cout<<"d= "<<d<<"\n";
		cout<<fastPow(c,d,n)<<"\n";
	}
	return 0;
}