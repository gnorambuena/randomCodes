#include <iostream>
using namespace std;
void xorSwap (int *x, int *y) {
     *x^=*y^(*y=*x);
 }
int main(){
	int a,b;
	cin>>a>>b;
	cout<<"a="<<a<<" b="<<b<<"\n";
	xorSwap(&a,&b);
	cout<<"a="<<a<<" b="<<b<<"\n";
	return 0;	
}