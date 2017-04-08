#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > allsol;
vector<int>n;
void backtracking(){
	for(int i = 0 ; i < n.size() ; i++)
	{
		vector<int>par;
		par.push_back(n[i]);
		for(int j = i+1 ; j < n.size() ; j++)
		{
			par.push_back(n[j]);
			for(int k = j+1 ; k < n.size() ; k++)
			{
				par.push_back(n[k]);
				for(int l = k+1 ; l < n.size() ; l++)
				{
					par.push_back(n[l]);
					for(int m = l+1 ; m <  n.size() ; m++)
					{
						par.push_back(n[m]);
						for(int o = m+1 ; o < n.size() ; o++){
							par.push_back(n[o]);
							allsol.push_back(par);
							par.pop_back();
						}
						par.pop_back();
					}
					par.pop_back();
				}
				par.pop_back();
			}
			par.pop_back();
		}
		par.pop_back();
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int k;
	bool flag = false;
	while(cin>>k && k!=0){
		if(flag)cout<<"\n";
		n.assign(k,0);
		allsol.clear();
		for(int &a : n)cin>>a;
		backtracking();
		for(int i = 0 ; i < allsol.size() ; i++){
			vector<int>vi = allsol[i];
			for(int j = 0 ; j < vi.size() ; j++){
				cout<<vi[j];
				if(j+1!=vi.size())cout<<" ";
			}
			cout<<"\n";
		}
		flag = true;
	}	
	return 0;
}
