#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<vector<double>> DPder, DPizq;
vector<pii> P;
int n;

double dist(int i, int j)
{
	int x = P[i].first-P[j].first, y = P[i].second - P[j].second;
	return sqrt(x*x+y*y);
}

double der(int,int);

double izq(int I, int D)
{
	if(DPizq[I][D] > -0.5) return DPizq[I][D];
	return DPizq[I][D] = min(dist(I,(I-1+n)%n) + izq((I-1+n)%n,D),
		dist(I,(D+1)%n) + der(I,(D+1)%n));
}

double der(int I, int D)
{
	if(DPder[D][I] > -0.5) return DPder[D][I];
	return DPder[D][I] = min(dist(D,(D+1)%n) + der(I,(D+1)%n),
		dist(D,(I-1+n)%n) + izq((I-1+n)%n,D));
}

int main()
{	
	int e,s;
	scanf("%d%d%d",&n,&e,&s);
	--e; --s;
	P.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d",&P[i].first,&P[i].second);
	
	DPder.assign(n,vector<double>(n,-1.0));
	DPizq.assign(n,vector<double>(n,-1.0));
	for(int i = 0; i < n; ++i)
		DPizq[s][i] = DPder[s][i] = 1e10;
	DPizq[s][(s-1+n)%n] = DPder[s][(s+1)%n] = 0.0;

	printf("%lf\n",min(izq(e,e),der(e,e)));
	return 0;
}