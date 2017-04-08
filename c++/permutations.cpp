#include <iostream>
#include <vector>
using namespace std;

int lastsorted(vector<int>&numbers){
	int c = numbers[0];
	for(int i = 1 ; i < numbers.size() ;i++){
		if(numbers[i]>=c){
			c = numbers[i];
		}
		else{
			return i;
		}
	}
	return numbers.size()-1;
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int>first(n),second(n);
	vector<int>secondpos(n+1);
	for(int &el:first)cin>>el;
	for(int &el:second)cin>>el;
	if(first==second){
		cout<<0<<"\n";
		return 0;
	}
	for(int i = 0; i < n ; i++){
		secondpos[second[i]]=i;
	}
	for(int i = 0 ; i < first.size() ; i++){
		first[i]=secondpos[first[i]];
	}
	cout<<first.size()-lastsorted(first)<<"\n";
	return 0;
}