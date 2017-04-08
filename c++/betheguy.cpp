#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,p;
	cin>>n>>p;
	vector<int>levels(n+1,0);
	for(int i=0;i<p;i++){
		int k;
		cin>>k;
		levels[k]=1;
	}
	cin>>p;
	for(int i=0;i<p;i++){
                int k;
                cin>>k;
                levels[k]=1;
        }
	for(int i=1;i<n+1;i++){
		if(levels[i]!=1){
			cout<< "Oh, my keyboard!"<<endl;
			return 0;
		}
	}
	cout<<"I become the guy."<<endl;
	return 0;
	}
