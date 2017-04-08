#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int s,m;
	cin>>m>>s;
	string max="";
	if(s==0 && m==1){
		cout<<"0 0"<<endl;
		return 0;
	}
	if( (s==0)||(m==0) || (m*9<s)){
		cout<<"-1 -1\n";
		return 0;}
	int x=s/9;
	for(int i = 0 ; i < x ; i++){
		max.append("9");
	}
	if(s%9!=0)max.push_back((char)(s%9 +'0'));
	while(max.size()<m){
		max.append("0");
	} 
	string min="";
	int y = (s-1)/9;
	for(int i = 0 ; i < y ; i++){
		min.append("9");
	}
	if(min.size()+1==m){
		if(s%9!=0)
		min.push_back((char)(s%9 + '0'));
	    else min.push_back((char)((s-y*9) + '0'));
	}
	else{
		min.push_back((char)((s-1)%9 + '0'));
		while(min.size()+1<m){
			min.append("0");
		}
		min.push_back('1');
	}
	reverse(min.begin(),min.end());
	cout<<min<<" "<<max<<endl;
	return 0;
}