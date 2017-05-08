#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <climits>
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

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > matrix(n,vector<int>(m,0));
	for(auto &a:matrix)
		for(auto &b:a)
			cin>>b;
	long long ans = INT_MAX;
	sieve(1e6);
	for(int i = 0 ; i < matrix.size(); i++){
		long long cur = 0;
		for(int j = 0 ; j < matrix[i].size() ; j++){
			auto it = lower_bound(primes.begin(),primes.end(),matrix[i][j]);
			cur+= (*it)-matrix[i][j];
			//cout<<matrix[i][j]<<" "<<(*it)<<"\n";
		}
		ans = min(ans,cur);
		//cout<<ans<<"\n";
	}
	for(int j = 0 ; j < matrix[0].size(); j++){
		long long cur = 0;
		for(int i = 0 ; i < matrix.size() ; i++){
			auto it = lower_bound(primes.begin(),primes.end(),matrix[i][j]);
			cur+= (*it)-matrix[i][j];
		}
		ans = min(ans,cur);

		//cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}