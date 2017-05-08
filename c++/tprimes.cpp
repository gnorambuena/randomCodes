#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>


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
set<long long>tprimes;
void genAns(){
	for(long long prime: primes){
		tprimes.insert(prime*prime);
		//cout<<prime<<" "<<prime*prime<<"\n";
	}
}
int main(){
	sieve(1e7);
	genAns();
	int n;
	cin>>n;
	while(n--){
		long long a;
		cin>>a;
		cout<<(tprimes.count(a)?"YES\n":"NO\n");
	}
	return 0;
}