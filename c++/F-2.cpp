#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N,empR = 0, terD = 0, sanD = 0,DR = 0; cin >> N;
	vector <string> A(N);
	for(int i = 0;i < N; i++){
		cin >> A[i];
		bool PD = false, PR = false, FD = false, FR = false;
		for(int ii = 0; ii < A[i].size(); ii++){
			if(A[i][ii] == 'R'){
				if(!PD && !PR){
					PR = true;	
				}
				if(FD){
					DR++;
					FD = false;
				}else{	
					FR = true;
					FD = false;
				}
			}
			if(A[i][ii] == 'D'){
				if(!PD && !PR){
					PD = true;
				}

				FR = false;
				FD = true;
			}
		}
		if(PR && FD){
			sanD++;
		}else if(PR){
			empR++;
		}else if(FD){
			terD++;
		}
	}
	cout << (DR + max(sanD - 1, 0) + min(empR, terD) + ((empR != 0 || terD != 0) && empR != terD && sanD != 0 ? 1 : 0) ) << '\n';
	return 0;
}