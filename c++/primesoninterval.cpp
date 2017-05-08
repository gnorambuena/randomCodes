#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <set>
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

vector<int>numprimes;

void genNumPrimes(){
	int num = 0;
	numprimes.assign(1e7,0);
	for(int i = 0; i < numprimes.size(); i++){
		if(bs[i])num++;
		numprimes[i] = num;
	}
}

int primesOnInterval(int i,int j){
	//cout<<"primes on interval="<<numprimes[j]-numprimes[i-1]<<"\n";
	return numprimes[j]-numprimes[i-1];
}

bool check(int a,int b,int l,int k){
	//cout<<"l="<<l<<"\n";
	for(int i = a; i <= b-l+1;i++){
		//cout<<i<<"\n";
		int r = l+i-1;
		if(primesOnInterval(i,r) < k)
			return false;
	}
	return true;
}
int main(){
	sieve(1e6);
	genNumPrimes();
	int a,b,k;
	cin>>a>>b>>k;
	int l = 1;
	int r = b-a+1;
	int m = (r+l)/2;
	if(primesOnInterval(a,b)<k)cout<<-1<<"\n";
	else{
		for(int i = 0; i < 32 ; i++){
			//cout<<r<<" "<<m<<" "<<l<<"\n";
			if(check(a,b,m,k)){
				//cout<<"true\n";
				r = m;
			}else{
				//cout<<"false\n";
				l = m+1;
			}
			m = (r+l)/2;
		}
		cout<<m<<"\n";
	}
	return 0;
}