#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int k = 1 ; k <= n ; k++){
		string s;
		cin>>s;
		vector<vector<int> > pos('z'-'a'+1,vector<int>());
		for(int i = 0 ; i < s.size() ; i++){
			char c = s[i];
			pos[c-'a'].push_back(i); 
		}
		int check = 0;
		for(auto v : pos){
			if(v.size()==1)check++;
		}
		if(check==s.size()){
			cout<<"Case #"<<k<<": -1\n";
			continue;
		}
		int mmin = INT_MAX;
		for(auto v : pos){
			if(v.size()!=1){
				int dist;
				for(int i = 1 ; i < v.size() ; i++){
					dist = v[i]-v[i-1];
					mmin = min(dist,mmin);
				}
			}
		}
		cout<<"Case #"<<k<<": "<<mmin<<"\n";
	}
	return 0;
}