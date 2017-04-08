#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=0){
		vector<pair<int,int> > points;
		map<pair<int,int>,int>id;
		vector<int>edges(n+1,-1);
		for(int i = 0 ; i < n ; i++){
			pair<int,int> p;
			cin>>p.first>>p.second;
			points.push_back(p);
			id[p]=id.size();
		}
		sort(points.begin(),points.end());
		for(int i = 0 ; i < n ; i++){
			cout<<id[points[i]]<<endl;
		}
	}
	return 0;
}