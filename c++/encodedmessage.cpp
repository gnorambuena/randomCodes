#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = sqrt(s.size());
		vector<vector<char> > matrix(n,vector<char>(n));
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				matrix[i][j] = s[n*i+j];
				//cout<<matrix[i][j];
			}
			//cout<<"\n";
		}
		string ans;
		for(int j = n-1 ; j>=0 ; j--){
			for(int i = 0 ; i < n ; i++){
				ans.push_back(matrix[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}