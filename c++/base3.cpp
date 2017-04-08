#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string>num;
vector<int>cur;
void gen_num(){
	num.resize(1001);
	cur.assign(7,0);
	cur[0]=1;
	num[0]="+";
	for(int i = 1 ; i < num.size() ; i++){
		int carry=1;
		for(int j = 0 ; j < 7 ; j++){
			if(cur[j]==1)
			{
				cur[j]=-1;
			}
			else{
				cur[j]+=1;
				carry=0;
				break;
			}
		}
		string s;
		bool flag = false;
		for(int j = cur.size()-1 ; j >=0 ; j--){
			if(cur[j]==1){
				s.push_back('+');
				flag=true;
			}
				
			else if(cur[j]==0){
				if(flag)
					s.push_back('0');
			}
			else{
				s.push_back('-');
				flag=true;
			}
		}
		//cerr<<s<<endl;
		num[i]=s;
	}
}
int main(){
	vector<int>pot3 = {1,3,9,27,81,243,729,2187};
	int t;
	cin>>t;
	gen_num();
	while(t--){
		int n;
		cin>>n;
		cout<<num[n-1]<<endl;
	}
	return 0;
}