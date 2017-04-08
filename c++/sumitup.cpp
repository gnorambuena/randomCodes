#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
vector<vector<int> > sol;
set<vector<int> > myset;
void backtrack(vector<int>&lista,vector<int>res,vector<int>numberOfElements,int val){
	/*cout<<res.size()<<endl;
	copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
	cout<<endl;*/
	int ans = 0;
	for(int &a : res){
		ans+=a;
	}
	if(ans>val){
		//cerr<<"backtracking\n";
		return;}
	else if(ans==val && myset.find(res)==myset.end()){
		sort(res.begin(), res.end() , greater<int>());
		sol.push_back(res);
		myset.insert(res);
		return ;
	}
	else{
		for(int &K : lista){
			if(numberOfElements[K]>0){
				vector<int>aux = res;
				aux.push_back(K);
				numberOfElements[K]--;
				backtrack(lista,aux,numberOfElements,val);
			}
		}
	}
	return ;
}
int main(){
	int t,n;
	while(cin>>t>>n && n!=0){
		sol.clear();
		myset.clear();
		vector<int>list(n);
		vector<int>res;
		vector<int>numberOfElements(110,0);
		for(int &a : list){
			cin>>a;
			numberOfElements[a]++;
		}
		cout<<"Sums of "<<t<<":\n";
		backtrack(list,res,numberOfElements,t);
		if(sol.size()==0)cout<<"NONE\n";
		else{
			sort(sol.begin(),sol.end(),greater<vector<int> > ());
			for(int i = 0 ; i < sol.size() ; i++){
				for(int j = 0 ; j < sol[i].size() ; j++){
					int a = sol[i][j];
					cout<<a;
					if(j+1!=sol[i].size())cout<<"+";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}