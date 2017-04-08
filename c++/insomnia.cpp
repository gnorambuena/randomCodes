#include <iostream>
#include <vector>
using namespace std;
int main(){
	int k,l,m,n,d;
	cin>>k>>l>>m>>n>>d;
	vector<int>dragons(d+1,0);
	for(int i=1;i<d+1;i++){
		if(k*i<=d){
			dragons[k*i]++;
		}
                if(l*i<=d){ 
                        dragons[l*i]++;
                }
                if(m*i<=d){ 
                        dragons[m*i]++;
                }
                if(n*i<=d){ 
                        dragons[n*i]++;
                }
	}
	int count=0;
	for(int i=1;i<d+1;i++){
		if(dragons[i]!=0)count++;
	}
	cout<<count<<endl;
	return 0;
}
