#include <iostream>
using namespace std;

struct point{
	long long x,y;	
};

long long crossproduct(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int main(){
	long long x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	point a = {x1,y1};
	point b = {x2,y2};
	while(n--){
		long long x,y;
		cin>>x>>y;
		point c = {x,y};
		long long  ans = crossproduct(a,b,c);
		if(ans == 0)
			cout<<"C\n";
		else if(ans < 0)
			cout<<"D\n";
		else
			cout<<"I\n";
	}
	return 0;
}