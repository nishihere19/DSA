#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,n;
    unordered_set<int>myset;
    cin>>n;
    int a[n];
    vector<int>b;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(myset.find(a[i])!=myset.end()) b.push_back(a[i]);
        else myset.insert(a[i]);
    }
 
    for(i=0;i<b.size();i++){
        cout<<b[i]<<endl;
    }
    

    return 0;
}