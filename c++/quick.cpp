#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

queue<pii> Q;
void quicksort(vector<int> &V, int i, int j)
{
	if(i >= j)
		return;
	int index = i;
	for(int k = i; k < j; ++k)
		if(V[k] <= V[j])
		{	
			if(index != k)
			{
				swap(V[index],V[k]);
				Q.emplace(index,k);
			}
			index++;
		}
	if(index != j)
	{
		swap(V[index],V[j]);
		Q.emplace(index,j);
	}
			
	quicksort(V,i,index-1);
	quicksort(V,index+1,j);
}

int main()
{
	vector<int> test {4,7,8,3,2,1,9};
	quicksort(test,0,test.size()-1);
	for(int t : test) cout << t << ' ';
	cout << endl << endl;
	while(!Q.empty())
	{
		cout << Q.front().first << ' ' << Q.front().second << '\n';
		Q.pop();
	}
	return 0;
}