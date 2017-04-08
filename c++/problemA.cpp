#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
vector<string>cero = {"xxxxx","x...x","x...x","x...x","x...x","x...x","xxxxx"};
vector<string>uno = {"....x","....x","....x","....x","....x","....x","....x"};
vector<string>dos = {"xxxxx","....x","....x","xxxxx","x....","x....","xxxxx"};
vector<string>tres = {"xxxxx","....x","....x","xxxxx","....x","....x","xxxxx"};
vector<string>cuatro = {"x...x","x...x","x...x","xxxxx","....x","....x","....x"};
vector<string>cinco = {"xxxxx","x....","x....","xxxxx","....x","....x","xxxxx"};
vector<string>seis = {"xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx"};
vector<string>siete = {"xxxxx","....x","....x","....x","....x","....x","....x"};
vector<string>ocho = {"xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx"};
vector<string>nueve = {"xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx"};
vector<string>mas = {".....","..x..","..x..","xxxxx","..x..","..x..","....."};
map<vector<string>,int> mymap;
map<int,vector<string> > mymap2;
int main(){
	mymap[cero]=0;
	mymap[uno]=1;
	mymap[dos]=2;
	mymap[tres]=3;
	mymap[cuatro]=4;
	mymap[cinco]=5;
	mymap[seis]=6;
	mymap[siete]=7;
	mymap[ocho]=8;
	mymap[nueve]=9;
	mymap[mas]=-1;
	vector<vector<string> > mynum = {cero,uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve};
	vector<string>input;
	string s;
	for(int i = 0 ; i < 7 ; i++){
		getline(cin,s);
		input.push_back(s);
		input[input.size()-1].push_back('.');
	}
	//copy(input.begin(),input.end(),ostream_iterator<string>(cout,"\n"));
	int ans1 = 0;
	int ans2 = 0;
	bool flag = true;
	for(int i = 0 ; i < input[0].size() ; i+=6){
		vector<string>num(7,"");
		for(int k = 0 ; k < 7 ; k++){
			for(int j = i ; j < 5+i ; j++){
				num[k].push_back(input[k][j]);
			}
		}
		//copy(num.begin(),num.end(),ostream_iterator<string>(cout,"\n"));
		if(flag){
			if(mymap[num]!=-1){
				//cerr<<mymap[num]<<endl;
				ans1=ans1*10;
				ans1+=mymap[num];
			}
			else{
				//cerr<<"mas"<<endl;
				flag=false;
			}
		}
		else{
			ans2=ans2*10;
			ans2+=mymap[num];
			//cerr<<mymap[num]<<endl;
		}
	}
	int ans = ans1+ans2;
	vector<vector<string> > sol;
	while(ans>0){
		int aux = ans%10;
		ans/=10;
		sol.push_back(mynum[aux]);
	}
	reverse(sol.begin(),sol.end());
	for(int j = 0 ; j < 7 ; j++){
		//cout<<sol.size()<<"\n";	
		for(int i = 0 ; i < sol[0].size() ; i++){
			cout<<sol[i][j];
			if(i+1!=sol[0].size())cout<<".";
		}
		cout<<"\n";
	}
	return 0;
}