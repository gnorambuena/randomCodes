#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

std::vector<int> primes;

/// Set your CPU's L1 data cache size (in bytes) here
const int L1D_CACHE_SIZE = 32768;

void segmented_sieve(int64_t limit)
{
  int sqrt = (int) std::sqrt(limit);
  int segment_size = std::max(sqrt, L1D_CACHE_SIZE);

  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 3;
  int64_t n = 3;
  //std::cerr<<"asd\n";
  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;
   //std::cerr<<"asd\n";
  // vector used for sieving
  std::vector<char> sieve(segment_size);

  std::vector<int> next;
  primes.push_back(2);
  //std::cerr<<"asd\n";
  for (int64_t low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, limit);

    // add new sieving primes <= sqrt(high)
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    //std::cerr<<"asd\n";
    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    //std::cerr<<"asd\n";
    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
        count++;
  }
  std::cerr<<"asd\n";
  //std::std::cerr << count << " primes found." << std::endl;
}

/// Usage: ./segmented_sieve n
/// @param n  Sieve the primes up to n.
///
int main(int argc, char** argv)
{
    std::cin.tie(0);std::ios::sync_with_stdio(0);
    int t;
    segmented_sieve(2147483647);
    std::cin>>t;
    while(t--){
        int L,U;
        std::cin>>L>>U;
        long long left=0,right=primes.size()-1;
        while(right-left>3){
            long long m=(left+right)/2;
            if(primes[m]<L)
                left=m;
            else 
                right=m;
        }
        while(primes[left+1]<=L)left++;
        for(;primes[left]<=U;left++){
            if(primes[left]!=0)
                std::cout<<primes[left]<<"\n";
        }
    }

  return 0;
}