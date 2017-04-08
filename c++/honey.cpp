#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int N,S; cin >> N >> S;
		vector<string> M(N);

		for(int i = 0; i < N; ++i)
			cin >> M[i];

		pii start;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if(M[i][j] == 'D')
				{
					start = pii(i,j);
					goto exit;
				}
		exit:

		queue<pii> Q; Q.push(start);
		vector<vector<pii>> parent(N,vector<pii>(N,pii(-1,-1))); parent[start.first][start.second] = pii(-2,-2);

		pii bear;
		while(!Q.empty())
		{
			int i = Q.front().first, j = Q.front().second; Q.pop();
			if(M[i][j] == 'M')
			{
				bear = pii(i,j);
				break;
			}
			if(i > 0 && M[i-1][j] != 'T' && parent[i-1][j].first == -1)
			{
				parent[i-1][j] = pii(i,j);
				Q.emplace(i-1,j);
			}
			if(i < N-1 && M[i+1][j] != 'T' && parent[i+1][j].first == -1)
			{
				parent[i+1][j] = pii(i,j);
				Q.emplace(i+1,j);
			}
			if(j > 0 && M[i][j-1] != 'T' && parent[i][j-1].first == -1)
			{
				parent[i][j-1] = pii(i,j);
				Q.emplace(i,j-1);
			}
			if(j < N-1 && M[i][j+1] != 'T' && parent[i][j+1].first == -1)
			{
				parent[i][j+1] = pii(i,j);
				Q.emplace(i,j+1);
			}
		}


		vector<vector<int>> dist(N,vector<int>(N,-1));
		Q = queue<pii>();
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if(M[i][j] == 'H')
				{
					Q.emplace(i,j);
					dist[i][j] = 0;
				}

		while(!Q.empty())
		{
			int i = Q.front().first, j = Q.front().second; Q.pop();
			if(i > 0 && M[i-1][j] != 'T' && i > 0 && M[i-1][j] != 'D' && dist[i-1][j] == -1)
			{
				dist[i-1][j] = dist[i][j]+1;
				Q.emplace(i-1,j);
			}
			if(i < N-1 && M[i+1][j] != 'T' && i < N-1 && M[i+1][j] != 'D' && dist[i+1][j] == -1)
			{
				dist[+-1][j] = dist[i][j]+1;
				Q.emplace(i+1,j);
			}
			if(j > 0 && M[i][j-1] != 'T' &&  j > 0 && M[i][j-1] != 'D' && dist[i][j-1] == -1)
			{
				dist[i][j-1] = dist[i][j]+1;
				Q.emplace(i,j-1);
			}
			if(j < N-1 && M[i][j+1] != 'T' && j < N-1 && M[i][j+1] != 'D' && dist[i][j+1] == -1)
			{
				dist[i][j+1] = dist[i][j]+1;
				Q.emplace(i,j+1);
			}
		}

		int time = 0;
		int ans = INT_MAX;
		while(bear != start)
		{
			for(int i = 0; i < S && bear != start; ++i)
			{
				bear = parent[bear.first][bear.second];
				if(bear != start)
					ans = min(ans,dist[bear.first][bear.second]-time);
			}
			time++;
		}

		cout << max(ans,-1) << '\n';
	}
	return 0;
}