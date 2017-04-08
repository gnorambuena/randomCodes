#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
void print(int k, int i = 0) {
	if(i == k) {
		bool flag = false;
		for(int j = k-1; j >= 0; --j)
			if(V[j]){
				flag = true;
				cout << (V[j] > 0 ? " + " : " - ") << abs(V[j]);
				if(j > 0)
					cout << "x^" << j << ' ';
			}
		if(flag)
			cout << '\n';
		return;
	}

	for(int j = -k; j <= k; ++j){
		V[i] = j;
		print(k,i+1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*borrar el k < 6 para imprimir todos los polinomios*/
	for(int k = 1; ; ++k){
		V.resize(k);
		print(k);
	}
	return 0;
}