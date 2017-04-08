#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a,b;
		char t,s;
		cin>>b>>s;
		bool flag = true;
		for(int i = 1 ; i < n ; i++){
			cin>>a>>t;
			if(a==b || t==s)
				flag = false;
			b=a;
			s=t;
		}
		cout<<(flag?"B":"M")<<"\n";
	}
	return 0;
}