#include <bits/stdc++.h>
using namespace std;

bool error = false;
struct PairTree
{
	*PairTree izq = NULL, der = NULL;

	PairTree()
	{
		string s; 
		if(cin >> s)
			if(s == "pair")
			{
				izq = new PairTree();
				der = new PairTree();
			}
		else
			error = true;
	}
}

ostream& operator<<(ostream& out, PairTree& P)
{
	if(P.izq != NULL)
		out << "pair<" << *P.izq << ',' << *P.der << '>';
	else
		out << "int";
	return out;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	PairTree P();
	if(error)
	{
		cout << "Error occurred";
		return 0;
	}
	string s;
	if(cin >> s)
	{
		cout << "Error occurred";
		return 0;
	}
	cout << P;
	return 0;
}