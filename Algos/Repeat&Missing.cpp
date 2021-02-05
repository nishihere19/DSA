#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i, a[n],b[n+1];
    for(i=0;i<n+1;i++){
        b[i]=0;
    }
    for(i=0;i<n;i++){
        cin>>a[i];
        if(b[a[i]]==0) b[a[i]]=-1;
        else cout<<"Repeated element: "<<a[i]<<endl;
    }
    for(i=0;i<n+1;i++){
        if(b[i]!=-1&&i!=0) cout<<"Missing: "<<i<<endl;
    }
    
    return 0;
}