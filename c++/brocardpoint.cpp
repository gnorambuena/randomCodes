#include <iostream>
#include <cmath>
using namespace std;
struct point{
	double x,y;
};

double crossproduct(point a, point b, point c){
	return abs((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}

double brocardAngle(point a,point b , point c){
	double A = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.x-b.x);
	double B = (b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
	double C = (a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y);
	A = abs(A);
	B = abs(B);
	C = abs(C);
	double area = crossproduct(a,b,c);
	return (A+B+C)/(2*area);
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		double x,y;
		cin>>x>>y;
		point a = {x,y};
		cin>>x>>y;
		point b = {x,y};
		cin>>x>>y;
		point c = {x,y};
		cout<< brocardAngle(a,b,c)<<"\n";
	}
	return 0;
}