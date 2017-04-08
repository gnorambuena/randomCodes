#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%7==0)
	cout<<(2*n/7)<<" "<<2*n/7<<endl;
    else{
	cout<<2*floor((float)n/7);
	if(n%7==2 || n%7==3)cout<<" "<<ceil((float)2*n/7)+1<<endl;
	else cout<<" "<<ceil((float)2*n/7)<<endl;
	}  
  return 0;
}
