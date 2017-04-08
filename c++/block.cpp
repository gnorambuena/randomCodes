#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
	priority_queue<int,vector<int>,greater<int> >pq;
	priority_queue<pii,vector<pii>,greater<pii> > P;
	for(int i=1; i < 30001 ; i++){
		pq.push(i);
	}
	vector<int>time(30001,-1);
	char mander;int t;

	while(cin>>t>>mander){
		if(mander == '.'){
			int a;
			cin>>a;
			if(time[a]!=-1 && t-time[a]<600){
				cout << '+' << endl;
				time[a]=t;
			}
			else{
				cout << '-' << endl;
				if(time[a]!=-1){
					pq.push(a);
						while(!P.empty() && t-P.top().first > 600){
				pii asd = P.top();P.pop();
				//cout<<asd.first<<" "<<asd.second<<endl;
				if(asd.first!=time[asd.second] && time[asd.second]!=-1){
					asd.first=time[asd.second];
					P.push(asd);
				}
				else{
					time[asd.second]=-1;
					pq.push(asd.second);
				}
			}
					time[a]=-1;
				}
			}
		}
		else{
			while(!P.empty() && t-P.top().first > 600){
				pii asd = P.top();P.pop();
				//cout<<asd.first<<" "<<asd.second<<endl;
				if(asd.first!=time[asd.second] && time[asd.second]!=-1){
					asd.first=time[asd.second];
					P.push(asd);
				}
				else{
					time[asd.second]=-1;
					pq.push(asd.second);
				}
			}
			int k = pq.top();pq.pop();
			time[k]=t;
			P.push(make_pair(t,k));
			cout<<k<<endl;
		}
	}
	return 0;
}