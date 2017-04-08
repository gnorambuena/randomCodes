#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<int>vi;
	for(int i = 0; i < s.size() ; i++){
		if(s[i]!='+')
			vi.push_back(s[i]-'0');
	}
	sort(vi.begin(),vi.end());
	for(int i = 0; i < vi.size(); i++){
		cout<<vi[i]<<(i!=vi.size()-1?"+":"");
	}
	cout<<endl;
	return 0;
}