#include <iostream>
#include <vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(int k = 1 ; k <= T ; k++){
		int N;
		cin>>N;
		vector<int>walls(N,0);
		for(int &a : walls){
			cin>>a;
		}
		int high_jumps = 0, low_jumps = 0;
		int base = walls[0];
		for(int i = 1 ; i < walls.size() ; i++){
			if(walls[i]>base)high_jumps++;
			else if(walls[i]<base)low_jumps++;
			base = walls[i];
		}
		cout<<"Case "<<k<<": "<< high_jumps << " "<< low_jumps <<"\n";
	}
	return 0;
}