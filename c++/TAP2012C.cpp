#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
long long B, L, R;
string s;
vector <int> pueden;

vector <int> Base(int n){
	vector <int> a;
	long long k = 1, cap = 0;
		while(k * B <= n){
			k *= B;
			cap++;
		}
	for(int ii = 0; ii <= cap; ++ii){
		long long c = 0;
		while(n >= k){
			n -= k;
			c++;
		}
		a.push_back(c);
		k /= B;
	}
	return a;
}

long long f(long long x){
	long long can = pueden[B - 1] - pueden[0], k = B, answ = can;
	if(x == 0){
		return 0;
	}
	while(k * B <= x){
		can = can * pueden[B - 1];
		answ += can;
		k *= B;
	}
	vector <int> a = Base(x);
	long long aux = 1;
	for(int i = 0; i < a.size(); i++){
		if(i != (int) a.size() - 1){
			aux *= pueden[B - 1];
		}
		else{
			aux *= pueden[a[i]] - pueden[0];
		}
	}
	answ += aux;
	return answ;
}

int main(){
	while(cin >> L >> R >> B >> s && s != "*"){
		L--;
		pueden.clear();
		pueden.resize(B,0);
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'S'){
				pueden[i]++;
			}
			if(i != 0) pueden[i] += pueden[i - 1];
		}
		if(pueden[B - 1] == B){
			cout << R - L << "\n";
			continue;
		}
		cout << f(R) - f(L) << "\n";
	}
}