#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <string>
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

vector<int>divisors(int n){
	set<int>ans;
	for(auto prime:primes){
		if(prime>n)break;
		if(n%prime==0){
			for(int i = 1; prime * i <= n ; i++){
				if(n%(prime*i)==0)
					ans.insert(prime*i);
			}
		}
	}
	vector<int> res = {1};
	for(auto &a:ans){
		res.push_back(a);
	}
	return res;
}

int main(){
	sieve(200);
	string s;
	cin>>s;
	vector<int>div = divisors(s.size());
	//for(auto el:div)cout<<el<<" ";
	//cout<<"\n";
	set<char>totalletters;
	for(char c:s)
		totalletters.insert(c);
	string res = "";
	for(int i = 0; i < div.size() && res=="" ; i++){
		vector<string>candidates;
		for(int j = 0 ; j + div[i] < s.size(); j++){
			string candidate = s.substr(j,div[i]);
			set<char>letters;
			for(char c: candidate)
				letters.insert(c);
			if(letters == totalletters){
				//cout<<candidate<<"\n";
				candidates.push_back(candidate);
			}
		}
		sort(candidates.begin(),candidates.end());
		//cout<<"asdasd\n";
		for(string candidate: candidates){
			//cout<<"testing candidate: "<<candidate<<"\n";
			string s2 = s;
			bool ans = 0;
			while(true){
				string aux = s2;
				for(int j = 0 ; j + candidate.size() < s2.size() ; j++){
					if(s2.substr(j,candidate.size())==candidate){
						//cout<<"erasing: "<<candidate<<" from "<<s2;
						s2.erase(j,candidate.size());
						//cout<<" result: "<<s2<<"\n";
						break;
					}
				}
				if(s2==candidate){
					res = candidate;
					ans = true;
					//cout<<"res:"<<candidate<<"\n";
					break;
				}
				if(aux==s2)break;
			}
			if(ans)break;
		}
	}
	if(res=="")cout<<s<<"\n";
	else	
		cout<<res<<"\n";
	return 0;
}