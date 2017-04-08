#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
struct point{
	double x,y;
};

double distance(point A, point B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double crossproduct(point A, point B, point C) {
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

double pointsegmentdistance(point A, point B, point C){
	double first = crossproduct(A,B,C);
	double second = distance(A,B);
	return fabs(first/second);
}

bool pointinsegment(point A,point B,point C){
	point D = {C.x-A.x,C.y-A.y};
	point E = {B.x-A.x,B.y-A.y};
	point F = {C.x-B.x,C.y-B.y};
	point G = {A.x-B.x,A.y-B.y};
	double first = D.x*E.x+D.y*E.y;
	double second = F.x*G.x+F.y*G.y;
	double epsilon = -0.00000762939;//-2^-17;
	return first >= epsilon && second >= epsilon;
}

int main(){
	string c;
	while(cin>>c){
		if(c=="*")break;
		int n = stoi(c);
		vector<point>points;
		double x,y;
		//cout<<"asdas\n";
		cin>>x>>y;
		point redis = {x,y};
		for(int i = 0 ; i < n ; i++){
			cin>>x>>y;
			point p = {x,y};
			points.push_back(p);
		}
		double ans = 1e9;;
		for (int i = 0; i < n; i++){
			ans= min(ans, distance(redis, points[i]));
		}

		if(pointinsegment(points[n-1],points[0],redis)){
			ans = min(ans,pointsegmentdistance(points[n-1],points[0],redis));
	    }
		for (int i = 0; i+1 < n; i++) {
			if(pointinsegment(points[i],points[i+1],redis)){
				ans = min(ans,pointsegmentdistance(points[i],points[i+1],redis));
	   		}
		}
		cout<<fixed<<setprecision(3)<<ans<<"\n";
	}
	return 0;
}
