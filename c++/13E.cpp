#include <vector>
#include <iostream>
#define REP(i,n) for(int i = 0; i < n; ++i)
#define RREP(i,n) for(int i = n; i >= 0; --i)
#define RRAP(i,a,n) for(int i = n; i > a; --i)
using namespace std;

typedef vector <int> vi;

int Sqrt(int n){
	int CS = n, CI = 0, M = (CS + CI)/2;
	while(CS - CI > 3){
		bool p = M*M > n;
		CI = (p ? CI : M);
		CS = (p ? M : CS);
		M = (CI + CS)/2;
	}
	while(CI*CI < n){
		CI++;
	}
	return CI - 1;
}

int main(){
	int n, q;
	cin >> n >> q;
	int SN = Sqrt(n);
	vi A(n,0), S(n,0), I(n,0);
	REP(i,n){
		cin >> A[i];
	}
	RREP(i,n-1){
		if(A[i] + i > n){
			S[i] = 1;
			I[i] = i;
		}else{
			S[i] = 1 + S[A[i] + i];
			I[i] = I[A[i] + i];
		}
	}
	REP(jj,q){
		int a; cin >> a;
		if(a == 0){
			int i, j;
			cin >> i >> j; i--;
			A[i] = j;
			if(i + A[i] > n){
				I[i] = i;
				S[i] = 1;
			}else{
				if(i / SN == (i + A[i]) / SN){
					I[i] = I[i + A[i]];
					S[i] = S[i + A[i]] + 1;
				}else{
					I[i] = i + A[i];
					S[i] = S[i + A[i]] + 1;
				}
				RRAP(ii,SN*(i/n), SN*(i/n + 1)){
					if(ii + A[ii] < SN*(i/n + 1)){
						I[ii] = I[ii + A[ii]];
						S[ii] = S[ii + A[ii]] + 1;	
					}
				}
			}
		}
		if(a == 1){
			int i; cin >> i; i--;
			int cuenta = S[i];
			while(i < SN * (SN - 1)){
				i =  I[i];
				cuenta += (S[i]);
			}
			cout << I[i] + 1 << " " << cuenta << "\n";
		}
	}
	return 0;
}