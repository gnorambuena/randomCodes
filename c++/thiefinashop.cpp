#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<vector<int> >mysetvi;
set<int>myset;
vector<int>res;
void backtrack(vector<int>&products,vector<int>rres,int k,int val){
	//cout<<val<<endl;
	if(k==0){
		sort(rres.begin(),rres.end());
		if(mysetvi.find(rres)==mysetvi.end() && myset.find(val)==myset.end()){
			res.push_back(val);
			mysetvi.insert(rres);
			myset.insert(val);
		}
		return ;
	}
	else{
		for(int &a:products){
			vector<int>aux=rres;
			aux.push_back(a);
			backtrack(products,aux,k-1,val+a);
		}
	}
	return;
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	vector<int>products(n);
	for(int &a :products)cin>>a;
	vector<int>rres;
	backtrack(products,rres,k,0);
	sort(res.begin(),res.end());
	for(int &a: res){
		cout<<a<<" ";
	}
	cout<<"\n";
	return 0;
}