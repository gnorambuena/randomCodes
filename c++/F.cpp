#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#define SORT(X,Y,Z,W) thread t1(internal_sort,X);thread t2(internal_sort,Y);thread t3(internal_sort,Z);thread t4(internal_sort,W);t1.join();t2.join();t3.join();t4.join()

using namespace std;
vector<int> S,M,D,B;
long long res = 0;
void internal_sort(vector<int> A){
	sort(A.begin(),A.end());
}
void DP(int L,int cur, bool takenS, int index_S,int stop_s, bool takenM, int index_M, bool takenD, int index_D, bool takenB, int index_B){
	if(cur>L) return ;
	if(index_S>=stop_s)return;
	if(!takenS){
		DP(L,cur+S[index_S],true,index_S,stop_s,takenM,index_M,takenD,index_D,takenB,index_B);
		if(index_S+1 < S.size()){
			DP(L,cur,false,index_S+1,stop_s,takenM,index_M,takenD,index_D,takenB,index_B);
			}
		}
	else if(!takenM){
		DP(L,cur+M[index_M],takenS,index_S,stop_s,true,index_M,takenD,index_D,takenB,index_B);
		if(index_M+1 < M.size()){
			DP(L,cur,takenS,index_S,stop_s,false,index_M+1,takenD,index_D,takenB,index_B);
			}
		}
	else if(!takenD){
		DP(L,cur+D[index_D],takenS,index_S,stop_s,takenM,index_M,true,index_D,takenB,index_B);
		if(index_D+1 < D.size()){
			DP(L,cur,takenS,index_S,stop_s,takenM,index_M,false,index_D+1,takenB,index_B);
		}
	}
	else if(!takenB){
		DP(L,cur+B[index_B],takenS,index_S,stop_s,takenM,index_M,takenD,index_D,true,index_B);
		if(index_B+1 < B.size()){
			DP(L,cur,takenS,index_S,stop_s,takenM,index_M,takenD,index_D,false,index_B+1);
			}
		}
	if(takenS && takenM && takenD && takenB){
		res++;
	}
	return;
	} 

int main(){
	int l,s,m,d,b;
	cin>>l>>s>>m>>d>>b;
	S.resize(s); M.resize(m); D.resize(d); B.resize(b);
	while(l!=0 && s!=0 && m !=0 && d!=0 && b!=0){
		for(int i = 0 ; i < s ; i++){
			cin>>S[i];
		}
		for(int i = 0 ; i < m ; i++){
			cin>>M[i];
		}
		for(int i = 0 ; i < d ; i++){
			cin>>D[i];
		}
		for(int i = 0 ; i < b ; i++){
			cin>>B[i];
		}
		SORT(S,M,D,B);
		thread t5(DP,l,0,false,0,s/4,false,0,false,0,false,0);
		thread t6(DP,l,0,false,s/4,s/2,false,0,false,0,false,0);
		thread t7(DP,l,0,false,s/2,s*3/4,false,0,false,0,false,0);
		thread t8(DP,l,0,false,s*3/4,s,false,0,false,0,false,0);
		t5.join();t6.join();t7.join();t8.join();
		cout<<res<<endl;
		res = 0;
		S.clear();M.clear();D.clear();B.clear();
		cin>>l>>s>>m>>d>>b;
		S.resize(s); M.resize(m); D.resize(d); B.resize(b);
	}
	return 0;
	}
