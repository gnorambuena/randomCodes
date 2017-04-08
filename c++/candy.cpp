#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int mmax = 0;
vector<vector<int> > table;
vector<vector<int> > c;
void backtracking(int ans){
	cout<<ans<<"\n";
	for(int i = 0 ; i < c.size() ; i++){
			for(int j = 0 ; j < c[0].size() ; j++){
				cout<<table[i][j]<<" ";
			}
			cout<<"\n";
	}
	if(table==c){
		mmax=max(mmax,ans);
		return ;
	}
	else{
		for(int i = 0 ; i < table.size() ; i++){
			for(int j = 0 ; j < table[i].size() ; j++){
				vector<int>upper;
				vector<int>lower;
				int izq=-1,der=-1;
				if(i>0){
					upper = table[i-1];
					table[i-1] = vector<int>(upper.size(),0);
				}
				if(i+1<table.size()){
					lower = table[i+1];
					table[i+1] = vector<int>(upper.size(),0);
				}
				if(j>0){
					izq = table[i][j-1];
					table[i][j-1]=0;
				}
				if(j+1<table[i].size()){
					der = table[i][j+1];
					table[i][j+1]=0;
				}
				backtracking(ans+table[i][j]);
				if(i>0){
					table[i-1] = upper;
				}
				if(i+1<table.size()){
					table[i+1] = lower;
				}
				if(j>0){
					table[i][j-1] = izq;
				}
				if(j+1<table[i].size()){
					table[i][j+1] = der;
				}
			}
		}
	}
	return ;
}
int main(){
	int n,m;
	while(cin>>n>>m && n!=0 && m!=0){
		table.assign(m,vector<int>(n));
		c.assign(m,vector<int>(n,0));
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				cin>>table[i][j];
			}
		}
		for(int i = 0 ; i < c.size() ; i++){
			for(int j = 0 ; j < c[0].size() ; j++){
				cout<<c[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"asdasd\n";
		backtracking(0);
		cout<<mmax;
	}
	return 0;
}