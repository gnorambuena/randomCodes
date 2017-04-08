#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	map<char,string>alphabet;
	for(int i = 0 ; i < 26 ; i++){
		char key;
		string value;
		cin>>key>>value;
		alphabet[key] = value;
	}
	int n;
	map<string,string> dictionary;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		string mapped;
		for(int j = 0 ; j < s.size() ; j++){
			string aux = alphabet[s[j]];
			mapped.append(aux);
		}
		dictionary[mapped] = s;
	}
	int k;
	while(cin>>k){
		if(k==0)break;
		string words;
		bool flag = true;
		for(int i = 0 ; i < k ; i++){
			string s;
			cin>>s;
			if(dictionary.count(s)>0){
				words.append(dictionary[s]);
				if(i+1!=k)
					words.push_back(' ');
			} else {
				cout<<s<<" not in dictionary.\n";
				flag = false;
				i++;
				for(; i < k ;i++){
					cin>>s;
					//cout<<s<<"\n";
				}
			}
		}
		if(flag){
			cout<<words<<"\n";
		}
	}
	return 0;
}