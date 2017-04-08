#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 int main(){
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	int N;
 	while(cin >> N && N != -1){
 		int answ = 0;
 		if(N == 1){
 			cout << 1 << endl;
 			continue;
 		}
 		for(int i = 1; i <= N; ++i){
 			for(int j = 1; j <= i && j*j <= N; ++j){
 				if((N - i*j) % (i + j) == 0){
 					int b = (N - i*j) / (i + j);
 					if(b <= j && b >= 0) answ++;
 				}
 			}
 		}
 		cout << answ << "\n";
 	}
 }