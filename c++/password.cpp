#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define invrep(i,n) for(int i=n;i--;)
#define rep(i,n) for(int i=0;i<(int)n;++i)
typedef unsigned long long ull;
ull mod[] = {(int)1e9+7, (int)1e9+9};
//largo máximo que puede tener un string
int maxstrlen = 1e6;
 
class RH {
    static vector<ull> x[2];
    vector<ull> h[2];
    string str;
    int n;
 
    //private: usar el método público para obtener el hash
    ull hash(int a, int start, int len) {
        ull ans = 0, end = start + len;
        //descomentar si se consideran substrings cíclicos
        //if (end > n) {end -= n; ans = h[a][0]*x[a][n-start] %mod[a];}
        ans += h[a][start] - h[a][end]*x[a][len] %mod[a] + mod[a];
        return ans %mod[a];
    }
 
public: RH() {}
    //str: string del cual se producen substrings a hashear
    RH(const string &str) { // complejidad: O(n)
        this->str = str;
        n = str.size();
        if (x[0].empty()) rep(a, 2) {
            x[a].assign(maxstrlen+1, 1);
            rep(i, maxstrlen) x[a][i+1] = x[a][i]*127 %mod[a];
        }
        rep(a, 2) {
            h[a].assign(n+1, 0);
            invrep(i, n) h[a][i] = (h[a][i+1]*127 + str[i]) %mod[a];
        }
    }
 
    //obtiene el hash de un substring que comienza en el índice “start”
    //y tiene largo “len”.
    ull hash(int start, int len) { // complejidad: O(1)
        //cout<<"caca\n";
        return hash(0, start, len) << 32 | hash(1, start, len);
    }
 
    //si se usan, insertar aquí los métodos opcionales 1 o 2.
};
//esta línea es importante para que el código compile
vector<ull> RH::x[2];
 
 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    RH rh(s);
    int lastmatch = -1;
    int ans = -1;
    for(int i = s.size()-1; i >=0  ; i--){
        //cout<<i<<" "<<s.size()-i<<"\n";
        //cout<<s.substr(0,i)<<" "<<s.substr(s.size()-i,i)<<"\n";
        if(rh.hash(0,i)==rh.hash(s.size()-i,i)){
            for(int j = 1; j < s.size() - i ; j++){
                //cout<<i<<" "<<j<<"\n";
                if(rh.hash(j,i)==rh.hash(0,i)){
                    ans = i;
                    i = -1;
                    //cout<<"asdasd\n"<<" "<<ans;
                    break;
                }
            }
        }
    }
    if(ans==0 || s.size()==1)
        cout<<"Just a legend\n";
    else
        cout<<s.substr(0,ans)<<"\n";
    //cout<<lastmatch<<"\n";
    //cout<<ans<<"\n";
    //cout<<s.size()<<"\n";
    return 0;
 }