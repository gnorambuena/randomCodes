#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
#define PRINT(X) copy(X.begin(),X.end(),ostream_iterator<point>(cout," ,"));
using namespace std;
struct point{
	long long x,y;
	point(long long a=0,long long b=0){
		x=a;y=b;
	}
	struct point& operator=(const point& a){
		x=a.x;
		y=a.y;
		return *this;
	}
};
point operator-(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
point operator+(point a,point b){
	return point(a.x+b.x,a.y+b.y);
}
bool operator<(point a, point b){
	if(a.y<b.y)return true;
	else if(a.y==b.y && a.x<b.x)return true;
	else return false;
}
bool comp(point a, point b){
	return a<b;
}
long long crossprod(point a, point b){
	return a.x*b.y-b.x*a.y;
}
int mod(point a){
	return a.x*a.x+a.y*a.y;
}
bool anglecomp(point a, point b){
	long long C = crossprod(a,b);
	if(C == 0)
		return mod(a) < mod(b);
	return C>0;
}
ostream& operator<<(ostream& os,point a){
	return os<<a.x<<" "<<a.y;
}
point nexttotop(stack<point>&s){
	point p=s.top();s.pop();
	point p1=s.top();
	s.push(p);
	return p1;
}
stack<point> convexhull(vector<point>&Q){
	sort(Q.begin()+1,Q.end(),anglecomp);
	//PRINT(Q);
	stack<point> s;
	s.push(Q[0]);
	s.push(Q[1]);
	s.push(Q[2]);
	for(int i = 3; i < Q.size();i++){
		long long cross =-1* crossprod(s.top()-nexttotop(s),Q[i]-nexttotop(s));
		if(cross==0){

			point a = s.top();s.pop();
			point b = s.top();s.pop();
			int m1=mod(a);
			int m2=mod(b);
			point c=a;
			if(m1<m2)c=b;
			//cerr<<"asd "<<c<<endl;
			s.push(c);
			continue;
		}
		//cout<<cross<<" "<<nexttotop(s)<<" "<<s.top()<<" "<<Q[i]<<endl;
		while(cross>0){
			s.pop();
			cross = crossprod(nexttotop(s)-s.top(),Q[i]-s.top());;
		}
		s.push(Q[i]);
	}
	return s;
}
int main(){
	point a(2,2),b(3,3),c(5,5),d(1,4);
	vector<point>points;

	points.push_back(a);points.push_back(b);points.push_back(c);points.push_back(d);
	sort(points.begin(),points.end(),comp);
	point pivot=points[0];
	for(int i = 1; i < points.size();i++ ){
		points[i]=points[i]-pivot;
	}
	stack<point> s = convexhull(points);
	stack<point> s2 = s;
	while(!s2.empty()){
		cout<<s2.top()+pivot<<endl;
		s2.pop();
	}
	//PRINT(points);
	//cout<<a<<endl;
	return 0;
}