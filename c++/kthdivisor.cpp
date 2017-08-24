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

vector<ll>divisors(ll N){
    vector<ll>s;
    vector<ll>rs;
    for(ll i = 1; i*i <= N ; i++){
        if(N%i==0){
            s.push_back(i);
            if(i*i!=N)
                rs.push_back(N/i);
        }
    }
    reverse(rs.begin(),rs.end());
    vector<ll>res;
    merge(s.begin(),s.end(),rs.begin(),rs.end(),back_inserter(res));
    return res;
}
int main(){
  ll n,k;
  cin>>n>>k;
  auto s = divisors(n);
  //for(auto el: s)cout<<el<<" ";
  //  cout<<"\n";
  //cout<<s.size()<<"\n";
  if (s.size() >= k){
    cout<<s[k-1]<<"\n";
  }else{
    cout<<-1<<"\n";
  }
  return 0;
}