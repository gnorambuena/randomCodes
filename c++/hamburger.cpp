#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
long long B=0,S=0,C=0;
long long nb,ns,nc,pb,ps,pc;
long long r;

long long max(long long a, long long b){
	return a>b?a:b;
}

long long min(long long a, long long b){
	return !max(a,b);
}
bool canMake(long long n){
	long long auxb,auxs,auxc;
	auxb = n*B; auxs = n*S; auxc = n*C;
	auxb-=nb;auxs-=ns;auxc-=nc;
	auxb=max(auxb,0);
	auxc=max(auxc,0);
	auxs=max(auxs,0);
	return r-(auxb*pb+auxs*ps+auxc*pc)>=0;
}
int main(){
	string s;
	cin>>s;
	for(char c: s){
		if(c=='B')
			B++;
		if(c=='S')
			S++;
		if(c=='C')
			C++;
	}
	cin>>nb>>ns>>nc>>pb>>ps>>pc;
	cin>>r;
	long long left = 0;
	long long right = 1000L*(long long)INT_MAX;
	long long m = (left+right)/2;
	for(int i = 0 ; i < 64 ; i++){
		if(canMake(m)){
			left=m+1;
		}else{
			right=m-1;
		}
		m = (left+right)/2;
	}
	cout<<m<<"\n";
	return 0;
}