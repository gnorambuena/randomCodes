#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll balloons[3];
	cin >> balloons[0] >> balloons[1] >> balloons[2];
	sort(balloons,balloons+3);
	if(2*(ballons[0] + balloons[1]) <= balloons[2])
		cout << balloons[0] + balloons[1];
	else
		cout << (balloons[0] + balloons[1] + balloons[2])/3;
	return 0;
}