#include <iostream>
using namespace std;
int main(){
	int k,n,w;
	cin>>k>>n>>w;
	int x=k*((w*(w+1))/2);
	n>=x?cout<<"0"<<endl : cout<<x-n<<endl;
	return 0;
}
