#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	while(cin >> n)
	{
		vector<string> P;
		map<string,int> R;

		for(int i = 0; i < n; ++i)
		{
			stringstream ss;
			ss << getline(cin);
			string word; ss >> word;
			if(!R.count(word))
			{
				R[word] = P.size();
				P.pb(word);
			}
			int i = R[word];
			while(ss >> word)
			{
				if(!R.count(word))
				{
					R[word] = P.size();
					P.pb(word);
				}

			}
		}
	}

	return 0;
}