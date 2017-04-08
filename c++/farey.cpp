#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;
vector<int>criba(10001,-1);
vector<int>phiacc(10001,-1);
void crib(){
	criba[0]=0;criba[1]=1;criba[2]=2;
	for(int i = 2 ; i < criba.size() ; i++){
		for(int j = i ; j < criba.size() ; j+=i){
			if(criba[j]==-1){
				criba[j]=i;
			}
		}
	}
}

long long phi(int k){
	set<int>primes;
	int p = criba[k];
	int aux = k;
	do{
		p = criba[aux];
		primes.insert(p);
		aux/=p;
	}while(aux!=criba[aux]);
	primes.insert(aux);
	primes.erase(1);
	int res = k;
	for(auto it : primes){
		res*=(it-1);
	}
	for(auto it : primes){
		res/=it;
	}
	return res;
}

void genphi(){
	phiacc[1]=phi(1);
	for(int k = 2 ; k <= 10000 ; k++){
		phiacc[k]=phi(k)+phiacc[k-1];
	}
}
int main(){
	crib();
	genphi();
	//copy(criba.begin(),criba.end(),ostream_iterator<int>(cout," "));cout<<"\n";
	int P;
	cin>>P;
	while(P--){
		int K,n;
		cin>>K>>n;
		cout<<K<<" "<<phiacc[n]+1<<"\n";
	}
}