#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N)
    {
    	vector<int>prices(N);
    	for(int &a:prices)cin>>a;

        sort(prices.begin(),prices.end());
        
        cin >> M;
        
        int i = 0, j = N - 1;
        int opt1, opt2;
        while (i < j)
        {
            if(prices[i] + prices[j] < M)i++;
            else if (prices[i] + prices[j] == M)
            {
                opt1 = i;
                opt2 = j;
                i++; j--;
            }
            else
                j--;
        }
        
        cout << "Peter should buy books whose prices are " << prices[opt1] << " and " << prices[opt2] << ".\n\n";
    }
}