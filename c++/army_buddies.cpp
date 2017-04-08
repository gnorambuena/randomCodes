#include <iostream>
#include <vector>

using namespace std;

int main(){
	int s, b;
	while(cin >> s >> b){
		vector<int> L(s + 2,0);
		vector<int> R(s + 2,0);

		L[0] = 0;
		R[0] = 1;

		for(int i = 1 ; i <= s+1;i++){
			L[i] = i-1;
			R[i] = i+1;
		}
		for(int i = 0; i < b ; i++){
			int l, r;
			cin >> l >> r;
			
			R[L[l] ] = R[r];
			L[R[r] ] = L[l];


			if(L[l] <= 0 ) cout << "* "; 
			else cout << L[l] << " ";

			if(R[r] > s ) cout << "*\n";
			else cout << R[r] << "\n";
		}
		cout << "-\n";
	}
}