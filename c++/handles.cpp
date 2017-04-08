#include <iostream>
#include <map>
#include <string>
#define rep(n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int q;
	map<string,string>mapa;
	cin>>q;
	rep(q){
		string old,neww;
		cin>>old>>neww;
		map<string,string>::iterator it=mapa.begin();
		while(it->second!=old && it!=mapa.end()){
			++it;
		}
		if(it==mapa.end()){
			mapa[old]=neww;
		}
		else{
			mapa[it->first]=neww;
		}
	}
	cout<<mapa.size()<<endl;
	map<string,string>::iterator it=mapa.begin();
	while(it!=mapa.end()){
		cout<<it->first<<" "<<it->second<<endl;
		++it;
	}
	return 0;
}