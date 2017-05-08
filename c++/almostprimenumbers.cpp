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

vector<long long>almostprimes;
void genAns(){
	sieve(1e6);
	for(long long prime: primes){
		long long pot = prime * prime;
		while(pot<1e12L){
			almostprimes.push_back(pot);
			pot*=prime;
		}
	}
	sort(almostprimes.begin(),almostprimes.end());
}

long long res(long long low, long long high){
	int ans = 0;
	auto it = lower_bound(almostprimes.begin(),almostprimes.end(),low);
	auto it2 = lower_bound(almostprimes.begin(),almostprimes.end(),high);
	if(it2!=almostprimes.end())
		ans = (long long)(it2-it);
	else{
		ans = almostprimes.size()-(it-almostprimes.begin());
	}
	return ans;
}
int main(){
	int n;
	genAns();
	cin>>n;
	while(n--){
		long long low,high;
		cin>>low>>high;
		cout<<res(low,high)<<"\n";
	}
	return 0;
}