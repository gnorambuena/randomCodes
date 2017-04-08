#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(){
	int C,P;
	int contestnumber = 0;
	while(cin>>C>>P && C!=0 && P!=0){
		contestnumber++;
		vector<int>horizontal(C,0);
		vector<int>vertical(P,0);
		for(int i = 0 ; i < C ; i++){
			string team;
			cin>>team;
			int hor = 0;
			for( int j = 0 ; j < P ; j++){
				int aux;
				cin>>aux;
				vertical[j]+=aux;
				hor+=aux;
			}
			horizontal[i]=hor;
		}
		//copy(horizontal.begin(),horizontal.end(),ostream_iterator<int>(cout," "));
		//cout<<endl;
		//copy(vertical.begin(),vertical.end(),ostream_iterator<int>(cout," "));
		//cout<<endl;
		int ans = 0;
		bool flag = true;
		for(int i = 0 ; i < P ; i++){
			if(vertical[i]==0){
				flag = false;
				//cerr<<"first\n"<<i;
				break;
			}
		}
		ans+=flag;
		int count = 0;

		for(int i = 0 ; i < C ; i++){
			if(horizontal[i]>=2)count++;
		}
		//cerr<<count<<"\n";
		if(10*count > 9*C){
			ans+=2;
			//cerr<<"second\n";
		}
		flag = true;
		for(int i = 0 ; i < C ; i++){
			if(horizontal[i]==P){
				flag = false;
				break;
			}
		}
		if(flag){
			//cerr<<"third\n";
			ans+=2;
		}
		cout<<"Contest "<<contestnumber<<": "<<ans<<"\n";
	}
	return 0;
}