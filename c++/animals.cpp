#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>matrix(n,vector<int>(m,0)){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin>>matrix[i][j];
			}
		}
	}
	return 0;
}