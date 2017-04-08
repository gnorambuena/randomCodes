#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;
const ull z = 127, MOD = 1e9+7;
ull Z[1000001];

struct RH
{
	ull H[1001];

	RH(string &S)
	{
		int N = S.size();
		H[N] = 0;
		for(int i = N-1; i >= 0; --i)
			H[i] = (H[i+1]*z+S[i])%MOD;
	}

	ull Hash(int i, int k)
	{
		return (H[i] + MOD - Z[k]*H[i+k]%MOD)%MOD;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	Z[0] = 1;
	for(int i = 1; i <= 1000000; ++i)
		Z[i] = z*Z[i-1]%MOD;
	int t;
	cin>>t;
	while(t--)
	{
		int N,M; cin >> N >> M;
		vector<RH> R; R.reserve(M);
		for(int i = 0; i < M; ++i)
		{
			string S; cin >> S;
			R.emplace_back(S);
		}

		ull myHash = 0;
		int X,Y; cin >> X >> Y;
		for(int i = 0; i < X; ++i)
		{
			string S; cin >> S;
			for(int j = 0; j < Y; ++j)
				myHash = (myHash + Z[i*Y+j]*S[j]%MOD)%MOD;
		}

		int ans = 0;
		for(int j = 0; j+Y-1 < M; ++j)
		{
			ull auxHash = 0;
			for(int i = N-X, k = 0; i < N; ++i, ++k)
				auxHash = (auxHash + Z[k*Y]*R[i].Hash(j,Y)%MOD)%MOD;

			if(auxHash == myHash)
				ans++;

			for(int i = N-X-1; i >= 0; --i)
			{
				auxHash = (auxHash + MOD - Z[(X-1)*Y]*R[i+X].Hash(j,Y)%MOD)%MOD;
				auxHash = auxHash*Z[Y]%MOD;
				auxHash = (auxHash + R[i].Hash(j,Y))%MOD;

				if(auxHash == myHash)
					ans++;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}