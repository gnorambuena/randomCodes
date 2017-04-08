#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point{
	double x;
	double y;
};

double crossproduct(Point A, Point B){
	return A.x*B.y-A.y*B.x;
}

int main(){
	Point stepx = {2,0};
	Point stepy = {1,sqrt(3)};
	Point stepz = {-1,sqrt(3)};
	int t;
	cin>>t;
	while(t--){
		int c;
		cin>>c;
		vector<Point>polygon;
		Point cur = {0,0};
		for(int i = 0 ; i < c ; i++){
			char d;
			int s;
			cin>>d>>s;
			if(d=='x'){
				cur.x+=(s*stepx.x);
				cur.y+=(s*stepx.y);
				polygon.push_back(cur);
			} else if(d=='y'){
				cur.x+=(s*stepy.x);
				cur.y+=(s*stepy.y);
				polygon.push_back(cur);
			} else {
				cur.x+=(s*stepz.x);
				cur.y+=(s*stepz.y);
				polygon.push_back(cur);
			}
			//cout<<cur.x<<" "<<cur.y<<"\n";
		}
		double ans = crossproduct(polygon[c-1],polygon[0]);
		for(int i = 0 ; i+1 < c ; i++){
			ans+=crossproduct(polygon[i],polygon[i+1]);
		}
		ans/=2;
		ans/=sqrt(3);
		cout<<round(fabs(ans))<<"\n";
	}
}