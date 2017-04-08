#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.141592653589793238462643383279502884L
using namespace std;
double binarysearch(double d, double h,double x, double n1, double n2){
	double target = n1/n2;
	double epsilon = 0.0002;
	double left = 0;
	double right = x;
	double xp = (left+right)/2;
	double firstsen = xp/sqrt(d*d+xp*xp);
	double secondsen = (x-xp)/sqrt(h*h+(x-xp)*(x-xp));
	double comp = firstsen/secondsen;

	while (abs(comp-target)>epsilon){
		if(comp>target){
			right = xp;
		}
		else{
			left = xp;
		}
		xp = (left+right)/2;
		firstsen = xp/sqrt((d*d+xp*xp));
		secondsen = (x-xp)/sqrt((h*h)+(x-xp)*(x-xp));
		comp = firstsen/secondsen;
	}
	return xp;
}

int main(){
	double d,h,x,n1,n2;
	while(cin>>d>>h>>x>>n1>>n2){
		if(d == 0 && h == 0 && x == 0 && n1 == 0 && n2 == 0)
			break;
		double xp = binarysearch(d,h,x,n1,n2);
		double firstsen = xp/sqrt(d*d+xp*xp);
		double angle = (pi/2)-(asin(firstsen));
		cout<<fixed<<setprecision(2)<<angle*180/pi<<"\n";
	}
	return 0;
}