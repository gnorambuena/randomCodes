#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	map<char,int> V = {{'C',0},{'D',1},{'H',2},{'S',3}};
	while(true)
	{
		int P,M,N; cin >> P >> M >> N;
		if(P == 0 && M == 0 && N == 0)
			break;

		vector<vector<pii>> hand(P,vector<pii>(M));
		queue<pii> deck; 
		for(int i = 0; i < N; ++i)
		{
			int R; char S; cin >> R >> S;
			deck.emplace(--R,V[S]);
		}
		for(int i = 0; i < P; ++i)
			for(int j = 0; j < M; ++j)
			{
				hand[i][j] = deck.front();
				deck.pop();
			}

		pii top = deck.front(); deck.pop();
		
		int clock = 1;
		int player = 0;
		if(top.first == 0)
		{
			hand[0].pb(deck.front());
			deck.pop();
			player++;
		}
		else if(top.first == 6)
		{
			hand[0].pb(deck.front());
			deck.pop();
			hand[0].pb(deck.front());
			deck.pop();
			player++;
		}
		else if(top.first == 10)
			player++;
		else if(top.first == 11)
			clock = -1;
		
		while(true)
		{
			pii card = {-1,-1};
			int cardindex = -1;
			for(int i = 0; i < hand[player].size(); ++i) 
				if(hand[player][i].first == top.first || hand[player][i].second == top.second)
					if(4*card.first+card.second < 4*hand[player][i].first+hand[player][i].second)
					{
						card = hand[player][i];
						cardindex = i;
					}

			if(cardindex == -1)
			{
				card = deck.front();
				deck.pop();
				if(card.first == top.first || card.second == top.second)
				{
					player = (player+clock+P)%P;
					top = card;
					if(top.first == 0)
					{
						hand[player].pb(deck.front());
						deck.pop();
						player = (player+clock+P)%P;
					}
					else if(top.first == 6)
					{
						hand[player].pb(deck.front());
						deck.pop();
						hand[player].pb(deck.front());
						deck.pop();
						player = (player+clock+P)%P;
					}
					else if(top.first == 10)
						player = (player+clock+P)%P;
					else if(top.first == 11)
						clock *= -1;
				}
				else
					hand[player].pb(card);
				continue;
			}

			top = card;
			hand[player].erase(hand[player].begin()+cardindex);
			if(hand[player].empty())
			{
				cout << player+1 << '\n';
				break;
			}

			top = card;
			if(top.first == 0)
			{
				player = (player+clock+P)%P;
				hand[player].pb(deck.front());
				deck.pop();
			}
			else if(top.first == 6)
			{
				player = (player+clock+P)%P;
				hand[player].pb(deck.front());
				deck.pop();
				hand[player].pb(deck.front());
				deck.pop();
			}
			else if(top.first == 10)
				player = (player+clock+P)%P;
			else if(top.first == 11)
				clock *= -1;
			player = (player+clock+P)%P;
		}
	}

	return 0;
}