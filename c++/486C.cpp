#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int dist(char a, char b) 
{
	if(a > b)
		swap(a,b);
	return min(b-a,a-'a'+'z'-b+1);
	//abcdefghijklmnopqrstuvwxyz
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,p; cin >> n >> p; p--;
	string s; cin >> s;
	
	int p1 = 0, p2 = n/2-1, p3 = n/2+n%2, p4 = n-1;
	while(p1 < p4 && s[p1] == s[p4])
	{
		p1++;
		p4--;
	}
	
	if(p1 >= p4)
	{
		cout << 0;
		return 0;
	}
	while(s[p2] == s[p3])
	{
		p2--;
		p3++;
	}
	
	int ans = abs(p-p1);
	ans = min(ans,abs(p-p2));
	ans = min(ans,abs(p-p3));
	ans = min(ans,abs(p-p4));
	if(p <= p3 || p >= p4) ans = min(ans,2*p1);
	for(int i = p1, j = p4; i <= p2 && j >= p3; ++i,--j)
		ans += dist(s[i],s[j])+1;
	cout << ans;
	return 0;
}