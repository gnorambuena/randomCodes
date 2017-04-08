#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct status
{
	int key, i, j;

	status(int k, int I, int J)
	{
		key = k; i = I; j = J;
	}
};

int N = 0, B = 1, Y = 2, R = 4, G = 8;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Row,Col; cin >> Row >> Col;

	while(Row != 0 && Col != 0)
	{
		vector<string> M(Row);

		for(int i = 0; i < Row; ++i)
			cin >> M[i];

		pii start;
		for(int i = 0; i < Row; ++i)
			for(int j = 0; j < Col; ++j)
				if(M[i][j] == '*')
				{
					start = pii(i,j);
					goto exit;
				}
		exit:

		vector<vector<vector<int>>> dist(16,vector<vector<int>>(Row,vector<int>(Col,INT_MAX)));

		queue<status> Q; Q.emplace(N,start.first,start.second);
		dist[N][start.first][start.second] = 0;

		int distance = INT_MAX;
		while(!Q.empty())
		{
			status s = Q.front(); Q.pop();

			//cout << s.i << ' ' << s.j << '\n';

			if(M[s.i][s.j] == 'X')
			{
				distance = dist[s.key][s.i][s.j];

				break;
			}

			if(M[s.i][s.j] == 'B' && (s.key&B) == 0)
				continue;
			if(M[s.i][s.j] == 'Y' && (s.key&Y) == 0)
				continue;
			if(M[s.i][s.j] == 'R' && (s.key&R) == 0)
				continue;
			if(M[s.i][s.j] == 'G' && (s.key&G) == 0)
				continue;

			if(M[s.i][s.j] == 'b' && (s.key&B) == 0 && dist[s.key|B][s.i][s.j] == INT_MAX)
			{
				Q.emplace(s.key|B,s.i,s.j);
				dist[s.key|B][s.i][s.j] = dist[s.key][s.i][s.j];
			}
			if(M[s.i][s.j] == 'y' && (s.key&Y) == 0 && dist[s.key|Y][s.i][s.j] == INT_MAX)
			{
				Q.emplace(s.key|Y,s.i,s.j);
				dist[s.key|Y][s.i][s.j] = dist[s.key][s.i][s.j];
			}
			if(M[s.i][s.j] == 'r' && (s.key&R) == 0 && dist[s.key|R][s.i][s.j] == INT_MAX)
			{
				Q.emplace(s.key|R,s.i,s.j);
				dist[s.key|R][s.i][s.j] = dist[s.key][s.i][s.j];
			}
			if(M[s.i][s.j] == 'g' && (s.key&G) == 0 && dist[s.key|G][s.i][s.j] == INT_MAX)
			{
				Q.emplace(s.key|G,s.i,s.j);
				dist[s.key|G][s.i][s.j] = dist[s.key][s.i][s.j];
			}

			if(s.i > 0 && M[s.i-1][s.j] != '#' && dist[s.key][s.i-1][s.j] == INT_MAX)
			{
				dist[s.key][s.i-1][s.j] = dist[s.key][s.i][s.j]+1;
				Q.emplace(s.key,s.i-1,s.j);
			}
			if(s.i < Row-1 && M[s.i+1][s.j] != '#' && dist[s.key][s.i+1][s.j] == INT_MAX)
			{
				dist[s.key][s.i+1][s.j] = dist[s.key][s.i][s.j]+1;
				Q.emplace(s.key,s.i+1,s.j);
			}
			if(s.j > 0 && M[s.i][s.j-1] != '#' && dist[s.key][s.i][s.j-1] == INT_MAX)
			{
				dist[s.key][s.i][s.j-1] = dist[s.key][s.i][s.j]+1;
				Q.emplace(s.key,s.i,s.j-1);
			}
			if(s.j < Col-1 && M[s.i][s.j+1] != '#' && dist[s.key][s.i][s.j+1] == INT_MAX)
			{
				dist[s.key][s.i][s.j+1] = dist[s.key][s.i][s.j]+1;
				Q.emplace(s.key,s.i,s.j+1);
			}
		}

		if(distance != INT_MAX)
			cout << "Escape possible in " << distance << " steps.\n";
		else
			cout << "The poor student is trapped!\n";

		cin >> Row >> Col;
	}

	return 0;
}