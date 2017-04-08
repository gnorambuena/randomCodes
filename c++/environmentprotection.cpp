#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int>p1,p2,q1,q2;
double pow(double x,int exp){
	if(exp == 0)return 1;
	double aux = pow(x,exp/2);
	if(exp%2==0)return aux*aux;
	else return aux*aux*x;
}
double min(double a,double b){
	return (a<b?a:b);
}
double y1(double x){
	double ans1 = 0;
	for(int i = 0 ; i < p1.size() ; i++){
		ans1+=p1[i]*pow(x,i);
	}
	double ans2 = 0;
	for(int i = 0 ; i < q1.size() ; i++){
		ans2+=q1[i]*pow(x,i);
	}
	return -1.0*ans1/ans2;
}
double y2(double x){
	double ans1 = 0;
	for(int i = 0 ; i < p2.size() ; i++){
		ans1+=p2[i]*pow(x,i);
	}
	double ans2 = 0;
	for(int i = 0 ; i < q2.size() ; i++){
		ans2+=q2[i]*pow(x,i);
	}
	return -1.0*ans1/ans2;
}
double area(double d,double w){
	double ans = 0;
	double step = 1/65536.0;
	double par1 = 0;
	for(double k = step ; k < w ; k+=step){
		double aux = y1(k);
		par1+=min(d,aux);
	}
	double par2 = 0;
	for(double k = step ; k < w ; k+=step){
		double aux = y2(k*step);
		par2+=min(d,aux);
	}
	par1 += (min(d,y1(0.0))+min(d,y1(w))) /2.0;
	par1 *= (w/65536);
	par2 += (min(d,y2(0.0))+min(d,y2(w))) /2.0;
	par2 *= (w/65536);
	return par2-par1;
}
double binarySearch(double w,double A,double D){
	double l = 0;
	double r = D;
	double epsilon = 1.0/65536.0;
	double ans;
	int count = 0;
	while(count<32){
		count++;
		ans = area((r+l)/2.0,w);
		if (ans > A)
			r = (r+l)/2.0 + epsilon;
		else
			l = (r+l)/2.0 - epsilon;
	}
	return (r+l)/2.0;
}
int main(){
	int W,D,A,K;
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>W>>D>>A>>K;
	cout<<fixed<<setprecision(5);
	p1.resize(K+1);p2.resize(K+1);
	q1.resize(K+1);q2.resize(K+1);
	for(int &a:p1)cin>>a;
	for(int &a:q1)cin>>a;
	for(int &a:p2)cin>>a;
	for(int &a:q2)cin>>a;
	cout<<binarySearch(W,A,D)<<"\n";
	return 0;
}