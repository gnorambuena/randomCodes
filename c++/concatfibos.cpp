#include <iostream>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
vector<ll>fib;
vector<string>concatfibos;
void fibonacci(){
	fib.assign(91,0);
	fib[0]=0;
	fib[1]=1;
	for(int i = 2 ; i < fib.size() ; i++)
		fib[i]=fib[i-2]+fib[i-1];
	cerr<<"fibos generated"<<endl;
}
void gen_concatfibos(){
	fibonacci();
	for(int i = 0; i < fib.size() ; i++)
		for(int k = 0 ;k < fib.size() ; k++){
			if(i!=k){
				string s=to_string(fib[i]);
				s+=to_string(fib[k]);
				concatfibos.push_back(s);
			}
		}
	cerr<<"concatfibos generated"<<endl;
}
int main(){
	gen_concatfibos();
	cerr<<concatfibos.size()<<endl;
	//vector<set<int>> 
	return 0;
}