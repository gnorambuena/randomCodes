#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int> > mem;
vector<int> C;

int DP(int i, int j)
{
    if(i > j)
        return 0;
    if(mem[i][j] != -1)
        return mem[i][j];
    
    mem[i][j] = 1+min(DP(i,j-1),DP(i+1,j));

    if(C[i] == C[j])
    	mem[i][j] = min(mem[i][j],DP(i+1,j-1));

    if(C[i] == C[i+1])
    	mem[i][j] = min(mem[i][j],1+DP(i+2,j));

    if(C[j] == C[j-1])
    	mem[i][j] = min(mem[i][j],1+DP(i,j-2));

    for(int k = i+2; k < j-1; ++k)
    {
    	if(C[i] == C[k])
    		mem[i][j] = min(mem[i][j],DP(i+1,k-1)+DP(k+1,j));
    	if(C[j] == C[k])
    		mem[i][j] = min(mem[i][j],DP(i,k-1)+DP(k+1,j-1));
    }
    
    return mem[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	C.resize(n); 
	for(int i = 0; i < n; ++i)
		cin >> C[i];

	mem.assign(n,vector<int>(n,-1));

	for(int i = 0; i < n; ++i)
		mem[i][i] = 1;

	for(int i = 1; i < n; ++i)
		mem[i-1][i] = 1 + (C[i-1] != C[i]);

	cout << DP(0,n-1);
	return 0;
}