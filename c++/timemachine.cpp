#include <iostream>
#include <vector>
#include <string>
#define NOT_VISITED 0
#define VISITED 1
using namespace std;
int main(){
	int n;
	cin>>n;
	string Strip;
	vector<bool>Visited(n,NOT_VISITED);
	vector<int>Jump(n);
	cout<<"Asd"<<endl;
	cin>>Strip;
	for(int i=0;i<n;i++){
		cin>>Jump[i];
	}
	int i=0;
	while(i<n && i>=0){
		if(Visited[i]!=NOT_VISITED){
			cout<<"INFINITE"<<endl;
			return 0;
		}
		Visited[i]=VISITED;
		if(Strip[i]=='>'){
			i+=Jump[i];
		}
		else{
			i-=Jump[i];
		}
	}
	cout<<"FINITE"<<endl;
	return 0;
}
