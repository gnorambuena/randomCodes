#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<string>vs;
	int n;
	cin>>n;
	int d=0,r=0;
	for(int i = 0 ; i < n ; i++){
		string t;
		cin>>t;
		string aux="";
		for(int i = 0 ; i < t.size() ; i++){
			if(t[i]=='D' || t[i]=='R'){
				aux.push_back(t[i]);
			}
		}
		if(aux!="")vs.push_back(aux);
		if(aux[aux.size()-1]=='D')d++;
		else r++;
	}
	if(d==0 || r==0){
		cout<<"0\n";
		return 0;
	}
	//cout<<("RD"<"RDD");
	vector<bool>dirty(vs.size(),false);
	sort(vs.begin(),vs.end());
	int index = 0;
	//copy(vs.begin(),vs.end(),ostream_iterator<string>(cout," "));
	//cout<<endl;
	while(d){
		//cerr<<index<<"\n";
		if(vs[index][vs[index].length()-1]=='D'){
			dirty[vs]=true;
			auto it = lower_bound(vs.begin()+index,vs.end(),"R");
			//cout<<*it<<endl;
			string aux = vs[index]+(*it);
			*it = aux;
			//cout<<*it<<endl;
			d--;
			//sort(vs.begin()+index,vs.end());
		}
		index++;
		//cout<<"asdasd\n";
		//copy(vs.begin(),vs.end(),ostream_iterator<string>(cout," "));
		//cout<<endl;
	}
	//copy(vs.begin()+index-1,vs.end(),ostream_iterator<string>(cout," "));
	//cout<<endl;
	char c =' ';
	string s;
	for(int i = index-1 ; i < vs.size() ; i++){
		if(!dirty[i])s.append(vs[i]);
	}
	//cout<<s<<endl;
	int count = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(c==' ' && s[i]=='D'){
			c=s[i];
		}
		else if(c =='D' && s[i]=='R'){
			count++;
			c=' ';
		}
		/*else if(c=='R' && s[i]=='D'){
			count++;
			c=' ';
		}*/
	}
	cout<<count<<"\n";
	return 0;
}