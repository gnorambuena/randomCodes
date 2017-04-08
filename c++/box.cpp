#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,ans=100;
	cin>>n;
	vector<int>boxes(n);
	for(int &box : boxes)cin>>box;
	sort(boxes.begin(),boxes.end());
	while(ans>0){
		for(int i = 0 ; i < boxes.size() ; i++)
			if(boxes[i]<i/ans){
				cout<<ans+1<<endl;
			return 0;}
	ans--;}
	cout<<1<<"\n";
	return 0;
}