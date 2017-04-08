#include <iostream>
#include <bitset>
using namespace std;
int main(){
	int x;
	cin>>x;
	bitset<32>bitmask(x);
	cout<<bitmask.count()<<endl;
	return 0;
	}
