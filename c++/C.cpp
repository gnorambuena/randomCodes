#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,vector<ll>> state;

ll d;
void mySwap(priority_queue<state,vector<state>,greater<state>> &pq, vector<ll> &V, int i, int j)
{
	swap(V[i],V[j]);
	pq.emplace(d+V[i]+V[j],V);
	swap(V[i],V[j]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ll> V(8);
	while(cin >> V[0])
	{
		for(int i = 1; i < 8; ++i)
			cin >> V[i];

		vector<ll> goal(8); for(ll &g : goal) cin >> g;

		priority_queue<state,vector<state>,greater<state>> pq;
		set<vector<ll>> S;
		pq.emplace(0LL,V);

		d = 0;
		while(!pq.empty())
		{
			d = pq.top().first;
			vector<ll> T = pq.top().second;
			pq.pop();

			if(T == goal)
				break;

			if(S.count(T))
				continue;

			S.insert(T);

			mySwap(pq,T,0,4);
			mySwap(pq,T,0,1);
			mySwap(pq,T,1,2);
			mySwap(pq,T,2,3);
			
			mySwap(pq,T,4,5);
			mySwap(pq,T,5,6);
			mySwap(pq,T,6,7);
			mySwap(pq,T,3,7);
			
			mySwap(pq,T,2,6);
			mySwap(pq,T,1,5);
		}

		cout << d << '\n';
	}

	return 0;
}