#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int sumOfElements(vector<int>&arr){
    int sum = 0;
    for(int a:arr)
        sum+=a;
    return sum;
}

void minimalUnique(vector<int>&arr){
    vector<bool>unique(10000,false);
    vector<int>notUnique;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0 ; i < arr.size(); i++){
        if(unique[arr[i]]){
            notUnique.push_back(i);
        } else {
            unique[arr[i]]=true;
        }
    }
    for(int i = 0 ; i < 10000 ; i++){
        if(!unique[i]){
            pq.push(i);
        }
    }

    for(int i = 0 ; i < notUnique.size() ; i++){
        int t;
        while((t = pq.top()) < arr[notUnique[i]])pq.pop();
        pq.pop();
        arr[notUnique[i]]= t;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    minimalUnique(arr);
    cout<<sumOfElements(arr)<<"\n";
    return 0;
}

