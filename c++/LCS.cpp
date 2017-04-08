#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#define NEG_INF -100000000
#define p 193
#define mod 1000000007
using namespace std;

long long pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result;}
        value = value*value;
        value = value;
        power /= 2;
        //power >>= 1;
    }
    return result;
}
unsigned long long hashf(string s, int i ,int j){
    unsigned long long res = 0;
    for(int k = 0; k < (j-i+1);k++){
        res+=s[i+k]*pow(p,k)%mod;
    }
    return res;
}
int RabinKarp(string s,string pattern){
    unsigned long long hpattern = hashf(pattern,0,pattern.size()-1);
    cerr<<hpattern<<endl;
    unsigned long long hs = hashf(s,0,s.size()-1);
    cerr<<hs<<endl;
    int n = s.size();
    int m = pattern.size();
    for(int i = 0 ; i < n-m+1 ; i++)
    {
        //cerr<<i<<endl;
        if(hs==hpattern)
        {
            if(s.substr(i,(n-i))==pattern)return i;
        }
        hs=hashf(s.substr(i,(n-i)),i,n-i);
    }
    return -1;
}

string lcs(string str1,string str2){
    int m=str1.length();
    int n=str2.length();
    vector<vector<int> >DP(m+1,vector<int>(n+1,0));
    int maxLen=NEG_INF,suffixEnd=-1;
    for(int i = 1;i<m+1;i++){
        for(int j = 1 ; j<n+1;j++){
            if(str1[i-1]==str2[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
                if(DP[i][j]>maxLen){
                    maxLen=DP[i][j];
                    suffixEnd=i;
                }
            }
            else{
                DP[i][j]=0;
            }
        }
    }
    return str1.substr(suffixEnd-maxLen,maxLen);
}

int main() {
  //char A[20] = "ACAATCC", B[20] = "AGCATGC";
  //int n = (int)strlen(A), m = (int)strlen(B);
  //int i, j, table[20][20]; // Needleman Wunsnch's algorithm
    cin.tie(0);ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    string text="Sanfoundry Linux Training";
    string pat="nux";
    cout<<RabinKarp(text,pat)<<endl;
    /*while(t--){
        vector<string>words;
        int k;
        cin>>k;
        for(int i = 0; i < k ; i++){
            string s;
            cin>>s;
            words.push_back(s);
        }
        string s1=words[0];
        for(int i = 1 ; i < k;i++){
            string s2=words[i];
            s1=lcs(s1,s2);
        }
    cout<<s1.lenght(<<"\n";
    }*/
  return 0;
}
