#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int A[3];
	while(cin >> A[0] >> A[1] >> A[2])
	{
		sort(A,A+3);
		if(A[0] == A[1] || A[1] == A[2] || A[0] + A[1] == A[2])
			cout << "S\n";
		else
			cout << "N\n";
	}
	return 0;
}