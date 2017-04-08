#include <iostream>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int daysofmonth[] ={31,28,31,30,31,30,31,31,30,31,30,31};
map<int,bool>leapyear;

bool cons(int d,int m, int y, int ld, int lm, int ly){
	if(y!=ly){
		if(lm==12 && m == 1 && ld==31 && d==1)return true; 
		return false;
	}
	if(lm==m && lm!=2 && m!=2){
		if(ld+1==d)return true;
		else return false;
	}
	if(leapyear[y] && lm==2){
		if(d==29 && ld==28 && m==2)return true;
		if(ld==29 && m==3 && d==1)return true;
		return false;
	}
	else{
		if(daysofmonth[lm]==ld){
			if(m==lm+1 && d==1)return true;
			return false;
		}
		return false;
	}
}
int main(){
	map<int,bool>leapyear;
	for(int i = 1900 ; i <= 2100 ; i++){
		if(((i%4==0)&& !(i%100==0))||i%400==0){
			leapyear[i]=true;
		}
	}
	int n;
	while(cin>>n && n!=0){
		int ld,lm,ly,lc;
		cin>>ld>>lm>>ly>>lc;
		int ans = 0;
		int consecutive = 1;
		int maxcons = -1;
		for(int i = 1 ; i < n ; i++){
			int d,m,y,c;
			cin>>d>>m>>y>>c;
			if( cons(d,m,y,ld,lm,ly)){
				consecutive++;
				ans+=(c-lc);
			}
			else{
				maxcons=max(maxcons,consecutive);
				consecutive=0;
			}
			ld = d;
			lc = c;
			lm = m;
			ly = y;
		}
		cout<<ans<<" "<<consecutive<<"\n";
	}

	return 0;
}