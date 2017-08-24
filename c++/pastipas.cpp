#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const ll b = 127, MOD = 1e9+7;
const int N = 5e5;
ll B[N+1];

struct RollingHash
{
  vector<ll> H;

  RollingHash(string &S)
  {
    int N = S.size();
    H.resize(N+1); H[N] = 0;
    for(int i = N-1; i >= 0; --i)
      H[i] = ((S[i]-'A')+b*H[i+1])%MOD;
  }

  ll hash(int i, int k)
  {
    return (H[i]-B[k]*H[i+k]%MOD+MOD)%MOD;
  }
};

int main(){
    B[0] = 1; 
    for(int i = 1; i <= N; ++i) B[i] = b*B[i-1]%MOD;
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int m = 1 ; m <= t ; m++){
        string s;
        cin>>s;
        RollingHash rh(s);
        int ans = 0;
        int i = 0;
        int j = 1;
        while(i+j-1 < s.size()-i-j){
            //cout<<"i = "<<i<<"\n"
                //cout<<s.substr(i,j)<<" "<<s.substr(s.size()-i-j,j)<<"\n";
            if(rh.hash(i,j)==rh.hash(s.size()-i-j,j))
            {
                //cout<<s.substr(i,j)<<" "<<s.substr(s.size()-i-j,j)<<"\n";
                //cout<<"suffix start "<<s.size()-i-j<<"\n";
                //cout<<"match: "<<i<<"\n";
                //cout<<"largo: "<<j<<"\n";
                ans+=2;
                i+=j;
                j = 1;
            }else{
                j++;
            }
        }
        //cout<<lastmatch<<"\n";
        //cout<<ans<<"\n";
        //cout<<s.size()<<"\n";
        cout<<"Case #"<<m<<": ";
        if(i<=s.size()-i-1){
            cout<<ans+1<<"\n";
        }else
            cout<<ans<<"\n";
    }
    return 0;
}