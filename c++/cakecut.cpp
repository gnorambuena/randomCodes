#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef pair<long long,long long> pii;
long long area(pii a,pii b,pii c){
	return abs(a.first*b.second+b.first*c.second+c.first*a.second-
			b.first*a.second-c.first*b.second-a.first*c.second);
}
long long abs(long long a){
	return (a>0?a:-a);
}
long long max(long long a ,long long b){
	return(a>b?a:b);
}
long long min(long long a,long long b){
	return (a>b?b:a);
}
int main(){
	//cout<<area({0,0},{0,2},{2,2})<<"\n";
	int n;
	cin.tie(0);ios::sync_with_stdio(0); 
	while(cin>>n){
		pii p1,p2,p3;
		vector<pii>points;
		cin>>p1.first>>p1.second;
		cin>>p2.first>>p2.second;
		long long totalarea = 0;
		points.push_back(p1);points.push_back(p2);
		for(int i = 2 ; i < n ; i++){
			cin>>p3.first>>p3.second;
			//cout<<area(p1,p2,p3)<<endl;
			totalarea+=area(p1,p2,p3);
			p2 = p3;
			points.push_back(p3);
		}
		//cout<<totalarea<<endl;
		int f1=1,f2=2;
		long long Amax = LLONG_MAX;
		long long ant = 0 , act = 0;
		long long aux = LLONG_MAX;
		for(int i = 0 ; i < n; i++){
			long long r;
			//cout << "i: " << i << " f1: " << f1 << " f2: " << f2 << endl;
			while(2*act < totalarea){
				ant = act;
				r =area(points[f1],points[i],points[f2]);
				act += r;
				f1 = (f1 + 1) % n;
				f2 = (f2 + 1) % n;	
			}
			if(2*act==totalarea){
				Amax = min(Amax,totalarea/2);
			}
			else{
				aux = max(totalarea-act,ant);
				Amax = min(Amax,aux);
			}
			act-=r;
			f1 = (f1 - 1 + n)%n;
			f2 = (f2 - 1 + n)%n;
			act -= area(points[i], points[(i + 1) % n], points[f1]);
		}
		cout<<totalarea-Amax<<" "<<Amax<<"\n";
	}
	return 0;
}