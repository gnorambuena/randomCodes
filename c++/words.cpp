#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isSuffix(string a,string b,int index){
	//cerr<<"checking from "<<index<<endl;
	for(int i = index ; i < min(a.length(),b.length()) ; i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
bool backtrack(string a,string b,vector<string>&vsa,vector<string>&vsb){
	//cerr<<"BACKTRACKING WITH "<<a<<" "<<b<<endl;
	if(a.length() >=100 || b.length() >= 100)return false;
	if(a==b && a!="" && b!=""){
		cerr<<a<<endl;
		return true;
	}
	else{
		if(a.length()>b.length()){
			string aux = b;
			bool res = false;
			int index = b.length();
			for(int i = 0 ; i < vsb.size() ; i++){
				aux.append(vsb[i]);
				//cerr<<a<<" "<<aux<<endl;
				if(aux==a)return true;
				if(isSuffix(aux,a,index)){
					res = res || backtrack(a,aux,vsa,vsb);
				}					
				aux = b;
			}
			//cerr<<"ggg"<<endl;
			return res;
		}
		else{
			string aux = a;
			bool res = false;
			int index = a.length();
			for(int i = 0 ; i < vsa.size() ; i++){
				aux.append(vsa[i]);
				//cerr<<aux<<" "<<b<<endl;
				if(aux==b)return true;
				if(isSuffix(aux,b,index)){
					res = res || backtrack(aux,b,vsa,vsb);
				}					
				aux = a;
			}
			//cerr<<"fff"<<endl;
			return res;
		}
	}
	//cerr<<"asdasd"<<endl;
	return false;
}
int main(){
	int n1,n2;
	cin.tie(0);ios::sync_with_stdio(0);
	while(cin>>n1>>n2){
		vector<string>vsa,vsb;
		for(int i = 0 ; i < n1 ; i++){
			string a;
			cin>>a;
			vsa.push_back(a);
		}
		for(int i = 0 ; i < n2 ; i++){
			string b;
			cin>>b;
			vsb.push_back(b);
		}
		bool flag = backtrack("","",vsa,vsb);
		cout<<(flag?"S":"N")<<"\n";
	}
	return 0;
}