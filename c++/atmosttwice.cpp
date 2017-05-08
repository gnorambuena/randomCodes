#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main(){
  string s;
  cin >> s;

  vector<vector<int> > cant(20, vector<int>(15, 0));

  for (int i = 0; i < s.size(); i++){
    for(int j = i; j < s.size(); j++){
      cant[j][s[i] - '0']++;
    }
  }

//cout << "print1" << endl;

  int i = 0;
  int cond = 0;

  for (i = 0; i < s.size(); i++){
    //cout << "el i actual es " << i << endl;
    while (cant[i][s[i] - '0'] > 2 && s[i] >= '0'){
      for (int j = i; j < s.size(); j++) cant[j][s[i] - '0']--;
      s[i]--;
      if (s[i] >= '0')
        for (int j = i; j < s.size(); j++) cant[j][s[i] - '0']++;
      if (s[i] >= '0' && cant[i][s[i] - '0'] < 2){
        cond = 1;
      }
    }
    while (s[i] < '0'){
      //cout << s[i];
      i--;
      s[i]--;
      if (s[i] >= '0' && cant[i][s[i] - '0'] < 2){
        cond = 1;
        break;
      }
    }
    if (cond) break;
    if (cant[i][s[i] - '0'] <= 2 && s[i] - '0' >= 0){
      continue;
    }
  }

  //cout << "hola" << endl;
  //cout << i << endl;
  //cout << s << endl;

  for (int j = i + 1; j < s.size(); j++){
    //cout << s << endl;
    for (int h = 9; h >= 0; h--){
      if ( (cant[j][h] < 2 && s[j] - '0' != h) || (cant[j][h] < 3 && s[j] - '0' == h)){
        for (int k = j; k < s.size(); k++) cant[k][h]++;
        s[j] = '0' + h;
        break;
      }
    }
  }

  string s2 = "";

  if(s[0] == '0'){
    for (int i = 1; i < s.size(); i++)
      s2 += s[i];
  }
  else{
    s2 = s;
  }
  cout << s2 << endl;

  return 0;
}
