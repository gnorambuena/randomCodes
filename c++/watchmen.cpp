#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
	pair<int,int>point;
	map<int,int>horizontal,vertical;
	map<pair<int,int>,int>puntos;
	int n;
	cin>>n;
	int count=0;
	for(int i=0;i<n;i++){
		cin>>point.first>>point.second;
		horizontal[point.first]++;
		vertical[point.second]++;
		puntos[point]++;
	}
	for(map<int,int>::iterator it=horizontal.begin();it!=horizontal.end();++it){
		int k=horizontal[p.first]-1;
	}
	cout<<count<<endl;
}
