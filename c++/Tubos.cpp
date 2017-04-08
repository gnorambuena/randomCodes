#include <bits/stdc++.h>
using namespace std;

double dis(double A, double B){
	return 2 * sqrt(A*B);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);
	int n;
	double maxi, aux;
	while(cin >> n){
		vector <double> R(n);
		vector <double> C(n,0);
		for(int i = 0; i < n; i++){
			cin >> R[i];
		}
		C[0] = R[0];
		for(int i = 1; i < n; i ++){
			maxi = R[i];
			for(int ii = i - 1; ii >= 0; ii--){
				aux = dis(R[i], R[ii]);
				if(aux + C[ii] > maxi){
					maxi = aux + C[ii];
				}
			}
			C[i] = maxi;
		}
		maxi = 0;
		for(int i = 0; i < n; i++){
			if(C[i] + R[i] > maxi){
				maxi = C[i] + R[i];
			}
		}
		cout << maxi << "\n";
	}
}
