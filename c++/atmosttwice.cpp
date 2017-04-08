#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool check(vector<int>&c){
	for(int i = 0 ; i < c.size() ; i++){
		if(c[i]>2) return false;
	}
	return true;
}
int main(){
	long long u;
	while(cin>>u){
		vector<int>digits;
		vector<int>c(10,0);
		while(u){
			int ans = u%10;
			u/=10;
			digits.push_back(ans);
			c[ans]++;
		}
		int index = 0;
		for(int i = 0 ; i < digits.size() ; i++){
			
			if(check(c) && digits[i] == 0){
				continue;
			}

			while(digits[i] != 0){
				c[digits[i]]--;
				digits[i]--;
				c[digits[i]]++;

				if(check(c)){
					break;
				}

			}
			
			if(check(c) && digits[i] != 0){
				index = i;
				break;
			}else{
				c[digits[i]]--;
			}
		}
		int n = digits.size();
		cout << "index: " << index << endl;
		cout << "Rindex: " << n - 1 - index << endl;
		int v = 9;
		reverse(digits.begin(),digits.end());
		bool prim = true;
		for(int i = 0 ; i < digits.size() ; i++){
			while(prim && digits[i] == 0 && i <= n - index - 1){
				i++;
			}
			prim = false;
			while(c[v] == 2){
				v--;
			}
			if(i > n - 1 - index) c[v]++;
			cout<<(i <= n - index - 1 ? digits[i] : v);
		}
	}
	return 0;
}