#include <iostream>
using namespace std;

bool primality(int n){
	for(int i = 2 ; i*i <= n ; i++) {
		if(n%i==0)return false;
	}
	return true;
}
int main(){
	int n;
	for(int i = 2; i < 10000000 ; i++){
		n = primality(i);
	}
}