#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tamano;
bitset<1000010> bs;
vector<int> primos;

void criba (ll n){
	tamano = n +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i<= tamano; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= tamano; j += i) bs[j] = 0;
			primos.push_back((int) i);
		}
}


int main(){
	
	criba(1000000);

	int n;
	cin >> n;


	int divisible = 0;
	
	for (int i = n; i >= 0; i--){
		for (int j = 0; j < primos.size(); j++){
			if ( i%primos[j] == 0 && i != primos[j]){
				divisible = 1;
			}
		}
		if (divisible){
			divisible = 0;
			continue;
		}
		else{
			cout << i << endl;
			break;
		}
	}

	
	return 0;
	}