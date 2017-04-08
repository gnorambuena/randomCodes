#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string time; cin >> time;
	int hour = 10*(time[0]-'0')+time[1]-'0';
	int minute = 10*(time[3]-'0')+time[4]-'0';
	int a; cin >> a;
	hour = (hour + (a+minute)/60)%24;
	minute = (minute + a%60)%60;
	cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 : "0" : "") << minute;
	return 0;
}