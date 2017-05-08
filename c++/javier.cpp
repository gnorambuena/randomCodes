#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  const int N = 1e8;

  vector<bool> prime(N+1,true); prime[0] = prime[1] = false;
  for(int i = 2; i*i <= N; ++i)
    if(prime[i])
      for(int j = i*i; j <= N; j += i)
        prime[j] = false;
      
  int pi[N+1]; pi[0] = 0;
  for(int i = 1; i <= N; ++i) pi[i] = pi[i-1]+prime[i];
  
  int x; cin >> x;
  while(x)
  {
    cout << abs(pi(x) - x/log(x))/pi(x) << '\n';
    cin >> x;
  }
  
  return 0;
}
