#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		string presentname;
		int i = 1;
		char apostrofe = '\'';
		while(s[i]!=apostrofe){
			presentname.push_back(s[i++]);
		}
		s.erase(s.begin(),s.begin()+i+2);
		stringstream ss(s);
		long long a,b,c,p;
		ss>>a>>b>>c>>p;
		long long ans = 2*a*b+2*b*c+2*a*c+6*b+3*c;
		string res = to_string(ans);
		for(int i = p; i < res.size(); i++){
			res[i] = '0';
		}
		cout<<"\"The Present "<<presentname<<" requires "<<res<<" square frightometers of paper to wrap\"\n";
	}
	return 0;
}