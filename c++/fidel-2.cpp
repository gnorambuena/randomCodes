#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	vector<string>vs;
	int n;
	cin>>n;
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
	}
	int count = 0;
	for(int j = 0 ; j < vs.size() ; j++){
		string &s=vs[j];
		for(int i = 0 ; i < s.size()-1 ; i++){
			if(s[i]=='D' && s[i+1]=='R'){
				count++;
				s[i]=' ';
				s[i+1]=' ';
			}
		}
	}
	//cout<<count<<endl;
	//copy(vs.begin(),vs.end(),ostream_iterator<string>(cout," "));cout<<endl;
	int d=0,r=0,rd=0,rr=0,dd=0;
	for(int j = 0 ; j < vs.size() ; j++){
		string s=vs[j];
		string aux="";
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i]!=' '){
				aux.push_back(s[i]);
			}
		}
		//cout<<aux<<endl;
		if(aux.size()>=3){
			string s2;
			s2.push_back(aux[0]);
			s2.push_back(aux[aux.size()-1]);
			aux=s2;
		}
		if(aux=="R")r++;
		else if(aux=="D")d++;
		else if(aux=="RD")rd++;
		else if(aux=="RR")rr++;
		else if(aux=="DD")dd++;
	}
	//cout<<d<<" "<<r<<" "<<rd<<" "<<" "<<rr<<" "<<dd<<endl;
	count+=min(r,d);
	r-=min(r,d);
	d-=min(r,d);
	if(rd>0 && rr>0 & dd>0){
		count+=2*min(rd,min(rr,dd));
		rd-=min(rd,min(rr,dd));
		rr-=min(rd,min(rr,dd));
		dd-=min(rd,min(rr,dd));
	}
	if(d>0 && rr > 0){
		count+=min(d,rr);
		d-=min(d,rr);
		rr-=min(d,rr);
	}
	if(r>0 && dd > 0){
		count+=min(dd,r);
		dd-=min(dd,r);
		r-=min(dd,r);
	}
	if(d>0 && rd > 0){
		count+=min(d,rd);
		d-=min(d,rd);
		rd-=min(d,rd);
	}
	if(r>0 && rd > 0){
		count+=min(r,rd);
		r-=min(r,rd);
		rd-=min(r,rd);
	}
	count+=min(r,d);
	cout<<count<<"\n";
	return 0;
}