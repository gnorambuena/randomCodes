#include <iostream>
using namespace std;
int main(){
	long long a,b,c,d;
	while(cin>>a>>b>>c>>d){
		if(a == -1 && b == -1 && c == -1 && d == -1)
			break;
		if(a == -1){
			int sumconstant = c-b;
			int mulconstant = c/b;
			if (c+sumconstant == d && b-sumconstant > 0){
				cout<<b-sumconstant<<"\n";
			}else if (c*mulconstant == d && b/mulconstant > 0){
				cout<<b/mulconstant<<"\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		if(b == -1){
			int sumconstant = d-c;
			int mulconstant = d/c;
			if (c-sumconstant == a+sumconstant && c-sumconstant > 0){
				cout<<c-sumconstant<<"\n";
			}else if (c/mulconstant == a*mulconstant && c/mulconstant > 0){
				cout<<c/mulconstant<<"\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		if(c == -1){
			int sumconstant = b-a;
			int mulconstant = b/a;
			if (d-sumconstant == b+sumconstant && d-sumconstant > 0){
				cout<<d-sumconstant<<"\n";
			}else if (d/mulconstant == b*mulconstant && d/mulconstant > 0){
				cout<<d/mulconstant<<"\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		if(d == -1){
			int sumconstant = c-b;
			int mulconstant = c/b;
			if (sumconstant == b-a && c + sumconstant <= 1000000){
				cout<<c+sumconstant<<"\n";
			}else if (mulconstant == b/a && c*mulconstant <= 1000000){
				cout<<c*mulconstant<<"\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
	}
}