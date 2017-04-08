#include <iostream>
#include <iomanip>
using namespace std;
double mysqrt(double a){
	double r = a;
	double l = 1;
	int count = 0;
	while(r-l>=1e-12 && count < 1000){
		double m = (r+l)/2.0;
		cerr<<m<<endl;
		if(m*m < a){
			l = m;
		}
		else
			r = m;
		count++;
	}
	return (r+l)/2.0;
}
int main(){
	double number;
	cerr<<fixed<<setprecision(13);
	cout<<fixed<<setprecision(13);
	while(cin>>number){
		cout<<mysqrt(number)<<"\n";
	}
	return 0;
}