#include <iostream>
using namespace std;
int main(){
	int w;
	cin>>w;
	cout<<( w&1 || w==2 ? "NO":"YES")<<"\n";
	return 0;
}