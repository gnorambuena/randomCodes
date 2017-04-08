#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll dist[n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> dist[i][j];
	
	ll sum = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			sum += dist[i][j];
	
	int k; cin >> k;
	while(k--)
	{
		int a,b; ll c;
		cin >> a >> b >> c;
		if(c < dist[--a][--b])
		{
			sum -= dist[a][b] - c;
			dist[a][b] = dist[b][a] = c;
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
				{
					ll magic = dist[i][a] + c + dist[b][j];
					if(magic < dist[i][j])
					{
						sum -= dist[i][j] - magic;
						dist[i][j] = dist[j][i] = magic;
					}
				}
		cout << sum << ' ';
	}
	return 0;
}