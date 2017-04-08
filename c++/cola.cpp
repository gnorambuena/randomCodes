#include <iostream>
#include <string>
using namespace std;
int main(){
	string q[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	int n;
	cin>>n;
	for(;n>5;n=(n/2)-2);
	cout<<q[n-1]<<"\n";
	return 0;
}
